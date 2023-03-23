#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define x 3

typedef struct dados {
    float altura;
    int idade;
    char cor_olhos[2];
} tDados;

float calcula_media(tDados *info){
    float media = 0;
    int i;

    for(i = 0; i < x; i++){
        media += info[i].idade;
    }
    media = media / x;
    return media;
}

void maior_altura(tDados *info){
    float maior = 0;
    int i;

    for(i = 0; i < x; i++){
        if(info[i].altura > maior){
            maior = info[i].altura;
        }
    }
    printf("A maior altura eh: %.2f \n", maior);
}

void menor_altura(tDados *info){
    float menor;
    int i;

    menor = info[0].altura;
    for(i = 1; i < x; i++){
        if(info[i].altura < menor){
            menor = info[i].altura;
        }
    }
    printf("A menor altura eh: %.2f \n", menor);
}

int olhos_idade(tDados *info, float media){
    int i, quantidade = 0;
    char cor = 'c';

    for(i = 0; i < x; i++){
        if(strcmp(info[i].cor_olhos, cor)){
            if(info[i].idade > media){
                quantidade++;
            }
        }
    }
    return quantidade;
} 

void imprime_olhos(int num){
    printf("A quantidade de pessoas com olhos castanhos e a idade acima da media eh: %d \n", num);
}

void imprime_media(float media){
    printf("Media de idades: %.1f \n", media);
}

int main(){
    int i, num_olhos;
    float media_idade;
    tDados *dados;

    printf("Digite as seguintes informacoes: \n");
    for(i = 0; i < x; i++){
        printf("Pessoa %d: Altura - Idade - Cor dos Olhos \n", i+1);
        scanf("%f %d %c", &dados[i].altura, &dados[i].idade, dados[i].cor_olhos);
        fflush(stdin);
    }

    media_idade = calcula_media(dados);
    imprime_media(media_idade);
    maior_altura(dados);
    menor_altura(dados);
    num_olhos = olhos_idade(dados, media_idade);
    imprime_olhos(num_olhos);

    return 0;
}