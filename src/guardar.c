#include<stdio.h>
#include<validar.h>
#include<guardar.h>


void guardar(Usuario_t *lista, int *count){

	FILE * fp;
	int i;

	fp = fopen("usuarios.txt","a");
	printf("%d\n", *count);
	for(i = 0; i <= *count; i++){

		fprintf(fp, "%s\t%s\t%s\t%s\t%d\n",lista[i].nombre,lista[i].apellido,lista[i].username,lista[i].password,lista[i].userid);

	}

	printf("Estoyen en guardar.c\n");
	fclose(fp);

}
