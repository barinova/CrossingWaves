#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mat.h"
#include <qlist.h>

#pragma once
class CReadMatFile
{
public:
	QList<double>		t, x;
	QList<QList<double>> s;
	int			numToReadT, numToReadX;
	CReadMatFile(static const char	*file);
	~CReadMatFile(void);
};

