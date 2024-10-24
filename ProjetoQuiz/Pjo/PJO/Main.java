import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        List<Chale> chales = new ArrayList<>();
        List<Pergunta> perguntasZeus = new ArrayList<>();
        perguntasZeus.add(new Pergunta("Zeus é o deus do trovão?"));
        chales.add(new Chale("Zeus", "Deus do trovão", perguntasZeus));

        Scanner scan = new Scanner(System.in);
        Controle controle = new Controle();
        View view = new View();

        int choice;
        do {
            ListaRespostas usuario = new ListaRespostas();
            choice = view.iniciar(scan);
            switch (choice) {
                case 1:
                    controle.getresultados(scan, view, usuario);
                    Quiz quiz = new Quiz(usuario.getRespostas(), chales);
                    controle.calcularChale(quiz);
                    controle.showResultados(quiz, view);

                    break;
                case 2:
                    break;
                default:
                    view.exibirmensagem("Erro! não existe opção");
                    break;
            }
        } while (choice != 2);
        scan.close();
    }
}