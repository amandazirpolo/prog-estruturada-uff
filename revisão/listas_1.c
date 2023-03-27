#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
} tLista;

tLista *cria_lista(){
    return NULL;
}

tLista *insere_elemento(tLista *dados, int elem){
    tLista *novo;

    novo = (tLista*)malloc(sizeof(tLista));
    novo->info = elem;
    novo->prox = dados; // proximo do novo aponta pro inicio da lista
    return novo;
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

int conta_elementos(tLista *dados){
    tLista *aux;
    int elementos = 0;

    aux = dados;
    while(aux != NULL){
        elementos++;   
        aux = aux->prox;     
    }
    return elementos;
}

int conta_recursivo(tLista *dados, int valor){
    if(dados == NULL){
        return valor;
    } else {
        return conta_recursivo(dados->prox, valor+1);
    }
}

void menu(){
    printf("============== MENU ============== \n");
    printf("Opcao 1: inserir um elemento no inicio; \n");
    printf("Opcao 2: inserir um elemento no final; \n");
    printf("Opcao 3: imprimir a lista; \n");
    printf("Opcao 4: contar quantos elementos a lista possui; \n");
    printf("Opcao 5: sair do programa. \n");
    printf("================================== \n");
}

int main(){
    tLista *lista;
    int info, el, seleciona;

    lista = cria_lista();

    menu();
    printf("Digite a opcao escolhida: \n");
    scanf("%d", &seleciona);

    while(seleciona != 5){
        switch(seleciona){
            case 1:
                printf("Digite um valor inteiro a ser inserido no inicio da lista: \n");
                scanf("%d", &el);
                lista = insere_elemento(lista, el);
                break;
            case 2: 
                printf("Digite um valor inteiro a ser inserido no final da lista: \n");
                scanf("%d", &el);           
                lista = insere_elemento_final(lista, el);
                break;
            case 3:
                printf("================================== \n");
                printf("Lista: \n");
                imprime_lista(lista);
                printf("================================== \n");
                break;
            case 4:
                info = conta_elementos(lista);
                printf("Quantidade de elementos na lista: %d \n", info);
                break;
            default:
                printf("Opcao invalida \n");
        }
        menu();
        printf("Digite a opcao escolhida: \n");
        scanf("%d", &seleciona);
    }

    free (lista);
    return 0;
}