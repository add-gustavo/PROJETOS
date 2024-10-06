
import java.util.ArrayList;

public class ModeloPerguntaChale {
    private ArrayList<PerguntaChale> modelos;

    public ModeloPerguntaChale() {
        modelos = new ArrayList<>();
    }

    public void addModelo(PerguntaChale modelo) {
        modelos.add(modelo);
    }

    public ArrayList<PerguntaChale> listmodelos() {
        return modelos;
    }
}
