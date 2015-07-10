#include "exp.h"

int binex(double a){
	int e=0,c=1;
	while(c <= a){
		e++;
		c = pow(2,e);
	}
	return e-1;
}
int elevar(int a, int n){
	int j;
	double aux=1;
	for(j=0;j<n;j++)
		aux = aux*a;
	return aux;
} 

double elevarA(double base, int exponente, int n){
	int i;
	double res=1;
	for(i=0;i<exponente;i++){
		res = res * base;
		res = fmod(res,n);
	}
	return res;
}

double Power(double a, double base , int n){
	double res=1;
	int k;
	do{
		k = binex(a);
		a= a- elevar(2,k);
		//printf("exponente %d\n ", elevar(2,k)  ) ;
		res = res * elevarA( base, elevar(2,k), n);
		//printf("exponenciacion : %.2f\n", elevarA( base, elevar(2,k), n) );
	}while(a > 0);
	return fmod(res,n);
}