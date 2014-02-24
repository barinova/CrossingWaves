#include "ccrossingwave.h"


CCrossingWave::CCrossingWave()
{
}

void CCrossingWave::clearAll()
{
    this->calculatingWaves.clear();
    this->h.clear();
    this->listHeihtsZDC.clear();
    this->listHeihtsZUC.clear();
    this->listCrestAZDC.clear();
    this->listCrestAZUC.clear();
    this->listThroughAZDC.clear();
    this->listThroughAZUC.clear();
    this->listProbabilitiesZDC.clear();
    this->listProbabilitiesZUC.clear();
    this->parametres.clear();
}

bool CCrossingWave::readingFile(std::string pathToFile)
{
    CLoadFile *file = new CLoadFile();
    parametres = file->loadFile(pathToFile);
    return (parametres.size() > 0 ? true : false);
}


float CCrossingWave::getNullPoint(waveParametres firstPoint, waveParametres secondPoint)
{
    return ((secondPoint.sec * firstPoint.shift - firstPoint.sec * secondPoint.shift)/(firstPoint.shift - secondPoint.shift));
}

void CCrossingWave::amplMax(waveParametres point, waveEntity &wave)
{
    if(point.shift > wave.amplMax)
    {
        wave.amplMax = point.shift;
        wave.ridge = point.sec;
    }
}

void CCrossingWave::amplMin(waveParametres point, waveEntity &wave)
{
    if(point.shift < wave.amplMin)
    {
        wave.amplMin = point.shift;
        wave.trough = point.sec;
    }
}

waveEntity CCrossingWave::getSingleWave(int i, typeCrossing type, int parametresSize)
{
    int k = 0;
    waveParametres currentPoint;
    waveEntity wave;
    wave.type = type;
    //if(parametres.at(i - 1))  !!!!!!!!!!!!!!
    wave.nullPoint[k] = getNullPoint(parametres.at(i), parametres.at(i + 1));
    wave.amplMax = 0;
    wave.amplMin = 0;
    currentPoint.sec = wave.nullPoint[k++];
    currentPoint.shift = 0;

    while(k < 3)
    {
        amplMax(currentPoint, wave);
        amplMin(currentPoint, wave);
        // if i+1 not found !!!!!
        if( i < parametres.size() && (currentPoint.shift * ((waveParametres)parametres.at(i + 1)).shift < 0))
        {
            wave.nullPoint[k++] = getNullPoint(currentPoint, parametres.at(i + 1));
        }
        if(++i >= parametresSize && k != 3)
            return waveEntity();
        currentPoint =  parametres.at(i);
    }

    wave.verticalAsummetry = fabs(wave.amplMax / wave.amplMin);
    wave.horizontalAsymmetry = (wave.nullPoint[1] - wave.nullPoint[0])/ (wave.nullPoint[2] - wave.nullPoint[1]);
    wave.totalHeight = fabs(wave.amplMax) + fabs(wave.amplMin);

    if(wave.type == ZDC)
    {
        //in new func
        listHeihtsZDC.append(wave.totalHeight);
        listCrestAZDC.append(wave.amplMax);
        listThroughAZDC.append( - wave.amplMin);
    }
    else
    {
        //in new func
        listHeihtsZUC.append(wave.totalHeight);
        listCrestAZUC.append(wave.amplMax);
        listThroughAZUC.append( - wave.amplMin);
    }
    return wave;
}

float CCrossingWave::heightOneThird(QList<float> listHeights)
{
    int size;
    float heightSignificant;
    size = 2 * (listHeights.count()/3);
    float tmp = listHeights.count() - size;
    qSort(listHeights.begin(), listHeights.end());
    for(int i(size); i < listHeights.count(); i++)
    {
        heightSignificant += listHeights.at(i);
    }
    return (heightSignificant/(listHeights.count() - size));
}

float CCrossingWave::significantHeights(QList<float> listHeights)
{
    //wtf
    float tmp = listHeights.count();
    float heightSignificant;
    for(int i(0); i < listHeights.count(); i++)
    {
        heightSignificant += listHeights.at(i);
    }

    tmp = heightSignificant/listHeights.count();
    return sqrt(4.04*heightSignificant/listHeights.count());
}

float CCrossingWave::setSigma(QList<float> listHeights, float sighificiantHeight)
{
    //float tmp = listHeights.count();
    float sigma;
    //if sign heights != 0
    for(int i(0); i < listHeights.count(); i++)
    {
        sigma += sqrt(pow(listHeights.at(i) - sighificiantHeight, 2));
    }
    return (sigma/listHeights.count());
}

void CCrossingWave::setHeights()
{
    heights zuc, zdc;
    zdc.type = ZDC;
    zdc.significantHeight = significantHeights(listHeihtsZDC);
    zdc.heightOneThird = heightOneThird(listHeihtsZDC);
    zdc.sigma = setSigma(listHeihtsZDC, zdc.heightOneThird);
    h.append(zdc);

    zuc.type = ZUC;
    zuc.significantHeight = significantHeights(listHeihtsZUC);
    zuc.heightOneThird = heightOneThird(listHeihtsZUC);
    zuc.sigma = setSigma(listHeihtsZUC, zuc.heightOneThird);
    h.append(zuc);
}

bool CCrossingWave::calculateWaves()
{
    int parametresSize = parametres.size();
    waveParametres first, second;
    waveEntity newWave;
    for(int i(0); i < parametresSize; i++)
   {
        first = parametres.at(i);
        second = parametres.at(i+1);
        if(first.shift * second.shift < 0)
        {
            //FOR NULL!!!!!
            typeCrossing type;
            if(first.shift > 0)
            {
                type = ZDC;
            }
            else
            {
                type = ZUC;
            }
            newWave = getSingleWave(i, type, parametresSize - 1);
            if(newWave.totalHeight == NULL)
            {
                setHeights();
                return true;
            }
            calculatingWaves.insert(std::make_pair(calculatingWaves.size(), newWave));
        }
    }
    return true;
}

void CCrossingWave::setProbabilities()
{
    this->setListProbabilities(listHeihtsZDC, listCrestAZDC, listThroughAZDC, ZDC);
    this->setListProbabilities(listHeihtsZUC, listCrestAZUC, listThroughAZUC, ZUC);
}

void CCrossingWave::setListProbabilities(QList<float> listHeights, QList<float> listCrestA,
                                         QList<float> listThroughA, typeCrossing type)
{
    probability obj;
    float N, waveFrequency, signH;
    N = listHeights.size();
    qSort(listHeights.begin(), listHeights.end());
    qSort(listCrestA.begin(), listCrestA.end());
    qSort(listThroughA.begin(), listThroughA.end());
    qDebug("Pteor exp(-H^2/(8*Hsign^2))\n", obj.teorP, obj.H, h.at(type).significantHeight);
    //qDebug("P  i/N");
    for(int i(0); i < listHeights.size(); i++)
    {
        signH = pow(h.at(type).significantHeight,2);
        waveFrequency = (N-i)/N;
        obj.H = listHeights.at(i);
        obj.experP = waveFrequency;
        //obj.teorP = exp(-obj.H * obj.H/(8*h.at(type).sigma * h.at(type).sigma));
        obj.crestP = exp(-pow(2 * listCrestA.at(i), 2)/(2 * h.at(type).sigma * h.at(type).sigma));
        obj.troughP = exp(-pow(2 * listThroughA.at(i), 2)/(2 *h.at(type).sigma * h.at(type).sigma));
        obj.teorP = exp(-obj.H * obj.H/(2*h.at(type).sigma * h.at(type).sigma));
        if(type == ZDC)
        {

            //qDebug("%f %f/%f\n",waveFrequency, floor(N-i),floor(N));
            qDebug("%f exp(-%f^2/(8*%f^2))\n", obj.teorP, obj.H, h.at(type).significantHeight);
            listProbabilitiesZDC.append(obj);
        }
        else
        {
            listProbabilitiesZUC.append(obj);
        }
    }
}
