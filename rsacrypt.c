#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "exp.h"
#include "rsa.h"

int main(int argc,char *argv[]){
	double a = 3, base = 29,res;
	int n=33;
	if(argc > 3){
		printf("Exito %s",argv[1]);
		res = Power(a,base,n);
		printf("Resultado %.2f\n", res);
	}
	
	return 0;
}