#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void manejaError(int);
void pideCadena(char*);
void pasaLista(LISTA,LISTA,char*);//Pasa los numeros de formato a#b a Lista1:a y Lista2:b
void hazMultiplicacion(LISTA,LISTA);
void enviaAlFinal(LISTA);

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
		if(numero!=0 && numero!=1)
		{
			printf("\nNumero rechazado\n");
			break;
		}else{
			list1=insertar(list1,numero);//agregar a list 1
			i++;
		}
		
	}
	j=i+1;
	while(cadena[j]!='\0')
	{
		numero=(int)cadena[i] - (int)'0';
		if(numero>=0 || numero<=1)
		{
			list2=insertar(list2,numero);//agregar a list 1
			i++;
		}else{
			printf("\nNumero rechazado\n");
			break;
		}
	}
}
void hazMultiplicacion(LISTA list1,LISTA list2)
{	
	LISTA resultado=creaLista(),aux=resultado,aux1=list1,aux2=list2;//Resultado guarda la lista de resultado y aux(n) se usa para moverse dentro de las listas creadas
	int multiplicacion=0,restante=0, intento=0;//el primer intento solo guarda el resultado de multiplicar el ultimo nodo de list1 con todos los nodos de list2
	enviaAlFinal(aux1);
	enviaAlFinal(aux2);
	while(esVaciaLista(aux1)!=1)
	{
		while(esVaciaLista(aux2)!=1)//la list2 se recorre de izquierda a derecha 
		{	
				if(intento==0)
				{
					multiplicacion=(aux1->dato)*(aux2->dato);
					aux=insertarInicio(resultado,multiplicacion);//los numeros se recorren de derecha a izquierda, por eso el insertar al inicio
					aux2=aux2->ant;
				}else{
					multiplicacion=(aux1->dato)*(aux2->dato);
					if(esVaciaLista(aux)!=1)//el resultado se recorre paralelo a la list2 pero hay veces que sobra un byte de carry
					{
						if(multiplicacion+(aux->dato)+restante==3)
						{
							aux->dato=0;
							if((aux->ant)!=NULL)
							{
								(aux->ant)->dato=(resultado,1);
								
							}else{
								aux=insertarInicio(resultado,multiplicacion+restante);//el byte de carry se inserta al inicio de resultado
								
							}
							restante=1;//byte de carry
						}else{
							if(multiplicacion+(aux->dato)+restante==2)
							{
								aux->dato=0;
								if((aux->ant)!=NULL)
								{	
									(aux->ant)->dato=(resultado,1);
									
								}else{
									aux=insertarInicio(resultado,multiplicacion+restante);//el byte de carry se inserta al inicio de resultado
								}
								restante=0;
							}else{
								aux->dato=multiplicacion+(aux->dato)+restante;
								restante=0;
							}
						}
						
					}else{
						aux=insertarInicio(resultado,multiplicacion+restante);//el byte de carry se inserta al inicio de resultado
						restante=0;
					}
					aux=aux->ant;     //Resultado y lista dos se recorren paralelamente
					aux2=aux2->ant;
				}
			
		}
		insertar(aux2,0);
		enviaAlFinal(aux2);
		enviaAlFinal(aux);
		aux1=aux1->ant;
		intento++;
		restante=0;
	}
	mostrar(resultado);
	
}
void enviaAlFinal(LISTA list)
{
	while(esVaciaLista(list)!=1)//envia la lista al final
	{
		list=list->sig;
	}
	list=list->ant;
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
