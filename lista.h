#ifndef listaD
#define listaD

#define TRUE 1
#define FALSE 0

typedef struct Nodo_ListaD{
	
	int dato;
	struct Nodo_ListaD * sig;
	struct Nodo_ListaD * ant;
}Nodo_ListaD;

typedef Nodo_ListaD * LISTA;

LISTA creaLista();
Nodo_ListaD * creaNodo();
int esVaciaLista(LISTA );
LISTA insertar (LISTA , int);
LISTA insertarInicio(LISTA, int);
int busqueda (LISTA, int);
LISTA eliminar(LISTA, int);
void mostrar(LISTA );

#endif