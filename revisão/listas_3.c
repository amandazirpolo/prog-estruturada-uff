#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} tLista;

tLista *cria_lista(){
    return NULL;
}

tLista *insere_elemento_final(tLista *dados, int elem){
    tLista *aux, *novo;
    
    novo = (tLista*)malloc(sizeof(tLista));

    if(dados == NULL){
        novo->info = elem;
        novo->prox = NULL;
        dados = novo;
    } else {
        aux = dados; 
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->info = elem;
        novo->prox = NULL;
    }
    return dados;
}

void imprime_lista(tLista *dados){
    tLista *aux;

    aux = dados;
    while(aux != NULL){
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
    printf("NULL \n");
}

int busca_elemento(tLista *dados, int elem){
    tLista *aux;

    aux = dados;
    if(dados != NULL){ // testa para ver se a lista esta vazia
        if(aux->info == elem){
            return 1; // se o elemento estiver retorna 1
        } else {
            return busca_elemento(aux->prox, elem);
        }
    } else {
        return 0; // se o elemento n estiver retorna 0
    }
}

int main(){
    tLista *lista;
    int i, qtd, dado, existe;

    lista = cria_lista();

    printf("Qual sera o tamanho da lista? \n");
    scanf("%d", &qtd);
    
    for(i = 0; i < qtd; i++){
        printf("Elemento %d: \n", i+1);
        scanf("%d", &dado);
        fflush(stdin);
        lista = insere_elemento_final(lista, dado);
    }

    printf("---------------------------------- \n");
    printf("Qual elemento deseja buscar na lista? \n");
    scanf("%d", &qtd);

    existe = busca_elemento(lista, qtd);
    if(existe){
        printf("O elemento esta na lista! \n");
    } else {
        printf("O elemento nao esta na lista! \n");
    }

    imprime_lista(lista);

    free(lista);

    return 0;
}

