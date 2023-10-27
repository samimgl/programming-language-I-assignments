#include <stdio.h>
#include <stdlib.h>

void lerArq(FILE * pFile, int * lin, int * col, int * max);
void lerPixel(FILE * pFile, int * pixel, int linha, int coluna);
void Imprime(int linha, int coluna, int pixel[]);

int main(){
    FILE * pFile;
    int total, linha, coluna, max;
    int * pixel;
    char name[100];
    
    scanf("%s", name);
    pFile = fopen(name, "r");

    if(pFile == NULL){
        printf("Erro no arquivo %s\n", name);
        return(1);
    }
    else{
        lerArq(pFile, &linha, &coluna, &max);
        total = linha * coluna;
        pixel = (int*)malloc(total * sizeof(int));
        lerPixel(pFile, pixel, linha, coluna);
        Imprime(linha, coluna, pixel);
        free(pixel);
    }

    return 0;
}

void lerArq(FILE * pFile, int * linha, int * coluna, int * max){
    char a[100];
    for(int l = 0; l <2; l++){
        fgets(a,100, pFile);
    }

    fscanf(pFile, "%d %d", linha, coluna);
    fscanf(pFile, "%d", max);
}

void Imprime(int linha, int coluna, int pixel[]){
    int total, j = 0;
    total = linha * coluna;
	
	for(int i = 0; i < total; i++){
		j = j + 1;
		if(j != coluna){
			printf("%3X ", pixel[i]);
		}
		else{
			printf("%3X\n", pixel[i]);
			j = 0;
        }
    }
}

void lerPixel(FILE * pFile, int * pixel, int linha, int coluna){
    int total;
    total = linha * coluna;

	for(int i = 0; i < total; i++){
		fscanf(pFile, "%d", &pixel[i]);
	}
}
