import java.util.ArrayList;
import java.util.List;

public class ListaRespostas {
    private List<Pergunta> respostas;

    public ListaRespostas(List<Pergunta> respostasChales) {
        this.respostas = respostasChales;
    }

    public ListaRespostas() {
        this.respostas = new ArrayList<>();
    }

    public void adicionarPergunta(Pergunta pergunta) {
        respostas.add(pergunta);
    }

    public List<Pergunta> getRespostas() {
        return respostas;
    }

    public void setRespostas(List<Pergunta> respostas) {
        this.respostas = respostas;
    }
}
