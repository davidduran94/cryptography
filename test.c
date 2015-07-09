#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

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
int main(int argc,char *argv[]){
	double a = 3, base = 29,res;
	int n=33;
	res = Power(a,base,n);
	printf("Resultado %.2f\n", res);
	

	return 0;
}

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
