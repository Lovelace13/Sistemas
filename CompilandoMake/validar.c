



	/*	validar.h	
	 *
	 *	no se que mismo es de poner aqui pero ahi vamos
	 *	:)
	 *
	 *	*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include"validar.h"

int validar(Usuario_t *u){
	int digitos = 0;
	
	int letras = 0;
	if(strlen(u->password) < 10) return 3;
	for(int j=0;j<strlen(u->password);j++){
		if(isalpha(u->password[j])){
			letras++;
		}
		if(isdigit(u->password[j])){
			digitos++;
		}
	
	
	}
	if(letras == 0){ return 4;
	}else if(digitos == 0){ return 5;}
		else{
			return 0;}	
	

	
}

