#ifndef CLOADFILE_H
#define CLOADFILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <map>
#include <cstdlib>
#include <qlist.h>
#include "ReadMatFile.h"

struct waveParametres
{
    float sec;
    float shift;
};

class CLoadFile
{
public:
	QList<double> listT;
	QList<double> listX;
	QList<QList<double>> listS;
    CLoadFile();
    std::map<int, waveParametres> loadDatFile(std::string str);
	std::map<int, waveParametres> loadMatFile(std::string str);
};

#endif // CLOADINGFILE_H
