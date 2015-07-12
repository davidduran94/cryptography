#ifndef SDES_H
#define SDES_H

#include "llave.h"

extern const unsigned char sbox0[4][4];

extern const unsigned char sbox1[4][4];
 
unsigned char IP(unsigned char B);

unsigned char EP(unsigned char B);

unsigned char invIP(unsigned char B);

unsigned char P4(unsigned char B);

unsigned char fk(unsigned char IP,unsigned char k);

unsigned char SW(unsigned char B);

unsigned char SDES(unsigned char m, unsigned char k1 ,unsigned char k2);

#endif