import java.util.Scanner;

public class Controle {

    public void getresultados(Scanner scan, View view, ListaRespostas listasUsuario) {
        for (Pergunta pergunta : listasUsuario.getRespostas()) {
            view.mostrarOpções();
            view.showPergunta(pergunta);
            pergunta.setResposta(view.pegarResposta(scan));

        }
    }

    public void calcularChale(Quiz quiz) {
        for (Chale chale : quiz.getChales()) {
            int soma = 0;
            for (int i = 0; i < chale.getRespostas().size(); i++) {
                soma += Math.abs(
                        quiz.getRespostasUsuario().get(i).getResposta() - chale.getRespostas().get(i).getResposta());
            }
            chale.setResultado(soma);
        }
        ordenarChale(quiz);
    }

    public void ordenarChale(Quiz quiz) {
        for (int i = 0; i < quiz.getChales().size() - 1; i++) {
            for (int j = i; j < quiz.getChales().size(); j++) {
                if (quiz.getChales().get(i).getResultado() > quiz.getChales().get(j).getResultado()) {
                    Chale aux = quiz.getChales().get(i);
                    quiz.getChales().set(i, quiz.getChales().get(j));
                    quiz.getChales().set(j, aux);
                }
            }
        }

    }

    public void showResultados(Quiz quiz, View view) {
        for (Chale chale : quiz.getChales()) {
            view.showResultados(chale);
        }
    }

}
