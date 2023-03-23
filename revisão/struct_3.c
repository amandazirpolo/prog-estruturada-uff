#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
    float salario, vendas, salario_final; 
} tDados;

void calcula_salario(tDados *info, int i){
    info->salario_final = info->salario + (info->vendas * 0.06);
    printf("Salario final do funcionario %d: R$%.2f \n", i+1, info->salario_final);
}

int main(){
    int n, i;
    tDados *dados; 

    printf("Digite a quantidade de funcionarios: \n");
    scanf("%d", &n);

    dados = (tDados*)malloc(sizeof(tDados));
    if (!dados){
        printf("ERROR \n");
        exit(1);
    }

    printf("Digite os seguintes dados dos funcionarios: \n");
    for(i = 0; i < n; i++){
        printf("Funcionario %d: Salario - Vendas \n", i+1);
        scanf("%f %f", &dados[i].salario, &dados[i].vendas);
        fflush(stdin);
        calcula_salario(dados, i);
    }

    free(dados);
}