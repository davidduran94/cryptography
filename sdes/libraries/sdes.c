#include "sdes.h"

const unsigned char sbox0[4][4] = { 1, 0, 3, 2,3, 2, 1, 0,0, 2, 1, 3,3, 1, 3, 2		};

const unsigned char sbox1[4][4] = { 0, 1, 2, 3,2, 0, 1, 3,3, 0, 1, 0,2, 1, 0, 3		};
			
/*Permutacion Inicial*/

unsigned char IP(unsigned char B){
	TByte a=UStoB(0),b=UStoB(B);

	#ifdef DEBUG
		printf("\n\tINITIAL PERMUTATION\n");
	#endif

	a.p0=b.p1;
	a.p1=b.p5;
	a.p2=b.p2;
	a.p3=b.p0;
	a.p4=b.p3;
	a.p5=b.p7;
	a.p6=b.p4;
	a.p7=b.p6;
	return BtoUS(a);
}

/*Expansion de llave*/

unsigned char EP(unsigned char B){
	TByte a,b=UStoB(B);

	a.p1=a.p7=b.p4;
	a.p2=a.p4=b.p5;
	a.p3=a.p5=b.p6;
	a.p0=a.p6=b.p7;

	return BtoUS(a);
}


/*Inversa de la Permutacion Inicial*/

unsigned char invIP(unsigned char B){

	TByte a=UStoB(0),b=UStoB(B);

		#ifdef DEBUG
				printf("\n\tINVERSE PERMUTATION\n");
		#endif


	a.p0=b.p3;
	a.p1=b.p0;
	a.p2=b.p2;
	a.p3=b.p4;
	a.p4=b.p6;
	a.p5=b.p1;
	a.p6=b.p7;
	a.p7=b.p5;
	return BtoUS(a);


}

/*Permutacion sobre 4 bits*/

unsigned char P4(unsigned char B){
	TByte a,b=UStoB(B);

	a.p4=b.p5;
	a.p5=b.p7;
	a.p6=b.p6;
	a.p7=b.p4;

	return BtoUS(a)&0x0F;

}


/*Funcion de Complejidad FK*/
unsigned char fk(unsigned char IP,unsigned char k){

		unsigned char B,sres=0;
		int r0,c0,r1,c1,s0,s1;
		TByte b;

				#ifdef DEBUG
					printf("\n\tFK FUNCTION\n");
				#endif

		/*Aplicamos EP a lo recibido por la funcion IP*/
		B=EP(IP);
		
				#ifdef DEBUG
					printTByte("\t\tEP:",UStoB(B),8);
				#endif

		/*Xor con la llave*/
		B=k^B;

				#ifdef DEBUG
					printTByte("\t\tKEY:",UStoB(k),8);
					printTByte("\t\tXOR:",UStoB(B),8);
				#endif


		
		/*pasamos el valor de B al tipo de dato TByte para operar mas facilmente*/

		b=UStoB(B);
		
		/*Basados en el TByte armamos los numeros correspondientes a filas y columnas*/
		r0=b.p0*2 + b.p3;
		c0=b.p1*2 + b.p2;
		r1=b.p4*2 + b.p7;
		c1=b.p5*2 + b.p6;

				#ifdef SBOXINDEX
					printf("\t\tSBOX INDEX(%d,%d):(%d,%d)\n",c0,r0,c1,r1);
				#endif

		/*Sustituimos basados en las Sbox*/
		s0=sbox0[r0][c0];
		s1=sbox1[r1][c1];

				#ifdef SBOXSHOW
					printf("\t\tSBOX (%d):(%d)\n",s0,s1);
				#endif

		/*creamos la palabra de 4 bits*/
		sres=(s0<<2|s1);//s&(unsigned char)0x0F;

				#ifdef DEBUG
					printTByte("\t\tSBOX RESULT:",UStoB(sres),4);
				#endif
		/*Permutamos a 4 bits*/

		sres=P4(sres);
				#ifdef DEBUG
					printTByte("\t\tP4:",UStoB(sres),4);
				#endif

		/*xor con los 4 bits mas significativos de IP*/

		sres=(IP&0xF0)^(sres)<<4;

				#ifdef DEBUG
					printTByte("\t\tXOR:",UStoB(sres>>4),4);
				#endif

		/*Retornamos el valor del XOR anterior como mas significativo con los 4 bits menos significativos de la IP*/

		return sres|(0x0F & IP);/*Nota: usamos la mascara anterior para quitar la parte mas significativa de IP*/


}


unsigned char SW(unsigned char B){
	/*Aplicamos mascaras para que la parte mas 	y menos significativa de 4 bits por bloque 
	sean removidas para despues poder aplicar corrimiento y sumar*/
				#ifdef DEBUG
					printf("\n\tSWITCH FUNCTION\n");
				#endif


	return ((B & 0x0F)<<4) + ((B & 0xF0)>>4);
}


unsigned char SDES(unsigned char m, unsigned char k1 ,unsigned char k2){
		unsigned char c;

			#ifdef DEBUG
				printf("SDES ENCRYPTION/DECRIPTION\n");
				printTByte("\tSIMBOL:",UStoB(m),8);
			#endif

		c=IP(m);

			#ifdef DEBUG
				printTByte("\t\tIP:",UStoB(c),8);
			#endif


		c=fk(c,(unsigned char)k1);

			#ifdef DEBUG
				printTByte("\tFK(1):",UStoB(c),8);
			#endif

		c=SW(c);

			#ifdef DEBUG
				printTByte("\t\tSW:",UStoB(c),8);
			#endif

		c=fk(c,(unsigned char)k2);

			#ifdef DEBUG
				printTByte("\tFK(2):",UStoB(c),8);
			#endif

		c=invIP(c);

			#ifdef DEBUG
				printTByte("\t\tIP-1:",UStoB(c),8);
				putchar('\n');
			#endif

	return c;

}