#include <stdlib.h>

typedef struct Nodo {
    struct Nodo* pai; 
    struct Nodo* esquerda; 
    struct Nodo* direita; 
    void *dados;
} Nodo;

typedef struct {
    struct Nodo* raiz;
    int tamanho;
} Arvore;

Arvore *cria();
int vazia();
Nodo *adiciona(Arvore *arvore, void *dados, int (criterio)(void*));
void remove(Arvore *arvore, Nodo *nodo);
