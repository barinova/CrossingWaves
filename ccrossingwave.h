#ifndef CCROSSINGWAVE_H
#define CCROSSINGWAVE_H

#include <map>
#include <string>
#include <cstdlib>
#include <math.h>
#include <QList>

enum typeCrossing { ZDC, ZUC};

struct waveParametres
{
    float sec;
    float shift;
};

struct probability
{
    float H;
    float P;
    float teorP;
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
};

class CCrossingWave
{
public:
    QList<float>listHeihtsZDC;
    QList<float> listHeihtsZUC;
    QList<probability> listProbabilitiesZDC;
    QList<probability> listProbabilitiesZUC;
    std::map<int, waveParametres> parametres;
    std::map<int, waveEntity> calculatingWaves;
    QList<heights> h;
    CCrossingWave();
    bool readingFile(std::string pathToFile);
    bool calculateWaves();
    void setProbabilities();

private:
    void clearAll();
    void dataToTable(std::string sec, std::string shift);
    waveEntity getSingleWave(int i, typeCrossing type, int parametresSize);
    float getNullPoint(waveParametres fistPoint, waveParametres secondPoint);
    void amplMin(waveParametres point, waveEntity &wave);
    void amplMax(waveParametres point, waveEntity &wave);
    float significantHeights(QList<float> listHeights);
    float heightOneThird(QList<float> listHeights);
    void setHeights();
    void setListProbabilities(QList<float> listHeights, typeCrossing type);
};

#endif // CCROSSINGWAVE_H
