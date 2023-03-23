#include <stdio.h>
#include <math.h>
#define x 3

typedef struct dados {
    float salario;
    int filhos, idade;
} tDados;

int main(){
    float media_sal = 0, maior_sal = 0, media_fil = 0;
    int i, aux = 0;
    tDados dados[x]; 

    printf("A seguir digite os seguintes dados: \n");
    for(i = 0; i < x; i++){
        printf("Pessoa %d: Salario - Idade - Numero de filhos \n", aux+1);
        scanf("%f %d %d", &dados[i].salario, &dados[i].idade, &dados[i].filhos);
        fflush(stdin);
    };
    for(i = 0; i < x; i++){
        media_sal += dados[i].salario;
        media_fil += dados[i].filhos;
        if (dados[i].salario > maior_sal) {
            maior_sal = dados[i].salario;
        }
    }
    media_sal = media_sal / x;
    media_fil = media_fil / x;

    printf("Media do salario da populacao: %.2f \n", media_sal);
    printf("Media da quantidade de filhos da populacao: %.0f \n", ceil(media_fil));
    printf("O maior salario entre a populacao eh: %.2f", maior_sal);

    return 0;
}