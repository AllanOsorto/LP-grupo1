/*
* File Name: Chorros_Agua
* Author: Grupo 1
* description: Sistema show de luces y agua
* el usuario ingresa un archivo txt
**/
#include<stdio.h>
#include<conio.h>


int main()//main function
{
	FILE * flujo = fopen("Ingreso.txt", "rb");
	if (flujo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}
	
	char Caracter;
	
	while (feof(flujo)==0){
		Caracter = fgetc(flujo);
		printf("%c", Caracter);
	}
	
	fclose(flujo);
	printf("\n\nSe ha leido el archivo correctamente...");
	
	return 0;
}

