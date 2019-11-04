
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
#include<validar.h>
#include<time.h>



void crearUsuario(Usuario_t *u);
void mostrarResultados(Usuario_t *u, char msg[]);
char* mensajeError(int *err);



int main(void){
	int id;
	Usuario_t user;
	char *message;
	//char *pResponse;
	int  response = 's';
	//pResponse = &response;
	
	while(response == 's'){
	printf("-------------------------------------------------------------------------\n");
	printf("****************************Compilación con Make*************************\n");
	printf("*********************************03/11/19********************************\n");
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
	user.userid = (unsigned int)id;
	//printf("Tu userID es: %d",&user.userid);
	printf("\n\n");
	
	int tipoError = (int)validar(&user);
	crearUsuario(&user);
	
	printf("\n\n\n\nHola");
	//printf(mensajeError(&tipoError));
	strcpy(message,mensajeError(&tipoError));
	mostrarResultados(&user,message);

	
	
	printf("\n\n");
	printf("Desea ingresar otro usuario?(S/N):\t");
	scanf("%d", response);	
	printf("\n");
	if(response == 's'){
		printf("\n\n\n\n\n\n\n\n\n\n");
	}else{
		printf("Hasta la proxima XD\n\n");
	}
	
		
	}
	
}


void crearUsuario(Usuario_t *u){
		
	char usuario[50];

	usuario[0]= tolower(u->nombre[0]);

	for(int i=0; i<sizeof(u->apellido);i++){
		
		if(i == 0){
			usuario[i+1]=tolower(u->apellido[0]);
		}else{
			usuario[i+1]=u->apellido[i];
		
		}
		if(u->apellido[i]=='\0'){
			usuario[i+1] = '\0';
			break;
		}

	
	
	}
	
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
	
	/*
	 *aqui va la salida del programa o nuevo ingreso
	 * */

	
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


