#include <stdio.h>
#include <stdlib.h>
/* Componentes: Ana Júlia Almeida, Gustavo Henrique Andrade, Thiago Brito, 
2 semestre, análise e desenvolvimento de sistemas, 2023.2*/

#define NUM_PERGUNTAS 10
#define NUM_CASAS 4
#define Caractere 300

// Struct para representar uma casa de Hogwarts
typedef struct {
    char nome[20];
    char descricao[Caractere];
    int caracteristicas[NUM_PERGUNTAS];
} Casa;

// Função para calcular a casa com base nas respostas do usuário
int calcularCasa( Casa casas[], int respostas[]) {
    int i, j, pontuacaocasa, pontuacao, PONTOSCASA[NUM_CASAS];
   // Cálculo de pontuação para cada casa
    for (i = 0; i < NUM_CASAS; i++) {
        pontuacaocasa = 0;
        for (j = 0; j < NUM_PERGUNTAS; j++) {
            pontuacao = (casas[i].caracteristicas[j] - respostas[j]);
        //retira os numeros negativos
        if(pontuacao < 0){
            pontuacao*=-1;
        }
            pontuacaocasa+= pontuacao; 
        }
        //vetor de armazenamento de pontuação das casa
        PONTOSCASA[i] = pontuacaocasa;
    }

    int indice=0, menorpontuacao=PONTOSCASA[0];
        //comparando a melhor casa
        for (i = 0; i < NUM_CASAS; i++){ 
                if (PONTOSCASA[i] < menorpontuacao){
                    menorpontuacao = PONTOSCASA[i];
                indice = i;
                }
            }
        int PONTEIRO[NUM_CASAS];

    //Comparando se há pontuações iguais 
        for (i = 0; i < NUM_CASAS; i++){
           if (PONTOSCASA[indice] == PONTOSCASA[i] && indice!= i){
            PONTEIRO[indice] = 1;
            PONTEIRO[i] = 1;
         }
         else{
            PONTEIRO[i] = 0;
         }
        }

    int aux, melhorCasa = indice, NovaPontuacao[NUM_CASAS];
    if (PONTEIRO[indice] != 0){
        // vai comparar a pergunta principal referente a casa
        for (i = 0; i < NUM_CASAS; i++){
            pontuacao = 0;
            if (PONTEIRO[i] != 0){
                if (i == 0){
                    aux = (casas[i].caracteristicas[0] - respostas[0]);
                    if (aux < 0) {aux *= -1;}
                    pontuacao += aux;
                    aux = (casas[i].caracteristicas[3] - respostas[3]);
                    if (aux < 0) {aux *= -1;}
                    pontuacao += aux;
                }
                if (i == 1){
                    aux = (casas[i].caracteristicas[1] - respostas[1]);
                    if (aux < 0) {aux *= -1;}
                    pontuacao += aux;
                    aux = (casas[i].caracteristicas[5] - respostas[5]);
                    if (aux < 0) {aux *= -1;}
                    pontuacao += aux;
                }
                if (i == 2){
                    aux = (casas[i].caracteristicas[2] - respostas[2]);
                    if (aux < 0) {aux *= -1;}
                    pontuacao += aux;
                     aux = (casas[i].caracteristicas[7] - respostas[7]);
                    if (aux < 0) {aux *= -1;}
                    pontuacao += aux;
                }
                if (i == 3){
                    aux = (casas[i].caracteristicas[3] - respostas[3]);
                    if (aux < 0) {aux *= -1;}
                    pontuacao += aux;
                    aux = (casas[i].caracteristicas[9] - respostas[9]);
                    if (aux < 0) {aux *= -1;}
                    pontuacao += aux;
                }
                NovaPontuacao[i] = pontuacao;
            }
            else{
                NovaPontuacao[i] = -1;
            }
        }

        int melhorpontuacao=NovaPontuacao[0];
        // vai indicar a comparação mais próxima
        for (i = 0; i < NUM_CASAS; i++){
            if (NovaPontuacao[i] >= 0){
                    if (NovaPontuacao[i] < melhorpontuacao){
                        melhorpontuacao = NovaPontuacao[i];
                        indice = i;
                    }
                
            }
        }
        // vai indicar a melhor casa
        melhorCasa = indice;
    }
       

    //retorna o valor do cálculo
    return melhorCasa;
}

// Função para exibir as informações da casa
int exibirCasa(Casa casas[], int indiceCasa) {
    printf("\nCasa de Hogwarts: %s\n", casas[indiceCasa].nome);
    printf("Descricao: %s\n", casas[indiceCasa].descricao);
    
    int escolha;
    while (1) {
        printf("\nGostaria de fazer um novo quiz?\n1-Sim\n2-Nao\n");
        scanf("%d", &escolha);
        if (escolha == 1) {
            return 1;
        } else if (escolha == 2) {
            return 0;
        } else {
            printf("Resposta invalida, tente novamente.\n");
        }
    }
}

int main() {
    // Definição das características de cada casa
    Casa casas[NUM_CASAS] = {
        {"Grifinoria", "Casa dos corajosos, valentes e destemidos.\nExistem bruxos que sao como voce, e alguns deles sao:\n-Harry Potter\n-Hermione Granger\n-Ron Weasley\n",    {5, 3, 3, 4, 3, 5, 3, 3, 2, 3}},
        {"Lufa-Lufa", "Casa dos leais, gentis e justos.\nExistem bruxos que sao como voce, e alguns deles sao:\n-Cedric Digorry\n-Ninfadora Tonks\n-Newt Scamander",             {4, 5, 2, 2, 3, 5, 3, 3, 3, 2}},
        {"Corvinal", "Casa dos sabios, inteligentes e criativos.\nExistem bruxos que sao como voce, e alguns deles sao:\n-Luna Lovegood\n-Cho Chang\n-Filius Flitwick",          {2, 3, 5, 1, 4, 4, 5, 5, 4, 3}},
        {"Sonserina", "Casa dos ambiciosos, astutos e determinados.\nExistem bruxos que sao como voce, e alguns deles sao:\n-Severus Snape\n-Draco Malfoy\n-Bellatrix Lestrange",{3, 1, 4, 5, 5, 2, 4, 4, 5, 5}}
    };

    char perguntas[NUM_PERGUNTAS][Caractere] = {
        "\nEu valorizo a coragem e bravura.",
        "Eu acredito na importancia de trabalhar duro sem esperar algo em troca.",
        "Eu me considero uma pessoa inteligente e criativa.",
        "Eu sou ambicioso e determinado para alcancar meus objetivos.",
        "Eu valorizo a astucia e sagacidade.",
        "Eu prezo pela lealdade acima de tudo.",
        "Eu me sinto atraido por desafios intelectuais.",
        "Eu gosto de aprender coisas novas constantemente.",
        "Eu priorizo o sucesso pessoal sobre o sucesso coletivo.",
        "Eu admiro a habilidade de manipular situacoes em beneficio proprio."
    };

    int respostas[NUM_PERGUNTAS], i;
    int escolha = 1;
    while (escolha == 1) {
    printf("----------------------------------------------------------------------------\n");
    printf("Bem-vindo ao Sistema de Chapeu Seletor, para descobrir sua Casa de Hogwarts!\n");
    printf("----------------------------------------------------------------------------\n");

    // Perguntas para o usuário
    printf("Responda as seguintes perguntas com um numero de 1 a 5:\n1-Discordo totalmente\n2-Discordo pouco\n3-Mais ou menos\n4-Concordo pouco\n5-Concordo totalmente.\n");
        // Loop para coletar as respostas do usuário
        for (i = 0; i < NUM_PERGUNTAS; i++) {
            printf("%s\n", perguntas[i]);
            scanf("%d", &respostas[i]);
            // Garante que a resposta esteja dentro do intervalo permitido
            if (respostas[i] < 1 || respostas[i] > 5) {
                printf("Resposta invalida! Insira um numero de 1 a 5.\n");
                i--; // Volta para a pergunta anterior
            }
        }

        // Calcula a casa do usuário
        int casaSelecionada = calcularCasa(casas, respostas);

        // Exibe a casa selecionada
        escolha = exibirCasa(casas, casaSelecionada);
        system("cls");
    }

    return 0;
}
