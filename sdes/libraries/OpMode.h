unsigned char CTR(unsigned char nonce, unsigned char counter, unsigned char m, Key K){
   unsigned char noncounter= (nonce & 0xC0)|(counter & 0x3F);
   return m ^ SDES(noncounter,K.k1,K.k2);
}

unsigned char CBC(unsigned char iv, unsigned char m, unsigned char mode, Key K){
      if(mode=='E')
         return SDES(m^iv,K.k1,K.k2);
      else
         return SDES(m,K.k2,K.k1)^iv;
}

unsigned char ECB(unsigned char m, unsigned char mode, Key K){
      if(mode=='E')
         return SDES(m,K.k1,K.k2);
      else
         return SDES(m,K.k2,K.k1);
}

unsigned char OFB(unsigned char iv, unsigned char mode, Key K){
         return SDES(iv,K.k1,K.k2);
}

unsigned char CFB(unsigned char iv, unsigned char m, unsigned char mode, Key K){
         return SDES(iv,K.k1,K.k2)^m;
}

void CIPHERFILE(const char *Source, const char *Target, const char *Mode ,Key key){

   FILE *source, *target;
   char ch; 
   unsigned char c,i;
   unsigned char NONCE=0,MODE=0,IV=0,OpMODE=0;

   /*Llenamos las variables de Opcion basados en el vector de opcion *OPT */

   OpMODE= Mode[0] ^ Mode[1] ^ Mode[2];

   if(OpMODE==69)
    NONCE = Mode[4];
   else
       IV = Mode[4];

   if( Mode[6]=='1' || Mode[6]=='E' || Mode[6]=='e')
       MODE='E';
   else
       MODE='D';

      /*Mostramos las opciones previamente procesadas si se encuentra la directiva activada*/

      #ifdef SHOWOPTIONS
         printf("OpMODE: %c%c%c CODE:%d\n",Mode[0],Mode[1],Mode[2],OpMODE);
         if(OpMODE==69)
            printf("NONCE: %d\n", NONCE);
         else
            printf("IV: %d\n", IV);
         printf("MODE: %c\n", MODE);
      #endif


   /*Procesamos los archivos de entrada y Salida*/

   source = fopen(Source, "r");
 
   if( source == NULL ){
      printf("PRESS ANY KEY TO CONTINUE...\n");
      exit(EXIT_FAILURE);
   }

 
   target = fopen(Target, "w");
   if( target == NULL ){
      fclose(source);
      printf("PRESS ANY KEY TO CONTINUE...\n");
      exit(EXIT_FAILURE);
   }




   i=0;
   while((ch = fgetc(source))!= EOF){


      if (MODE=='E'){
         /* code */
      
          if(OpMODE==69)
            c=CTR(NONCE,i,(unsigned char)ch,key);
         if (OpMODE==68)
            c=ECB((unsigned char)ch, MODE, key);
       if (OpMODE==66){
            c=CBC(IV,ch,MODE,key);
            IV=c;
       } 
       if (OpMODE==71){
           IV=CFB(IV,(unsigned char)ch,MODE,key);
           c=IV;
       }
         if (OpMODE==75){
            IV=OFB(IV,MODE,key);
            c=IV^(unsigned char)ch;
         }
    }



   else if (MODE=='D'){
            /* code */
         
             if(OpMODE==69)
               c=CTR(NONCE,i,(unsigned char)ch,key);
            if (OpMODE==68)
            c=ECB((unsigned char)ch, MODE, key);
            if (OpMODE==66){
               c=CBC(IV,ch,MODE,key);
               IV=ch;
            }  
            if (OpMODE==71){
               c=CFB(IV,(unsigned char)ch,MODE,key);
               IV=ch;
            }
            if (OpMODE==75){
               IV=OFB(IV,MODE,key);
               c=IV^(unsigned char)ch;
            }
       }

         //printTByte( "RESULT:" ,UStoB(c),8);
         fprintf(target, "%c", (char)c );
   }
 
   (MODE=='E')?printf("FILE CYPHERED SUCCESSFULLY....\n"):printf("FILE DECYPHERED SUCCESSFULLY....\n");
   fclose(source);
   fclose(target);

}