/*****************************************************************************************

Incluye definiciones que permiten compilar el programa
en modo:

	DEBUG (Muestra las etapas de cifrado SDES)
	SBOXSHOW (Muestra los numeros obtenidos por SBOXING)
	SBOXINDEX (Muestra los indices obtenidos a partir de la cadena original)
	CHARSHOW (Al imprimir un dato de 8bits muestra valores asociados en formatos int,hex,char)

	*Para activar cada uno mantener la definicion
	*Para desactivar se puede comentar la definicion
	*Las definiciones anidadas se anulan de una sola vez
		comentando la condicion superior

*****************************************************************************************/
#define PORTADA		
#define CHARSHOW
#define SHOWOPTIONS
#define DEBUG
	#ifdef DEBUG
		#define SBOXSHOW
				#ifdef SBOXSHOW
					#define SBOXINDEX
					#define SHOWKSCH
				#endif
	#endif
