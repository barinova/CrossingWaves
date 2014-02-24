#include "cloadfile.h"


CLoadFile::CLoadFile()
{
}

std::map<int, waveParametres> CLoadFile::loadFile(std::string pathToFile)
{
    std::ifstream fileName(pathToFile.c_str());
    std::string sec, shift, line;
    std::map<int, waveParametres> parametres;
    waveParametres param;
    //create new starting func
    while(getline(fileName, line))
    {
        std::stringstream   linestream(line);
        getline(linestream, sec, '\t');
        getline(linestream, shift, '\n');
        param.sec = ::atof(sec.c_str());
        param.shift = ::atof(shift.c_str());
        parametres.insert(std::make_pair(parametres.size(), param));;
    }
    return parametres;
}

