// 2. Considere uma lista onde cada nó é composto pelo código, nome e preço de um produto. A lista está
// ordenada por ordem crescente do código do produto.
// a. Considerando alocação sequencial estática, faça a declaração desta estrutura e uma função
// que receba esta lista como parâmetro e que escreva os dados de todos os produtos contidos
// na lista.
// b. Considerando uma lista simplesmente encadeada dinâmica, faça a declaração desta
// estrutura e uma função que calcule e retorne a média de preços.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista_um {
    int codigo_produto;
    float preco_produto;
    char nome_produto[50];
} tLista_estatica;

typedef struct lista_dois {
    int codigo;
    float preco;
    char nome[50];
    struct lista *prox;
} tLista_dinamica;

void imprime_lista_estatica(tLista_estatica *dados, int num){
    int i;

    for(i = 0; i < num; i++){
        printf("=========================================== \n");
        printf("Produto %d: \n", i+1);
        printf("cod: %d ------ val: R$%.2f ------ prod: %s \n", dados[i].codigo_produto, dados[i].preco_produto, dados[i].nome_produto);
    }
}

tLista_dinamica *cria_lista_dinamica(){
    return NULL;
}

tLista_dinamica *transfere_dados(tLista_dinamica *info_dois, tLista_estatica *info_um, int qtd, float *media){
    tLista_dinamica *aux, *novo;
    int i;

    for(i = 0; i < qtd; i++){
        novo = (tLista_dinamica*)malloc(sizeof(tLista_dinamica));

        aux = info_dois;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->codigo = info_um[i].codigo_produto;
        novo->preco = info_um[i].preco_produto;
        strcpy(aux->nome, info_um[i].nome_produto);
        novo->prox = NULL;
        media += novo->codigo;
    }
    return info_dois;
}

void imprime_lista_dinamica(tLista_dinamica *dados){
    tLista_dinamica *aux;
    int i = 1;

    aux = dados;
    while(aux != NULL){
        printf("=========================================== \n");
        printf("Produto %d: \n", i);
        printf("cod: %d ------ val: R$%.2f ------ prod: %s \n", aux->codigo, aux->preco, aux->nome);
        i++;
        aux = aux->prox;
    }
    
}

int main(){
    int qtd, i;
    float media = 0;
    tLista_estatica *dados_um;
    tLista_dinamica *dados_dois;

    printf("Quantos produtos serao inseridos no sistema? \n");
    scanf("%d", &qtd);
    printf("=========================================== \n");

    dados_um = (tLista_estatica*)malloc(qtd*(sizeof(tLista_estatica))); // alocando memoria para lista estatica
    if (!dados_um){
        printf("ERROR \n");
        exit(1);
    }
    
    for(i = 0; i < qtd; i++){
        printf("Produto %d: codigo - preco - nome \n", i+1);
        scanf("%d %f %s", &dados_um[i].codigo_produto, &dados_um[i].preco_produto, dados_um[i].nome_produto);
        fflush(stdin);
        printf("- \n");
    }
    
    printf("Lista dos produtos catalogados: \n");
    imprime_lista_estatica(dados_um, qtd);

    dados_dois = cria_lista_dinamica();
    dados_dois = transfere_dados(dados_dois, dados_um, qtd, &media);

    media = media / qtd;

    printf("A media do preco dos produtos cadastrados eh: R$%.2f \n");

    free(dados_um);
    free(dados_dois);

    return 0;
}

