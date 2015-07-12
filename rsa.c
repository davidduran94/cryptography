#include "rsa.h"

void extEuclid(int a, int b, int *x, int *y, int *d){
  int q, r, x1, x2, y1, y2;

  if (b == 0) {
    *d = a, *x = 1, *y = 0;
    return;
  }

  x2 = 1, x1 = 0, y2 = 0, y1 = 1;

  while (b > 0) {
    q = a / b, r = a - q * b;
    *x = x2 - q * x1, *y = y2 - q * y1;
    a = b, b = r;
    x2 = x1, x1 = *x, y2 = y1, y1 = *y;

  }
  *d = a, *x = x2, *y = y2;

}

void Inverso(double a, double b, double *x, double *y, double *d){
  double q, r, x1, x2, y1, y2;

  if (b == 0) {
    *d = a, *x = 1, *y = 0;
    return;
  }

  x2 = 1, x1 = 0, y2 = 0, y1 = 1;

  while (b > 0) {
    q = a / b, r = a - q * b;
    *x = x2 - q * x1, *y = y2 - q * y1;
    a = b, b = r;
    x2 = x1, x1 = *x, y2 = y1, y1 = *y;

  }
  *d = a, *x = x2, *y = y2;

}


int ec(int a, int b)
{
 int cociente,resto=1;

 if (a<b) {cociente=a; a=b; b=cociente;}
 while (resto>0) {
  cociente=a/b;
  resto=a%b;
  //printf("%d = %dx%d + %d\n",a,b,cociente,resto);
  a=b;
  b=resto;
 }

 return a;
}

double euclides(double a, double b)
{
 double cociente,resto=1;

 if (a<b) {cociente=a; a=b; b=cociente;}
 while (resto>0) {
  cociente=a/b;
  resto=fmod(a, b);
  //printf("%d = %dx%d + %d\n",a,b,cociente,resto);
  a=b;
  b=resto;
 }

 return a;
}

int rn(int mod){	
	return rand()%mod;
}

double calcN(int a,int b){
  double res = a*b;
	return res;
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

void toFile(int c,int *primos){

  FILE * f1;
    f1 = fopen("prime", "w");
    
    //fprintf(f1,"%d\n",primos[i]);
    fwrite( &c , sizeof(int) , 1 , f1 );
    fwrite(primos , sizeof(int) , c , f1 );

      //fprintf(f1,"%d ",i);
    fclose(f1);
}

void fromFile(int *primos,int *c){

  FILE * f1;
    f1 = fopen("prime", "r");
    
    //fprintf(f1,"%d\n",primos[i]);
    printf("leeyendo de archivo\n");
    fread(c , sizeof(int) , 1 , f1);
    fread(primos , sizeof(int) , (size_t)(*c) , f1 );

      //fprintf(f1,"%d ",i);
    fclose(f1);
    //printf("%d\n ",*c);
    printf("leectura exitosa\n");
}

void usageCrypt(void)
{
  printf("Usage:\n");
  printf(" -f<name>\n");
  printf(" -d<name>\n");
  exit (8);
}