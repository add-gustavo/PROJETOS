
import java.util.Scanner;

public class ControlPergunta {
    private ModeloPergunta modelousuario;
    private View view;
    private ModeloPerguntaChale modeloschales;
    private ModeloChale chales;

    public ControlPergunta(View view, ModeloPergunta modelousuario, ModeloPerguntaChale modelos, ModeloChale chales) {
        this.view = view;
        this.modelousuario = modelousuario;
        this.modeloschales = modelos;
        this.chales = chales;
    }

    public void iniciar(int choice, Scanner scan) {

        switch (choice) {
            case 1:
                getresultados(scan);
                ControlPerguntaChale analise = new ControlPerguntaChale(modeloschales, chales);
                analise.calcularChale(modelousuario.listPergunta());
                showResultados(chales);
                break;
            case 2:
                break;
            default:
                view.exibirmensagem("Erro! não existe opção");
                break;
        }
    }

    public void showResultados(ModeloChale chales) {
        for (Chale chale : chales.listChales()) {
            view.showResultados(chale);
        }
    }

    public void getresultados(Scanner scan) {
        for (Pergunta pergunta : modelousuario.listPergunta()) {
            view.mostrarOpções();
            view.showPergunta(pergunta);
            pergunta.setResposta(view.pegarResposta(scan));

        }
    }
}
