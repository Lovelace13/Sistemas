



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
#include<stdlib.h>
#include"validar.h"

int validar(Usuario_t *u){
	int digitos = 0;
	int resultado;
	int letras = 0;
	if(islower(u->nombre[0])){
		
		toupper(u->nombre[0]);
	
	}
	if(islower(u->apellido[0])){
		
		toupper(u->apellido[0]);
	}
	if(strlen(u->password) < 10){
		
		resultado = 3;

	} 
	for(int j=0;j<strlen(u->password);j++){
		if(isalpha(u->password[j])){
			letras++;
		}
		if(isdigit(u->password[j])){
			digitos++;
		}	
		if(letras == 0){
	
			resultado = 4;
		}else if(digitos == 0){
	       
			resultado = 5;
		}else{
			resultado = 0;}	
		
	}
	return resultado;
}

