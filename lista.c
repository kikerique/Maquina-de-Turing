#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void manejaError(int);



LISTA creaLista(){
	LISTA l=NULL;
	return l;
}

Nodo_ListaD * creaNodo(){
	Nodo_ListaD * nld;
	nld=(Nodo_ListaD *)malloc(sizeof(Nodo_ListaD));
	if(nld==NULL){
		manejaError(0);
		//exit(0);
	}
	nld->sig=NULL;
	nld->ant=NULL;
	return nld;
}
int esVaciaLista(LISTA l){
	if(l==NULL)
		return TRUE;
	return FALSE;
}

void mostrar(LISTA l){
	Nodo_ListaD * aux;
	int pos=0;
	if(esVaciaLista(l)==TRUE){
		manejaError(0);//lista vacia.
		//exit(0);
	}
	aux=l;

	do{printf("\n%c\n", aux->dato);
		aux=aux->sig;
		pos++;
	}while(aux!=NULL);
}

LISTA insertar(LISTA l, int e){
	Nodo_ListaD * aux;
	Nodo_ListaD * nld;
	Nodo_ListaD * aux2;

	aux=l;
	nld=creaNodo();

	if(esVaciaLista(l)==TRUE){
		nld->dato=e;
		l=nld;
		return l;
	}
	while(aux!=NULL){
		aux2=aux;
		aux=aux->sig;
	}

	nld->dato=e;
	aux2->sig=nld;
	nld->ant=aux2;
	nld->sig=aux;

	return l;
}

LISTA eliminar(LISTA l, int e){
	Nodo_ListaD * aux;
	Nodo_ListaD * aux2;
	aux=l;
	aux2=l;

	if(esVaciaLista(l)==TRUE){
		manejaError(0);//lista vacia.
		//exit(0);
	}
	while(aux !=NULL && e!=aux->dato){
		aux2=aux;
		aux=aux->sig;
	}
	if(aux==NULL)
		printf("\nElemento %d no se encuentra en la lista \n",e);

	else if (aux==aux2){
		l=aux->sig;
		if(aux->sig !=NULL)
			l->ant=NULL;
		printf("Elemento %d ha sido borrado... \n",aux->dato);
		free(aux);
	}
	else{
		aux2->sig=aux->sig;
		if(aux->sig!=NULL)
			aux->sig->ant=aux->ant;
		printf("Elemento %d ha sido borrado....\n",aux->dato);
		free(aux);
	}
	return l;
}
int busqueda(LISTA l,int elem)
{

	Nodo_ListaD * aux;
	aux=l;
	int pos=0;
	if(esVaciaLista(l)==TRUE){
		manejaError(0);// lista vacia
		//exit(0);
	}
	while(aux!=NULL && aux->dato!=elem){
		aux=aux->sig;
		pos++;
	}
	if(aux==NULL)
		//printf("El elemento %d NO se encuentra en la Lista \n", elem);
		return FALSE;
	else
		//printf("El elemento %d se encuentra en la posición %d \n",elem,pos);
		return TRUE;

}