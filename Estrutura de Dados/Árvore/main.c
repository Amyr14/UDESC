#include <stdio.h>
#include <string.h>
#include "./Headers/arvore_avl.h"
#include "./Headers/arvore_avl.h"

long hash(char *str);


int main()
{ 
    Arvore *arvore = criar_arvore();
    FILE *arquivo = fopen("DataSet.txt", "r");
    char linha[256];
    char *token;
    char delimitador[2] = {' '};
    int contagem_linha = 0;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        contagem_linha += 1;
        token = strtok(linha, delimitador);
        while (token != NULL)
        {
            if ((token[0] >= 65 && token[0] <= 90) || (token[0] >= 97 && token[0] <= 122))
            {
                arvore_inserir(arvore, hash(token), contagem_linha);
                break; // sai do loop, indo para prox linha para não inserir o curso na arvore (próxima string de letras)
            }
            token = strtok(NULL, delimitador);
        }
    }
    char *busca = "Clara";

    Lista* ocorrencias = arvore_buscar(arvore, hash(busca));
    printf("Ocorrências de %s:\n", busca);
    if ( !ocorrencias )
        printf("\nNenhuma Ocorrência");
    else {
        Nodo_LDE* aux = ocorrencias->inicio;
        while (aux != NULL){
            printf("Linha: %i\n", aux->linha);
            aux = aux->proximo;
        }
    }
    destruir_arvore(arvore);
}

long hash(char *str)
{
    long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}
