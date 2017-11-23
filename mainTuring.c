#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void manejaError(int);
void pideCadena(char*);
void pasaLista(LISTA,LISTA,char*);//Pasa los numeros de formato a#b a Lista1:a y Lista2:b
void hazMultiplicacion(LISTA,LISTA);

int main()
{
	LISTA list1=creaLista();
	LISTA list2=creaLista();
	char* cadena=(char*)malloc(sizeof(char)*100);
	pideCadena(cadena);
	pasaLista(list1,list2,cadena);
	hazMultiplicacion(list1,list2);
	return 0;
}

void pideCadena(char* cadena)
{
	printf("\nBienvenido Usuario ingrese los numeros a multiplicar en formato A#B donde A y B son numeros binarios\n");
	scanf("%s",cadena);
}
void pasaLista(LISTA list1, LISTA list2, char* cadena)
{
	int i=0,j=0,numero=0;
	while(cadena[i]!='#')
	{
		numero=(int)cadena[i] - (int)'0';
		lista1=insertar(lista1,numero);//agregar a list 1
		i++;
	}
	j=i+1;
	while(cadena[j]!='\0')
	{
		lista2=insertar(lista2,numero);//agregar a list 2
		j++;
	}
}
void hazMultiplicacion(LISTA list1,LISTA list2)
{
	int i=0,j=0;
	while(/*Lista 1 llegue al fin*/){ i++;}
	
	while(/*Lista 2 llegue al fin*/){j++;}
	
}
void manejaError(int e)
{
	switch(e)
	{
		case 0:
			printf("\nLista vacia\n");
		break;
		case 2:
		break;
	}
}
