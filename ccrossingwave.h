#ifndef CCROSSINGWAVE_H
#define CCROSSINGWAVE_H

#include <map>
#include <string>
#include <cstdlib>
#include <math.h>

enum typeCrossing { ZDC, ZUC};

struct waveParametres
{
    float sec;
    float shift;
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

class CCrossingWave
{
public:
    //CCrossingWave();
    //std::list<waveParametres> listParametres;
    std::map<int, waveParametres> parametres;
    std::map<int, waveEntity> calculatingWaves;
    CCrossingWave();
    bool readingFile(std::string pathToFile);
    bool calculateWaves();

private:
    void dataToTable(std::string sec, std::string shift);
    waveEntity getSingleWave(int i, typeCrossing type, int parametresSize);
    float getNullPoint(waveParametres fistPoint, waveParametres secondPoint);
    void amplMin(waveParametres point, waveEntity &wave);
    void amplMax(waveParametres point, waveEntity &wave);
};

#endif // CCROSSINGWAVE_H
