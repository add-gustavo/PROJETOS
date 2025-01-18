#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;


void inserir_inicio(No **lista, int num){
    No * novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;

    }
    else{
        printf("Erro ao alocar memoria!!\n");
    }
}

void inserir_fim(No ** lista, int num){
    No *aux, * novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        if(*lista == NULL){
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;

        }

    }else{
        printf("Erro ao alocar memoria!!\n");
    }
}

void inserir_meio(No **lista, int num, int ant){

    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;

        }
        else{
            aux = *lista;
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else{
        printf("Erro ao alocar memoria!!\n");
    }

}

void inserir_ordenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));
    
    if(novo){
        novo->valor = num;
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        else if(novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }

    }
    else{
        printf("Erro ao alocar memória!\n");
    }
}

No* remover(No **lista, int num){
    No *aux, *remover = NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num){
                aux = aux->proximo;
            }
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }

    return remover;

}

No* buscar(No **lista, int num){
    No *aux, *no = NULL;

    aux = *lista;
    while(aux && aux->valor != num){
        aux = aux->proximo;
    }
    if(aux){
        no = aux;
    }
    return no;
}

void imprimir(No *no){
    printf("\n Lista: ");
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}


int main(){
    int opcao, valor, anterior;
    No *removido, *lista = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir Inicio\n\t2 - Inserir Final\n\t3 - Inserir Meio\n\t4 - Inserir Ordenado\n\t5 - Remover\n\t6 - Buscar\n\t7 - Imprimir\n\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: 
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_inicio(&lista, valor);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_fim(&lista, valor);
                break;
            case 3: 
                printf("Digite um valor e o valor de referência: ");
                scanf("%d%d", &valor, &anterior);
                inserir_meio(&lista, valor, anterior);
                break;
            case 4: 
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_ordenado(&lista, valor);
                break;
            case 5: 
                printf("Digite um valor: ");
                scanf("%d", &valor);
                removido = remover(&lista, valor);
                if(removido){
                    printf("Elemento a ser removido: %d\n", removido->valor);
                    free(removido);
                }
                else{
                    printf("Elemento inexistente!\n");
                }
                break;
            case 6:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                removido = buscar(&lista, valor);
                if(removido){
                    printf("Elemento encontrado: %d\n", removido->valor);
                }
                else{
                    printf("Elemento não encontrado!\n");
                }
                break;
            case 7:
                imprimir(lista);
                break;
            default:
                if(opcao != 0){
                printf("Opção inválida!\n");
                }
                break;
        }

    }while(opcao != 0);
    return 0;
}