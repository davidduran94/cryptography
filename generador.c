#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "exp.h"
#include "rsa.h"

int main(int argc,char *argv[]){
	int c;
	int f,x,y;
	int p,q,n,phin,e;
	int *primos;
	primos = (int *) malloc( limite );

	fromFile(primos , &c);
	srand(time(NULL));
	p = primos[rn(c)];
	q = primos[rn(c)];
	printf("p %d q :%d\n",p,q);
	n = calcN(p,q);
	printf("n :  %d\n",n);
	phin = phiN(p, q);
	printf("phi (n) = %d\n",phin);
	do{
		e = rand();
		e = e%phin;
		printf(" e : %d\n",e);
		
		
		printf("mcd () = %.0f\n",euclides(phin, e));
	}while(  (euclides(phin, e) != 1) || e <= 0  );
	//printf("valor de e : %d\n",e);
	//e = 7;
	extEuclid((int)e, (int)phin, &x, &y, &f);
	printf("x = %d y = %d f = %d\n", x, y, f);

	printf("RSA public Key : (  %d , %d ) \n",e,n);
	printf("RSA secret Key : (  %d , %d ) \n",mod(x,phin),n);

	return 0;
}