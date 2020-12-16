#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAMANHOMODELO 100
typedef struct {
    char modelo[TAMANHOMODELO];
    int ano;
}Carro;

int main(){
    Carro *catalogo = (Carro *)malloc(sizeof(Carro)*0); //inicializando catalogo
    char modelo[TAMANHOMODELO] = {};
    int ano = 0;
    int i = 0;
    do{

        printf("Insira o modelo: ");
        fgets(modelo, TAMANHOMODELO, stdin);
        fflush(stdin);  //limpando o buffer de entrada

        printf("Insira o ano: ");
        scanf("%d", &ano);
        fflush(stdin);  //limpando o buffer de entrada

        if(ano>=0){
            Carro carro;
            strcpy(modelo, carro.modelo);
            carro.ano = ano;
            catalogo = (Carro *)realloc(catalogo, sizeof(Carro)*(i+1));
            catalogo[i] = carro;
            i++;
        }
    }while(ano>=0);
/*
    int k;
    for(k=0; k<i; k++){
        printf("%s %d\n", catalogo[k].modelo, catalogo[k].ano);
    }
*/
    return 0;
}
