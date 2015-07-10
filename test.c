#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "exp.h"

#define TRUE 1;
#define FALSE 0;


int rn(int mod){	
	srand(time(NULL));
	int r = rand();
	return r%mod;
}

int calcN(int a,int b){
	return a*b;
}

int phiN(int a, int b){
	return (a-1)*(b-1);
}

int * calcularPrimos(unsigned int limite,int *c)
{
    int i;
    int mul;
    int *a = (int *) malloc(limite/2);
    char *compuesto = (char *)malloc(limite +1);
    compuesto[1] = TRUE;
    (*c) =0;
        //idenficar los numeros compuestos
        for (i = 2; i <= limite; i++) {
            if (!compuesto[i]) {
                // 'i' es primo
                a[(*c)]= i;
                (*c)++;
                mul = 2;
                while (i * mul <= limite) {
                    compuesto [i * mul] = TRUE;
                    mul++;
                }
            }
        }
        return a;
}

int main(int argc,char *argv[]){
	int i=0,c;
	int *primos;
	primos = calcularPrimos((unsigned int) 1000000, &c);
	do{
		printf("%d\n",primos[i]);
		i++;
	}while(i<c);
	
	return 0;
}

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
