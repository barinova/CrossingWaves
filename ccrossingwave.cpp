#include "ccrossingwave.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstddef>

CCrossingWave::CCrossingWave()
{
}

bool CCrossingWave::ReadingFile(std::string pathToFile)
{
    std::ifstream fileName(pathToFile.c_str());
    std::string sec, shift, line;
    while(getline(fileName, line))
    {
        std::stringstream   linestream(line);
        getline(linestream, sec, '\t');
        getline(linestream, shift, '\n');
        DataToTable(sec, shift);
    }
    if(!(sec.empty() && shift.empty()))
        return true;
    else
        return false;
}


void CCrossingWave::DataToTable(std::string sec, std::string shift)
{
    waveParametres param;
    param.sec = ::atof(sec.c_str());
    param.shift = ::atof(shift.c_str());
    parametres.insert(std::make_pair(parametres.size(), param));
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
    }
}

void CCrossingWave::amplMin(waveParametres point, waveEntity &wave)
{
    if(point.shift < wave.amplMin)
    {
        wave.amplMin = point.shift;
    }
}

waveEntity CCrossingWave::GetSingleWave(int i, typeCrossing type, int parametresSize)
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

    return wave;
}


bool CCrossingWave::CalculatingWaves()
{
    int parametresSize = parametres.size();
    waveParametres first, second;
    waveEntity newWave;
    for(int i(0); i < parametresSize; i++)
    //for (std::list<waveParametres>::iterator it = wave->listParametres.begin(); it != wave->listParametres.end(); it++)
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
            newWave = GetSingleWave(i, type, parametresSize - 1);
            if(newWave.totalHeight == NULL)
                   return true;
            calculatingWaves.insert(std::make_pair(calculatingWaves.size(), newWave));
        }
    }
    return true;
}
