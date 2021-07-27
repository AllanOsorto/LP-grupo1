/*
* File Name: Chorros_Agua
* Author: Grupo 1
* description: Sistema show de luces y agua
* el usuario ingresa un archivo txt
**/
#include<stdio.h>
#include<conio.h>
#include<string.h>

char input[200];    // Almacena la cadena de entrada 
char token[5];      // Almacena la cadena que forma el símbolo de la palabra 
char ch;            // Almacena los caracteres leídos actualmente 
int p;              // input [] subíndice 
int fg;             // marca de cambio 
int num;            // Almacenar valores enteros 

// Matriz de caracteres bidimensionales, almacenando palabras clave 
char index[6][6]={"PSI","LUMEN","FOCOU","FOCOM","FUENTEU","FUENTEM"};

// Declaración del método de análisis léxico
void scaner();  

int main()
{
	//*****************************************************************************************************************************************************************
	//Lector de archivos
	//*****************************************************************************************************************************************************************	
	FILE *archivo;
	char caracter;
	
	archivo = fopen("Ingreso.txt","r");
	
	if (archivo == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
        else
        {
            printf("\nEl contenido del archivo es \n\n");
            while((caracter = fgetc(archivo)) != EOF)
	    {
		printf("%c",caracter);
	    }
        }
        fclose(archivo);
	return 0;

	
    p=0;
    printf("please intput string(End with '#'):\n");
    
    // leer cíclicamente en caracteres
    do {
        ch=getchar();
        input[p++] = ch;
    } while( ch!='#' );

    p=0;
    do {

        scaner();

        switch( fg )
        {
            case 8:printf("( %d,%d )   ", fg,num);break;       
            case -1:printf("input error\n");  break;           
            default:printf("( %d,%s )   ", fg, token);         
        }
    } while( fg != 0 );

    return 0;
}

/*análisis léxico*/
void scaner()
{
	int m=0;        // token [] subíndice 
	int n;
  
    // Filtrar espacios 
    ch=input[p++];
    while(ch==' ') ch=input[p++];
  
    // Flujo de procesamiento de palabras clave (identificador) 
    if(( ch<='z' && ch>='a' )||( ch<='Z' && ch>='A' ))
    {
            while(( ch<='z' && ch>='a' )||( ch<='Z' && ch>='A' )||( ch<='9' && ch>='0' ))
            {
                 token[m++] = ch;
                 ch = input[p++];
            }
            p--;
            token[m++] = '\0';
            fg = 7;

            for( n=0; n<6; n++ )
            {
                if(strcmp(token, index[n])==0)// strcmp () compara dos cadenas y devuelve 0 si son iguales 
                    {
                        fg = n+1;
                        break;
                    }
            }
    }
       
    // Flujo de procesamiento digital 
    else if(( ch<='9' && ch>='0' ))
    {
        num=0;
        while(( ch<='9' && ch>='0' ))
        {
            num = num*10+ch-'0';
            ch = input[p++];
        }
        p--;
        fg = 8;
    }
     
    // Flujo de procesamiento del delimitador del operador 
    else
        switch(ch)
        {
            case '<':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='>')          // Generar <> 
                {
                    fg=14;
                    token[m++]=ch;
                }
                else if(ch=='=')     // Generar <= 
                {
                    fg=15;
                    token[m++]=ch;
                }
                else
                {
                    fg=13;
                    p--;
                }
                token[m++] = '\0';
                break;
            }

		    case '>':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='=')        // Generar> = 
                {
                    fg=17;
                    token[m++]=ch;
                }
                else               // Generar> 
                {
                    fg=16;
                    p--;
                }
                token[m++] = '\0';
                break; 
            }
                 
            case '+': fg=9; token[0]=ch; token[1]='\0'; break;
            case '-': fg=10; token[0]=ch; token[1]='\0'; break;
            case '*': fg=11; token[0]=ch; token[1]='\0'; break;
            case '/': fg=12; token[0]=ch; token[1]='\0'; break;
            case '=': fg=18; token[0]=ch; token[1]='\0'; break;
            case ';': fg=19; token[0]=ch; token[1]='\0'; break;
            case '(': fg=20; token[0]=ch; token[1]='\0'; break;
            case ')': fg=21; token[0]=ch; token[1]='\0'; break;
            case '#': fg=0; token[0]=ch; token[1]='\0'; break;
            default: fg=-1;
        }

}



