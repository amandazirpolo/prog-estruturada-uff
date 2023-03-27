#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} tLista;

void menu(){
    printf("--------------- MENU --------------- \n");
    printf("------------------------------------ \n");
    printf("1. Operacao: intersecao; \n");
    printf("2. Operacao: uniao; \n");
    printf("3. Operacao: diferenca; \n");
    printf("4. Operacao: pertinencia; \n");
    printf("5. Imprimir as listas; \n");
    printf("6. Sair do programa. \n");
    printf("------------------------------------ \n");
}

tLista *cria_lista(){
    return NULL;
}

tLista *insere_elemento(tLista *dados, int elem){
    tLista *novo;

    novo = (tLista*)malloc(sizeof(tLista));
    novo->info = elem;
    novo->prox = dados;
    return novo;
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

int verifica_elemento(tLista *dados, int elem){
    tLista *aux;

    aux = dados;
    while(aux != NULL){
        if(aux->info == elem){
            return 1;
        } else {
            aux = aux->prox;
        }
    }
    return 0;
}

tLista *intersecao(tLista *l1, tLista *l2){
    tLista *aux_1, *aux_2, *l3;
    int verifica;

    l3 = cria_lista();

    aux_1 = l1;
    aux_2 = l2;
    while(aux_1 != NULL){
        while(aux_2 != NULL){
            if(aux_1->info == aux_2->info){
                verifica = verifica_elemento(l3, aux_1->info);
                if(!verifica){
                    l3 = insere_elemento(l3, aux_1->info);
                }
            }
            aux_2 = aux_2->prox;
        }
        aux_1 = aux_1->prox;
    }
    return l3;
}

tLista* uniao(tLista *l1, tLista *l2){
    tLista *aux_2, *aux_3, *l3;
    int verifica;

    l3 = cria_lista();
    
    // a lista resultante recebe lista um
    l3 = l1;
    aux_2 = l2;
    aux_3 = l3;
    // o laço procura os elementos que sao diferentes e verifica se ja estao na lista
    while(aux_3 != NULL){
        while(aux_2 != NULL){
            if(aux_3->info != aux_2->info){
                verifica = verifica_elemento(l3, aux_2->info);
                if(!verifica){
                    l3 = insere_elemento(l3, aux_2->info);
                }
            }
            aux_2 = aux_2->prox;
        }
        aux_3 = aux_3->prox;
    }
    return l3;
}

tLista* diferenca(tLista *l1, tLista *l2){
    tLista *aux_1, *aux_2, *l3;
    int verifica;

    l3 = cria_lista();

    aux_1 = l1;
    aux_2 = l2;
    while(aux_1 != NULL){
        while(aux_2 != NULL){
            if(aux_1->info != aux_2->info){
                // se info l1 for diferente de info l2, ele insere o elemento de l1 em l3
                verifica = verifica_elemento(l3, aux_1->info);
                if(!verifica){
                    l3 = insere_elemento(l3, aux_1->info);
                }
            }
            aux_2 = aux_2->prox;
        }
        aux_1 = aux_1->prox;
    }
    return l3;
}

tLista *pertinencia(tLista *l1, tLista *l2){

}

int main(){
    tLista *lista_um, *lista_dois, *lista_tres;
    int tam_1, tam_2, i, elem, op;

    // cria as tres listas
    lista_um = cria_lista();
    lista_dois = cria_lista();
    lista_tres = cria_lista();

    printf("Qual o tamanho das listas um e dois? \n");
    scanf("%d %d", &tam_1, &tam_2);
    printf("------------------------------------ \n");
    printf("Preencha as listas com numeros inteiros: \n");
    printf("------------------------------------ \n");

    // preenche a primeira lista
    for(i = 0; i < tam_1; i++){
        printf("Lista 1 - elemento %d: \n", i+1);
        scanf("%d", &elem);
        fflush(stdin);
        lista_um = insere_elemento(lista_um, elem);
    }
    printf("------------------------------------ \n");
    // preenche a segunda lista
    for(i = 0; i < tam_2; i++){
        printf("Lista 2 - elemento %d: \n", i+1);
        scanf("%d", &elem);
        fflush(stdin);
        lista_dois = insere_elemento(lista_dois, elem);
    }

    menu();
    printf("Digite a operacao desejada: \n");
    scanf("%d", &op); 
    while(op != 6){
        switch(op){
            case 1:
                lista_tres = intersecao(lista_um, lista_dois);
                printf("Lista resultante da intersecao: \n");
                imprime_lista(lista_tres);
                printf("------------------------------------ \n");
                break;
            case 2:
                lista_tres = uniao(lista_um, lista_dois);
                printf("Lista resultante da uniao: \n");
                imprime_lista(lista_tres);
                printf("------------------------------------ \n");
                break;
            case 3:
                lista_tres = diferenca(lista_um, lista_dois);
                printf("Lista resultante da diferenca: \n");
                imprime_lista(lista_tres);
                printf("------------------------------------ \n");
                break;
            case 4:
                break;
            case 5:
                printf("------------------------------------ \n");
                printf("Lista 1: \n");
                imprime_lista(lista_um);
                printf("Lista 2: \n");
                imprime_lista(lista_dois);
                printf("------------------------------------ \n");
                break;
        }
        menu();
        printf("Digite a operacao desejada: \n");
        scanf("%d", &op);
    } 

    free(lista_um);
    free(lista_dois);
    free(lista_tres);

    return 0;
}