#include<stdio.h>
#include<validar.h>
#include<guardar.h>


void guardar(Usuario_t *lista){
	
	FILE * fp;
	int i;

	fp = fopen("usuarios.txt","a");

	for(i = 0; i < sizeof(lista); i++){
		
		fprintf(fp, "%s\t%s\t%s\t%s\t%d\n",lista[i].nombre,lista[i].apellido,lista[i].username,lista[i].username,lista[i].password,lista[i].userid);
	
	}

	printf("Estoyen en guardar.c");
	fclose(fp);
	
}
