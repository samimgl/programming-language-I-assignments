#include <stdio.h>
#include <string.h>

#include "Conta.h"

int numCar(FILE * arq){
    int conta = 0;

    while(getc(arq) != EOF){
        conta = conta + 1;
    }
    return(conta);
}

int numLinhas(FILE * arq){
    rewind(arq);
    int linhas = 0;
    char caract;
    while((caract = fgetc(arq)) != EOF){
        if(caract == '\n'){
            linhas = linhas + 1;
        }
    }
    return(linhas);
}
