#include <stdio.h>
#include <string.h>
#define x 3

typedef struct dados {
    char estado[3];
    int num_veiculos, num_acidentes;
} tDados;

void mostra_estado(tDados *info){
    int n_carros, i;

    n_carros = info[0].num_veiculos;
    for(i = 1; i < x; i++){
        if (info[i].num_veiculos > n_carros){
            n_carros = info[i].num_veiculos;
        }
    }
    printf("Estados com maior numero de veiculos: \n");
    for(i = 0; i < x; i++){
        if(info[i].num_veiculos == n_carros){
            printf("%s \n", info[i].estado);
        }
    } 
}

void menos_acidentes(tDados *info){
    int menor = 100, proporcao = 0, i;
    char nome_est[2];

    for(i = 0; i < x; i++){
        proporcao = (info[i].num_acidentes * 100) / info[i].num_veiculos;
        if(proporcao < menor){
            menor = proporcao;
            strcpy(nome_est, info[i].estado);
        }
    }
    printf("Estado com menor indice de acidentes: %s \n", nome_est);
}

void total(tDados *info){
    int total = 0, i;

    for(i = 0; i < x; i++){
        total += info[i].num_acidentes;
    }
    printf("Numero total de acidentes: %d", total);
}

int main(){
    int i, aux = 1;
    tDados dados[x];

    printf("A seguir digite as seguintes informacoes sobre os estados: \n");
    for(i = 0; i < x; i++){
       printf("Estado %d: Sigla - Num de veiculos - Num de acidentes \n", aux);
       scanf("%s %d %d", dados[i].estado, &dados[i].num_veiculos, &dados[i].num_acidentes);
       fflush(stdin);
       aux++;
   };
    
    mostra_estado(dados);
    menos_acidentes(dados);
    total(dados);

    return 0;
}