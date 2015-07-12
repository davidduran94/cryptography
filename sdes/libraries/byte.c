#include "byte.h"
/*Entero a TByte para llave*/

TByte INTtoB(int b){
	TByte byte;

	byte.p9=b%2;b=b>>1;
	byte.p8=b%2;b=b>>1;
	byte.p7=b%2;b=b>>1;
	byte.p6=b%2;b=b>>1;
	byte.p5=b%2;b=b>>1;
	byte.p4=b%2;b=b>>1;
	byte.p3=b%2;b=b>>1;
	byte.p2=b%2;b=b>>1;
	byte.p1=b%2;b=b>>1;
	byte.p0=b%2;
	return byte;
}

/*TByte a Entero*/

int BtoINT(TByte byte){
	int B;

	B=((byte.p0)<<9)
	+((byte.p1)<<8)
	+((byte.p2)<<7)
	+((byte.p3)<<6)
	+((byte.p4)<<5)
	+((byte.p5)<<4)
	+((byte.p6)<<3)
	+((byte.p7)<<2)
	+((byte.p8)<<1)
	+(byte.p9);

	return B;

}

/*Unsigned char a TByte*/

TByte UStoB(unsigned char b){
	TByte byte;

	byte.p7=b%2;b=b>>1;
	byte.p6=b%2;b=b>>1;
	byte.p5=b%2;b=b>>1;
	byte.p4=b%2;b=b>>1;
	byte.p3=b%2;b=b>>1;
	byte.p2=b%2;b=b>>1;
	byte.p1=b%2;b=b>>1;
	byte.p0=b%2;
	return byte;
}

/*TByte a Unsigned char*/

unsigned char BtoUS(TByte byte){
	unsigned char B;

	B=((byte.p0)<<7)
	+((byte.p1)<<6)
	+((byte.p2)<<5)
	+((byte.p3)<<4)
	+((byte.p4)<<3)
	+((byte.p5)<<2)
	+((byte.p6)<<1)
	+(byte.p7);

	return B;

}

/*Funcion que imprime el TByte*/

void printTByte(char *Tag,TByte B,int n){

	switch(n){

		case 4:

			printf("%s(%d%d%d%d)\n",Tag,B.p4,B.p5,B.p6,B.p7);
			break;

		case 8:

			printf("%s(%d%d%d%d%d%d%d%d)",Tag,B.p0,B.p1,B.p2,B.p3,B.p4,B.p5,B.p6,B.p7);
				#ifdef CHARSHOW
					printf("  Int:(%d)  Hex:(%2x)  Char:(%c)",BtoUS(B),BtoUS(B),BtoUS(B));
				#endif
			putchar('\n');
			break;

		case 10:

			printf("%s(%d%d%d%d%d%d%d%d%d%d)\n",Tag,B.p0,B.p1,B.p2,B.p3,B.p4,B.p5,B.p6,B.p7,B.p8,B.p9);
			break;

	}	
}