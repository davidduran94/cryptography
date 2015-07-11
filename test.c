#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "exp.h"
#include "rsa.h"

	/*
	double a = 3, base = 29,res;
	int n=33;
	res = Power(a,base,n);
	printf("Resultado %.2f\n", res);
	*/

	/*
	int p,q,e,d,n,m,c;
	p = 31;
	q = 5;
	e = 7;
	d = 103;
	n = calcN(p,q);
	printf("Hola Repo Crypto\n");
	printf("llave publica k(e,n): (%d,%d)\n",e,n);
	printf("llave privada k(d,n): (%d,%d)\n",d,n);
	*/
	//int t=1311,e=134,n=39979;
	//printf("%d\n",exp(t,e,n));
	/*
	do{
		printf("%d\n",primos[i]);
		i++;
	}while(i<c);
	*/

int main(int argc,char *argv[]){
	int c;
	double p,q,n;
	int *primos;
	primos = (int *) malloc( limite/2 );
	//primos = calcularPrimos((unsigned int) limite, &c);
	//toFile(c,primos);
	fromFile(primos , &c);
	srand(time(NULL));
	p = primos[rn(c)];
	q = primos[rn(c)];
	printf("p %.0f q :%.0f\n",p,q);
	n = calcN(p,q);
	printf("n :  %.0f\n",n);
	/*
	Escojer un numero e entre 1 < e <= phi(n)  mcd(n,e)=1 
	calcular su inverso
	*/
	
	return 0;
}
