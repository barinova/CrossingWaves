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
    float verticalAsummetry;
    float horizontalAsymmetry;
    float nullPoint[3];
};

class CCrossingWave
{
public:
    //CCrossingWave();
    //std::list<waveParametres> listParametres;
    std::map<int, waveParametres> parametres;
    std::map<int, waveEntity> calculatingWaves;
    CCrossingWave();
    bool ReadingFile(std::string pathToFile);
    bool CalculatingWaves();

private:
    void DataToTable(std::string sec, std::string shift);
    waveEntity GetSingleWave(int i, typeCrossing type, int parametresSize);
    float getNullPoint(waveParametres fistPoint, waveParametres secondPoint);
    void amplMin(waveParametres point, waveEntity &wave);
    void amplMax(waveParametres point, waveEntity &wave);
};

#endif // CCROSSINGWAVE_H
