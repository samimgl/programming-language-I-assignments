#include <stdio.h>
#include <string.h>

int main(){
    char frase[1024];
    char * p;
    int contador = 0;

    printf("Digite a frase:\n");
    fgets(frase, 1023, stdin);

    p = strtok(frase," .,;:\n");

    while (p != NULL){
        contador += 1;
        p = strtok(NULL, " .,;:\n");
    }

    printf("\nNumero de Palavras: \n");
    printf("%d", contador);

    return 0;
}
