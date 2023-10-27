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

    int cimp = car - imp;

    printf("%d\n", car);
    printf("%d\n", cimp);
    printf("%d", linhas);

    return 0;
}

int numCar(FILE * arq){
    int conta = 0;

    while(getc(arq) != EOF){
        conta = conta + 1;
    }
    return(conta);
}

int numImp(FILE * arq){
    rewind(arq);
    int total, a, b, c, d, e, f, g;
    char caract;
    while((caract = fgetc(arq)) != EOF){
        if(caract == '\0'){
            a = a + 1;
        }
        if(caract == '\a'){
            b = b + 1;
        }
        if(caract == '\b'){
            c = c + 1;
        }
        if(caract == '\t'){
            d = d + 1;
        }
        if(caract == '\f'){
            e = e + 1;
        }
        if(caract == '\n'){
            f = f + 1;
        }
        if(caract == '\r'){
            g = g + 1;
        }
    }
    return(a + b + c + d + e + f + g);
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
