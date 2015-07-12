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
	int f,x,y;
	int p,q,n,phin,e;
	int *primos;
	primos = (int *) malloc( limite/2 );
	//primos = calcularPrimos((unsigned int) limite, &c);
	//toFile(c,primos);
	fromFile(primos , &c);
	srand(time(NULL));
	p = 17;//primos[rn(c)];
	q = 11;//primos[rn(c)];
	printf("p %d q :%d\n",p,q);
	n = calcN(p,q);
	printf("n :  %d\n",n);
	phin = phiN(p, q);
	printf("phi (n) = %d\n",phin);
	/*
	do{
		e = rand();
		e = fmod(e, phin);
		printf(" e : %.0f\n",e);
		//printf("mcd () = %.0f\n",euclides(n, e));
	}while( e <= 0 && euclides(phin, e) == 1);
	*/
	e = 7;
	//Inverso(e,n,&f,&x,&y);
	extEuclid((int)e, (int)phin, &x, &y, &f);
	printf("x = %d y = %d f = %d\n", x, y, f);

	printf("RSA public Key : (  %d , %d ) \n",e,n);
	printf("RSA secret Key : (  %d , %d ) \n",x,n);
	/*
	Escojer un numero e entre 1 < e <= phi(n)  mcd(n,e)=1 
	calcular su inverso
	*/
	
	return 0;
}
