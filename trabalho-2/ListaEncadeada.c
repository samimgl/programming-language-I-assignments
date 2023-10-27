#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}no;

typedef struct{
    no *inicio;
    int tam;
}Lista;

void inserirInicio(Lista *list, int valor);
void Imprimir(Lista *list);

void inserirInicio(Lista *list, int valor){
    no *novo = (no*)malloc(sizeof(no));
    novo->valor = valor; 
    novo->proximo = list->inicio;
    list->inicio = novo;
    list->tam++;
}

void Imprimir(Lista *list){
    no *inicio = list->inicio;
    while(inicio !=NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}

int main(){
    Lista list;
    int op, val;
    
    do{
        printf("\n1 - Inserir no Início \n2 - Imprimir Lista \n3- Sair\n\n");
        scanf("%d", &op);
        switch(op){
        case 1:
            printf("Digite um valor para a inserção: ");
            scanf("%d", &val);
            inserirInicio(&list, val);
            break;
        case 2:
            Imprimir(&list);
            break;
        case 3:
            printf("Finalizando...\n");
            break;
        default:
            printf("Opção Inválida.\n");
        }
    }while(op != 3);
    
    list.inicio = NULL;
    list.tam = 0;

    return 0;
}
