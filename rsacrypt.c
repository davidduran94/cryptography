#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "exp.h"
#include "rsa.h"

int main(int argc,char *argv[]){
	double a, base,res;
	int n;//=33;
	if(argc > 3){
		printf("Nombre del programa %s",argv[0]);
		sscanf(argv[1], "%lf", &a);
		sscanf(argv[2], "%lf", &base);
		n = atoi(argv[3]);
		res = Power(a,base,n);
		printf("Resultado %.2f\n", res);
	}
	
	return 0;
}