#include <stdio.h>
#define MAX 10
/*
Discentes: Ana Júlia Almeida
Gustavo Henrique Andrade
Thiago Brito
*/

typedef struct
{
    float item[MAX];
    int topo;
} Calculadora;

void inicia(Calculadora *p)
{
    p->topo = -1;
}

int cheia(Calculadora *p)
{
    return p->topo == MAX - 1;
}

int vazia(Calculadora *p)
{
    return p->topo == -1;
}

void empilha(Calculadora *p, float num)
{
    if (cheia(p))
    {
        printf("Pilha cheia\n");
        return;
    }
    else
    {
        p->topo++;
        p->item[p->topo] = num;
    }
}
void desempilha(Calculadora *p)
{
    if (vazia(p))
    {
        printf("Pilha Vazia\n");
        return;
    }
    else
    {
        p->topo--;
    }
}

void calculo(Calculadora *p, char operador)
{
    if (operador == '+')
    {
        float aux = 0;
        for (int i = 0; i < 2; i++)
        {
            aux = p->item[p->topo] + aux;
            desempilha(p);
        }
        empilha(p, aux);
    }
    if (operador == '-')
    {
        float aux = 0;
        int trava = 0;
        for (int i = 0; i < 2; i++)
        {
            if (i == 1)
            {
                if (aux > p->item[p->topo])
                {
                    trava = 1;
                }
            }
            aux = p->item[p->topo] - aux;
            desempilha(p);
            if (trava == 1)
            {
                aux = aux * -1;
            }
        }
        empilha(p, aux);
    }
    if (operador == '*')
    {
        float aux = 1;
        for (int i = 0; i < 2; i++)
        {
            aux = p->item[p->topo] * aux;
            desempilha(p);
        }
        empilha(p, aux);
    }
    if (operador == '/')
    {
        if (p->topo != 0)
        {
            float aux = 1;
            for (int i = 0; i < 2; i++)
            {
                aux = p->item[p->topo] / aux;
                desempilha(p);
            }
            empilha(p, aux);
        }
        else
        {
            printf("Erro no resultado, foi zerado, por conta que nao e possivel divisoes por zero.\n");
            return;
        }
    }
}

void resultado(Calculadora *p)
{
    if (vazia(p))
    {
        printf("Pilha vazia\n");
        return;
    }
    printf("Resultado: %.1f\n", p->item[p->topo]);
}

int main()
{
    Calculadora p;
    inicia(&p);
    int opcao = 0;
    while (opcao != 2)
    {
        printf("----------------------------\n");
        printf("1 - Inserir dado\n");
        printf("2 - Encerrar sistema\n");
        printf("----------------------------\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            char dado = 0;
            printf("------------------------------------\n");
            printf("#: Inserir numero\n");
            printf("+: Efetuar adicao\n");
            printf("-: Efetuar subtracao\n");
            printf("*: Efetuar multiplicacao\n");
            printf("/: Efetuar divisao\n");
            printf("=: Exibir resultado\n");
            printf("------------------------------------\n");

            printf("Escreva seu calculo: ");
            while (dado != '=')
            {
                scanf(" %c", &dado);
                if (dado == '+' || dado == '-' || dado == '*' || dado == '/')
                {
                    calculo(&p, dado);
                }
                else if (dado == '#')
                {
                    float num;
                    scanf("%f", &num);
                    empilha(&p, num);
                }
                else if (dado == '=')
                {
                    resultado(&p);
                    break;
                }
                else
                {
                    printf("Operador invalido\n");
                }
            }
            inicia(&p);
        }
        else if (opcao != 2)
        {
            printf("Opcao invalida\n");
        }
    }
    printf("\nCalculadora Polonesa Finalizada.");
    return 0;
}
