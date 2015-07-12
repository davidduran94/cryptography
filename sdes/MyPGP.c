#include <stdio.h>
#include <stdlib.h>
#include "libraries/definicion.h"
#include "libraries/information.h"
#include "libraries/sdes.h"
#include "libraries/OpMode.h"


int main(int argc,char *argv[]){
 
   int k;
   Key key;

   system("clear"); 

   if(argc!=5)
       usage();
   else{

       /*Imprimimos la portada si esto se encuentra definido en el header*/
         #ifdef PORTADA
            portada();
         #endif

         k=validaLlave(argv[3]);
         key=keyschedule(k);  

         CIPHERFILE(argv[1],argv[2],argv[4],key);

   }
   return 0;
}