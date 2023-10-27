#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numLinhas(char name[50]);
int numCar(char name[50]);

int main(){
    int linhas, car;

    char name[50];
    scanf("%s", name);

    
    car = numCar(name);
    //imp = numImp(arq);
    linhas = numLinhas(name);

    printf("%d\n", car);
    printf("%d", linhas);

    return 0;
}

int numCar(char name[50]){
    FILE * arq;
    arq = fopen(name, "r");
    
    int conta = 0, contb = 0;
    char a[240], b[240];

    if(arq == NULL){
        printf("Erro no arquivo texto\n");
        return(1);
    }
    else{
        while(!feof(arq)){
            fgets(a, 240, arq);
            conta = conta + 1;

            for(int j = 0; j<conta; j++){
                fgets(b, 240, arq);
                contb = contb + 1;
            }
        }
        return(conta+contb);
    }

}

int numLinhas(char name[50]){
    FILE * arq;
    arq = fopen(name, "r");

    int linhas = 0;

    if(arq == NULL){
        printf("Erro no arquivo texto\n");
        return(1);
    }
    else{
        while(!feof(arq)){
            char a[240];
            fgets(a, 240, arq);
            linhas = linhas + 1;
        }
        return(linhas);
    }
}
