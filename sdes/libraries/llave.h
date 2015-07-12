#ifndef LLAVE_H
#define LLAVE_H

#include "byte.h"
/***************************************************************************************

	KeySchedule
			Tipo de dato Key que almacena las dos subllaves

****************************************************************************************/
typedef struct{
	int k1;
	int k2;
}Key;

int validaLlave(const char *llave);

int P10(int llave);

int P8(int llave);

Key keyschedule(int key);

#endif