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
	primos = (int *) malloc( limite/2 );

	fromFile(primos , &c);
	srand(time(NULL));
	p = 17;//primos[rn(c)];
	q = 11;//primos[rn(c)];
	printf("p %d q :%d\n",p,q);
	n = calcN(p,q);
	printf("n :  %d\n",n);
	phin = phiN(p, q);
	printf("phi (n) = %d\n",phin);

	e = 7;
	extEuclid((int)e, (int)phin, &x, &y, &f);
	printf("x = %d y = %d f = %d\n", x, y, f);

	printf("RSA public Key : (  %d , %d ) \n",e,n);
	printf("RSA secret Key : (  %d , %d ) \n",x,n);

	return 0;
}