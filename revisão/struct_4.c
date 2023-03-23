#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados{
    int numero_os;
    float valor_os;
    char servico[50], nome_cliente[30];
} tDados;

float calcula_media(tDados *info, int n){
    int i, media = 0;

    for(i = 0; i < n; i++){
        media += info[i].valor_os;
    }
    media = media / n;
    return media;
}

void acima_media(tDados *info, int n, float media){
    int i;

    printf("Clientes cuja OS tem o valor acima da media: \n");
    for(i = 0; i < n; i++){
        if(info[i].valor_os >= media){
            printf("%s \n", info[i].nome_cliente);
        }
    }
}

void OS_mais_cara(tDados *info, int n){
    float preco = 0;
    int i;
    char cliente[30];

    for(i = 0; i < n; i++){
        if(info[i].valor_os > preco){
            preco = info[i].valor_os;
            strcpy(cliente, info[i].nome_cliente);
        }
    }
    printf("Cliente da OS mais cara: %s \n", cliente);
}

void imprime_media(float media){
    printf("Media de preco das OS: R$%.2f \n", media);
}

int main(){
    int i, n;
    float media_preco;
    tDados *dados;

    printf("Digite a quantidade de ordens de servico: \n");
    scanf("%d", &n);

    dados = (tDados *)malloc(n*sizeof(tDados));
    if (!dados){
        printf("ERROR");
        exit(1);
    }

    printf("Digite as seguintes informacoes: \n");
    for(i = 0; i < n; i++){
        printf("Cliente %d: Numero da OS - Valor da OS - Tipo de serviço - Nome de cliente \n", i+1);
        scanf("%d %f %s %s", &dados[i].numero_os, &dados[i].valor_os, dados[i].servico, dados[i].nome_cliente);
        fflush(stdin);
    }
    
    media_preco = calcula_media(dados, n);
    imprime_media(media_preco);
    acima_media(dados, n, media_preco);
    OS_mais_cara(dados, n);

    free(dados);
}