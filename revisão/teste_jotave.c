#include <stdio.h>
#include <string.h>


typedef struct transito{
    char sigla[50];
    int QndVeiculo,QndAcidentes;
    
}Transitobr;


void CalculaAcidente(Transitobr* acidentes){
    int quantidadedecarros=0,guarda;
    for(int i=0;i<=2;i++){
        if(acidentes[i].QndVeiculo>quantidadedecarros){
            quantidadedecarros=acidentes[i].QndVeiculo;
            guarda=i;
        }
    }
    printf("%s eh o estado com mais carros",acidentes[guarda].sigla);

}


void CalculaPorcentagem(Transitobr* acidentes){
    float MenorIndice=100, porcentagem;
    int guarda;
    for(int i=0;i<=2;i++){

        porcentagem = (acidentes[i].QndAcidentes / 100) * acidentes[i].QndVeiculo;
        if(porcentagem<MenorIndice){
            guarda=i;
            MenorIndice=porcentagem;
        }
    }
    printf("%s eh o estado com menor indice com %f",acidentes[guarda].sigla, porcentagem);
}


void CalculaTotal(Transitobr* acidentes){
    int Totalacidentes=0;
    for(int i=0;i<=2;i++){
        Totalacidentes+=acidentes[i].QndAcidentes;
    }

    printf("Quantidade total de acidentes:%d",Totalacidentes);
}


void main(){

    Transitobr acidentes[3];


    for(int i=0;i<=2;i++){
        printf("Sigla do estado:\n");
        scanf("%s", &acidentes[i].sigla);
        fflush(stdin);
        printf("Quantidade de veiculos:\n");
        scanf("%d", &acidentes[i].QndVeiculo);
        fflush(stdin);
        printf("Quantidade de acidentes:\n");
        scanf("%d", &acidentes[i].QndAcidentes);
        fflush(stdin);
    }

    CalculaTotal(acidentes);
    CalculaAcidente(acidentes);
    CalculaPorcentagem(acidentes);
}