#include "cloadfile.h"


CLoadFile::CLoadFile()
{
}

std::map<int, waveParametres> CLoadFile::loadDatFile(std::string pathToFile)
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
        parametres.insert(std::make_pair(parametres.size(), param));
    }
    return parametres;
}

std::map<int, waveParametres> CLoadFile::loadMatFile(std::string pathToFile)
{
	std::map<int, waveParametres> parametres;
	waveParametres param;

	CReadMatFile *matFile = new CReadMatFile(pathToFile.c_str());
	if (!matFile->t.isEmpty() && !matFile->s.isEmpty() && !matFile->x.isEmpty())
	{
		for(int i(0); i < 1; i ++)//matFile->numToReadT
		{
			//t - fixed
			for(int j(0); j < matFile->numToReadX; j ++)//matFile->numToReadX; j ++)
			{
				param.sec= matFile->x[j];
				param.shift = matFile->s[i][j];
				parametres.insert(std::make_pair(parametres.size(), param));
			}
		}
	}
	 return parametres;
}