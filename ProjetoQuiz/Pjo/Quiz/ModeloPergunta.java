
import java.util.ArrayList;

public class ModeloPergunta {
    private ArrayList<Pergunta> perguntas;

    public ModeloPergunta() {
        perguntas = new ArrayList<>();
    }

    public void addPergunta(Pergunta pergunta) {
        perguntas.add(pergunta);
    }

    public ArrayList<Pergunta> listPergunta() {
        return perguntas;
    }
}
