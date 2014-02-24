#ifndef CCROSSINGWAVE_H
#define CCROSSINGWAVE_H

#include <string>
//#include <cstdlib>
#include <math.h>
#include <QList>
#include "cloadfile.h"

enum typeCrossing { ZDC, ZUC};


struct probability
{
    float H;
    float experP;
    float teorP;
    float crestP;
    float troughP;
};

struct waveEntity
{
    typeCrossing type;
    float amplMax;
    float amplMin;
    float totalHeight;
    float sec;
    float verticalAsummetry;
    float horizontalAsymmetry;
    float nullPoint[3];
    float trough;
    float ridge;
};

struct heights
{
    typeCrossing type;
    float significantHeight;
    float heightOneThird;
    float sigma;
};

class CCrossingWave
{
public:
    QList<float> listHeihtsZDC;
    QList<float> listHeihtsZUC;
    QList<float> listCrestAZDC;
    QList<float> listCrestAZUC;
    QList<float> listThroughAZDC;
    QList<float> listThroughAZUC;
    QList<probability> listProbabilitiesZDC;
    QList<probability> listProbabilitiesZUC;
    std::map<int, waveParametres> parametres;
    std::map<int, waveEntity> calculatingWaves;
    QList<heights> h;
    CCrossingWave();
    bool readingFile(std::string pathToFile);
    bool calculateWaves();
    void setProbabilities();
    void clearAll();

private:
    void dataToTable(std::string sec, std::string shift);
    waveEntity getSingleWave(int i, typeCrossing type, int parametresSize);
    float getNullPoint(waveParametres fistPoint, waveParametres secondPoint);
    void amplMin(waveParametres point, waveEntity &wave);
    void amplMax(waveParametres point, waveEntity &wave);
    float significantHeights(QList<float> listHeights);
    float heightOneThird(QList<float> listHeights);
    float setSigma(QList<float> listHeights, float sighificiantHeight);
    void setHeights();
    void setListProbabilities(QList<float> listHeights, QList<float>listCrestA,
                              QList<float> ListThroughA, typeCrossing type);
};

#endif // CCROSSINGWAVE_H
