#include <stdio.h>

int pixels(FILE * pFile);

int main(){
    FILE * pFile;
    char name[50];

    printf("Digite o nome do arquivo: ");
    scanf("%s", name);

    pFile = fopen(name,"r");

    if(pFile == NULL){
        printf("Erro: arquivo inexistente\n");
        return(1);
    }
    else{
        pixels(pFile);
    }
    
    return 0;
}

int pixels(FILE * pFile){
    int linha, coluna;
        
        for(int l = 0; l <2; l++){
            char a[100];
            fgets(a,100, pFile);
        }

        fscanf(pFile, "%d", &linha);
        fscanf(pFile, "%d", &coluna);

        int impressao[linha][coluna];

        for(int l = 0; l <2; l++){
            char a[100];
            fgets(a,100, pFile);
        }

        for(int i = 0; i<linha; i++){
            for(int j = 0; j <coluna; j++){
                int pixel;
                fscanf(pFile, "%d", &pixel);
                impressao[i][j] = pixel;
            }
        }
        for(int i = 0; i<linha; i++){
            for(int j = 0; j <coluna; j++){
                if(j != coluna - 1){
                    printf("%3X ", impressao[i][j]);
                }
                else{
                    printf("%3X\n", impressao[i][j]);
                }
            }
        }
    return (0);
}
