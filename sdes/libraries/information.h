void usage(){
     printf("USAGE: ./%s <INPUTFILE> <OUTPUTFILE> <10BIT BINKEY> <OPTIONS>\n", "MyPGP");
      printf("\t<10BIT BINKEY> IE. 1000111101\n");  
      printf("\t<OPTIONS>\n");
      printf("\t  -CTR <CTR:NONCE> IE. CTR:Z\n");
      printf("\t  -CBC <CBC:IV:MODE> IE. CBC:F:E\n");     
      printf("\t  -OFB <OFB:IV:MODE> IE. CTR:Z:e\n");
      printf("\t  -CFB <CFB:IV:MODE> IE. CFB:Q:2\n");
      printf("\t  -ECB <ECB:0:MODE> IE. ECB:0:D (NOT RECOMENDED)\n");
      printf("\t\t  <MODE OPTIONS>\n\t\t      FOR ENCRIPTION:[1|E|e]\n\t\t      FOR DECRYPTION:[2|D|d]\n");
      printf("\t\t  [IV|NONCE] PARAMETERS SHOULD BE (CHAR)\n");
}

void portada(){

   printf("********************************************************************************\n");
   printf("*                                                                              *\n");
   printf("*  MMM    MMM            PPPPPPPPP      GGGGGGGGGG        PPPPPPPPP            *\n");
   printf("*  M MM  MM M            PPPPPPPPPP    GGGGGGGGGGGG       PPPPPPPPPP           *\n");
   printf("*  M MMMMMM M            P P     PPP   G G                P P     PPP          *\n");
   printf("*  M M MM M M  YY    YY  P P     PPP   G G                P P     PPP          *\n");
   printf("*  M M    M M   YY  YY   P P    PPP    G G  GGGGGGG       P P    PPP           *\n");
   printf("*  M M    M M   YY  YY   P PPPPPPP     G G  GGGGG G       P PPPPPPP            *\n");
   printf("*  M M    M M     YY     P PPPPPP      G G      G G       P PPPPPP             *\n");
   printf("*  M M    M M     YY     P P           G G      G G       P P                  *\n");
   printf("*  M M    M M     YY     P P           GGGGGGGGGG G       P P                  *\n");
   printf("*  MMM    MMM     YY     PPP (PRETTY)   GGGGGGGGGG (GOOD) PPP (PROBABILITIES)  *\n");
   printf("*                                                                              *\n");
   printf("*                                                  (to fail at cryptography)   *\n");
   printf("*                                                                              *\n");
   printf("*     BY:                                                                      *\n");
   printf("*         DAVID DURAN                                                          *\n");
   printf("*         ALEJANDRO LOPEZ                                                      *\n");
   printf("*         ANGEL LOPEZ                                                          *\n");
   printf("*                                                               JULY  2015     *\n");
   printf("*                                                                              *\n");
   printf("**********************PRESS***ANY***KEY***TO***CONTINUE*************************\n");
   getchar();
   system("clear");

}