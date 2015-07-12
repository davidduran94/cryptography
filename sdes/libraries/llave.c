#include "llave.h"

/*Valida que la llave sea de 10 caracteres y que este en el rango permitido*/
int validaLlave(const char *llave)
{
	int K10=0,i=0;

	while(llave[i]!='\0'){
		if( llave[i]=='0' || llave[i]== '1')
			K10 = (K10 << 1)	+	((llave[i])-'0');
		else
			K10 = -1;
		i++;
	}
	
	return K10;
}

/*Permutacion 8bits LLAVE*/
int P10(int llave)
{
	TByte a,b=INTtoB(llave);
	
	#ifdef SHOWKSCH
			printTByte("\tKEY:",b,10);
	#endif

	/*Permutacion a 10*/
			a.p0=b.p2;
			a.p1=b.p4;
			a.p2=b.p1;
			a.p3=b.p6;
			a.p4=b.p3;
			a.p5=b.p9;
			a.p6=b.p0;
			a.p7=b.p8;
			a.p8=b.p7;
			a.p9=b.p5;

	#ifdef SHOWKSCH
		printTByte("\tP10:",a,10);
	#endif
	return BtoINT(a);

}

int P8(int llave)
{
	TByte a,b=INTtoB(llave);

	#ifdef SHOWKSCH
		printTByte("\t\tRECIEVEDP8:",b,10);
	#endif

			/*Permutacion*/
			a.p2=b.p5;
			a.p3=b.p2;
			a.p4=b.p6;
			a.p5=b.p3;
			a.p6=b.p7;
			a.p7=b.p4;
			a.p8=b.p9;
			a.p9=b.p8;

	#ifdef SHOWKSCH
		printTByte("\t\tPERMUTEDP8:",a,10);
	#endif
		
	return BtoINT(a);

}


Key keyschedule(int key)
{

	Key k;

	#ifdef SHOWKSCH
			printf("KEY SCHEDULE\n");
	#endif

		/*Introducimos la llave por unica vez a una permutacion P10*/		
			k.k1=P10(key);

		/*LS-1 aplicado a mascaras para realizar corrimientos y sumas sin riesgo a un resultado no deseado*/
			k.k1= ((k.k1&0x1E0)<<1 | (k.k1&0x200)>>4) | ( (k.k1&0xF)<<1 | (k.k1&0x10)>>4 );

		/*LS-2 aplicado a mascaras para realizar corrimientos y sumas sin riesgo a un resultado no deseado*/
			k.k2=((k.k1&0xE0)<<2 | (k.k1&0x300)>>3) | ((k.k1&0x7)<<2 | (k.k1&0x18)>>3);

	#ifdef SHOWKSCH
			printTByte("\tLS-1:",INTtoB(k.k1),10);	
	#endif

		/*Aplicamos una mascara a 8 bits a la P8 para garantizar los resultados en este rango*/
		k.k1= P8(k.k1)&0xFF;

	#ifdef SHOWKSCH
		printTByte("\tLS-2:",INTtoB(k.k2),10);
	#endif

		/*Aplicamos una mascara a 8 bits a la P8  para garantizar los resultados en este rango*/
		k.k2= P8(k.k2)&0xFF;

	#ifdef SHOWKSCH
		printTByte("\tSUBKEY1:",UStoB((unsigned char)k.k1),8);
		printTByte("\tSUBKEY2:",UStoB((unsigned char)k.k2),8);
		putchar('\n');putchar('\n');
	#endif


	return k;

}
