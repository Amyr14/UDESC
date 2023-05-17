#include <stdlib.h>
#include "arvore.h"

Nodo *adiciona_aux(Nodo *nodo, void *dados, int (criterio)(void*, void*)) {
    
    if ( nodo == NULL ) {
        Nodo* novo_nodo = (Nodo*)malloc(sizeof(Nodo));
        novo_nodo->dados = dados;
        return novo_nodo;
    }

    if ( criterio(nodo->dados, dados) )
        nodo->direita = adiciona_aux(nodo->direita, dados, criterio);
    
    if ( !criterio(nodo->dados, dados) )
        nodo->esquerda = adiciona_aux(nodo->esquerda, dados, criterio);
    
    return nodo;
}

void *adiciona(Arvore *arvore, void *dados, int (criterio)(void*)) {
    arvore->raiz = adiciona_aux(arvore->raiz, dados, criterio);
}