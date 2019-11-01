
/*main.c
 *
 *Hecho por: Angel Miller
 *	     Katiuska Marin
 *
 *
 * */

#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"validar.h"
#include<time.h>


void crearUsuario(Usuario_t *u);
int main(){
	unsigned int id;
	Usuario_t user;

	
	printf("-------------------------------------------------------------------------\n");
	printf("************Almacenamiento de datos estructurados en memoria*************\n");
	printf("*********************************27/10/19********************************\n");
	printf("*******************************Miller-Marin******************************\n");
	printf("-------------------------------------------------------------------------\n\n\n");
	srand(time(NULL));
	printf("Ingrese su nombre:\t");
	scanf("%s",&user.nombre);
	printf("\n");
	printf("Ingrese su apellido:\t");
	scanf("%s",&user.apellido);
	printf("\n");
	printf("Ingrese una contrasenia: ");
	scanf("%s",&user.password);
	printf("\n");

	id = rand();
	user.userid = (int)id;
	printf("Tu userID es: %d",&user.userid);
	printf("\n");
	crearUsuario(&user);
	int tipoError = validar(&user);
	switch(tipoError){

		case 0:
			printf("No se registro errores\n");
			break;
		case 3:
			printf("La contrasenia tiene una longitud inferior a 10\n");
			break;
		case 4:
			printf("La pass no contiene letras\n");
			break;
		case 5:
			printf("La pass no tiene numeros\n");
	}	


}

void crearUsuario(Usuario_t *u){
	
	char usuario[50];

	usuario[0]= tolower(u->nombre[0]);

	for(int i=0; i<strlen(u->apellido);i++){
	
		if(i == 0){
			usuario[i+1]=tolower(u->apellido[0]);
		}else{
			usuario[i+1]=u->apellido[i];
		
		}

	
	
	}

	strcpy(u->username,usuario);

	printf("Username: %s\n\n\n",&u->username);


}


