#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED

#define TRUE 1;
#define FALSE 0;
/* ^^ these are the include guards */

/* Prototypes for the functions */
/* Sums two ints */
void extEuclid(int a, int b, int *x, int *y, int *d);

int ec(int a, int b);

int rn(int mod);

int calcN(int a,int b);

int phiN(int a, int b);

int * calcularPrimos(unsigned int limite,int *c);

#endif