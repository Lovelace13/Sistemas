
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
#include<stdbool.h>
#include"validar.h"
#include<time.h>



void crearUsuario(Usuario_t *u);
void mostrarResultados(Usuario_t *u, char msg[]);
char* mensajeError(int *err);
int main(){
	unsigned int id;
	Usuario_t user;
	char *message;
	
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
	printf("\n\n");
	
	int tipoError = (int)validar(&user);
	crearUsuario(&user);
	
	printf("\n\n\n\n");
	//printf(mensajeError(&tipoError));
	strcpy(message,mensajeError(&tipoError));
	mostrarResultados(&user,message);


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
	for(int j = 1; j<strlen(usuario); j++){
	
		if(isupper(usuario[j])){
		
			usuario[j]=tolower(usuario[j]);

		}

	}
	usuario[strlen(usuario)] = '\0';
	strcpy(u->username,usuario);
	
	
	printf("Username: %s\n\n\n",&u->username);


}

void mostrarResultados(Usuario_t *u, char msg[]){

		
	
	printf("****************************INFORMACION**********************************\n");
	printf("*									*\n");
	printf("*	Nombre:		%s                                      	*\n",u->nombre);	
	printf("*	Apellido:	%s                                      	*\n",u->apellido);
	printf("*	Username:	%s                                              *\n",u->username);	
	printf("*	Password:	%s                                              *\n",u->password);
	printf("*	User ID:	%d                                              *\n",u->userid);
	printf("*									*\n");
	printf("*	ERROR:		%s						*\n",msg);
	printf("*									*\n");
	printf("*************************************************************************\n");
	
	

	

}

char *mensajeError(int *err){
	
	
	
	char *msg = malloc(sizeof(char[MAXSTR]));	
	
	switch(*err){

		case 0:

			strcpy(msg, "No se registro errores");
			//printf("Aqui entra");	
			break;
		case 3:

			strcpy(msg, "La contrasenia tiene una longitud inferior a 10");
			//printf("Aqui tb");
			break;
		case 4:
			strcpy(msg, "La pass no contiene letras");
			//printf("Por supuesto");
			break;
		case 5:
			strcpy(msg, "La pass no tiene numeros");
			
			break;
	}
	
	return(msg);	
}


