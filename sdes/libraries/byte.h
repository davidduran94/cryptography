/***********************************************************


TByte es una estructura de enteros que almacenara 0's y 1's
	y cuenta con un entero auxiliar por si es necesario
	usarlo para hacer ordenamiento por algun metodo7


***********************************************************/

typedef struct{
	int p0;
	int p1;
	int p2;
	int p3;
	int p4;
	int p5;
	int p6;
	int p7;
	int p8;
	int p9;
}TByte;

TByte INTtoB(int b);

int BtoINT(TByte byte);

TByte UStoB(unsigned char b);

unsigned char BtoUS(TByte byte);

void printTByte(char *Tag,TByte B,int n);