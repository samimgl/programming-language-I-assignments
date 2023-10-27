// modularizando o código que lê um arquivo e retorna o número de caracteres + número de linhas + números de caracteres imprimíveis
#include <stdio.h>
#include <string.h>

#include "Conta.h"

int main(){
    FILE * arq;
    int linhas, car, imp;

    char name[50];

    scanf("%s", name);
    arq = fopen(name, "r");

    if(arq == NULL){
        printf("Erro no arquivo %s\n", name);
        return(1);
    }
    else{
        car = numCar(arq);
        linhas = numLinhas(arq);
    }
    
    imp = car - linhas;

    printf("%d\n", car);
    printf("%d\n", imp);
    printf("%d", linhas);

    return 0;
}
