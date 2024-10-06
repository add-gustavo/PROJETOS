
import java.util.ArrayList;

public class ControlPerguntaChale {
    private ModeloPerguntaChale modelochale;
    private ModeloChale chales;

    public ControlPerguntaChale(ModeloPerguntaChale modelo, ModeloChale chales) {
        this.modelochale = modelo;
        this.chales = chales;
    }

    public void calcularChale(ArrayList<Pergunta> perguntausuario) {
        for (PerguntaChale modelo : modelochale.listmodelos()) {
            getPergunta(modelo, perguntausuario);
        }
        ControlChale controlchales = new ControlChale(chales);
        controlchales.ordenarChale();

    }

    public void getPergunta(PerguntaChale modelochale, ArrayList<Pergunta> perguntausuario) {

        ModeloPergunta modelo = modelochale.getModelochale();
        ArrayList<Pergunta> perguntachale = modelo.listPergunta();

        int soma = 0;
        for (int i = 0; i < perguntachale.size(); i++) {
            soma += Math.abs(perguntausuario.get(i).getResposta() - perguntachale.get(i).getResposta());
        }
        modelochale.getChale().setResultado(soma);
    }

}
