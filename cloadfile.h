#ifndef CLOADFILE_H
#define CLOADFILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <map>
#include <cstdlib>

struct waveParametres
{
    float sec;
    float shift;
};

class CLoadFile
{
public:
    CLoadFile();
    std::map<int, waveParametres> loadFile(std::string str);
};

#endif // CLOADINGFILE_H
