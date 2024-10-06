
import java.util.Scanner;

public class View {

    public int iniciar(Scanner scan) {
        int choice;
        System.out.println("-------------------Menu-------------------");
        System.out.println("1 - Começar Quiz");
        System.out.println("2- Sair do Quiz");
        System.out.println("------------------------------------------");
        System.out.println("O que você deseja fazer?");
        choice = scan.nextInt();
        return choice;
    }

    public void exibirmensagem(String mensagem) {
        System.out.println(mensagem);
    }

    public void mostrarOpções() {
        System.out.println("Responda as seguintes perguntas com um numero de 1 a 5:");
        System.out.println("1-Discordo totalmente");
        System.out.println("2-Discordo pouco");
        System.out.println("3-Mais ou menos");
        System.out.println("4-Concordo pouco");
        System.out.println("5-Concordo totalmente");
    }

    public void showPergunta(Pergunta pergunta) {

        System.out.println(pergunta.getPergunta());
    }

    public int pegarResposta(Scanner scan) {
        int resposta = scan.nextInt();
        return resposta;
    }

    public void showResultados(Chale chale) {
        System.out.println("Pai/Mãe: " + chale.getDeus() + " -  Descrição: "
                + chale.getDescricao() + " - " + chale.getResultado());
    }
}
