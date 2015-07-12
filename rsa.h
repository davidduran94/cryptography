#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED

#define TRUE 1;
#define FALSE 0;

static const int limite = 100;

/* ^^ these are the include guards */

/* Prototypes for the functions */
/* Sums two ints */
void extEuclid(int a, int b, int *x, int *y, int *d);

void Inverso(double a, double b, double *x, double *y, double *d);

int ec(int a, int b);

double euclides(double a, double b);

int rn(int mod);

double calcN(int a,int b);

int phiN(int a, int b);

int * calcularPrimos(unsigned int limite,int *c);

void toFile(int c,int *primos);

void fromFile(int *primos,int *c);

void usageCrypt(void);

int mod(int k, int n);
#endif