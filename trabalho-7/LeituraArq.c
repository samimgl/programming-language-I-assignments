#include <stdio.h>
#include <string.h>

int numLinhas(FILE * arq);
int numCar(FILE * arq);
int numImp(FILE * arq);

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
        imp = numImp(arq);
        linhas = numLinhas(arq);
    }

    printf("%d\n", car);
    printf("%d\n", imp);
    printf("%d", linhas);

    return 0;
}

int numCar(FILE * arq){
    int conta = 0;
    char a[240];

    while(!feof(arq)){
        fgets(a, 240, arq);
        int i = 0;

        while(a[i] != '\0'){
            conta++;
            i++;
        }
    }
    return(conta + 1);
}

int numImp(FILE * arq){
    rewind(arq);
    int conta = 0;
    char * p;
    char a[240];

    while(!feof(arq)){
        fgets(a, 240, arq);
        int i = 0;

        while(a[i] != '\0'){
            p = strtok(a, " \n\t\0");

            while(p != NULL){
                conta+=1;
                p = strtok(NULL, " \n\t\0");
            }
            i++;
        }
    }
    return(conta);
}

int numLinhas(FILE * arq){
    rewind(arq);
    int linhas = 0;

    while(!feof(arq)){
        char a[240];
        fgets(a, 240, arq);
        linhas = linhas + 1;
    }
    return(linhas);
}
