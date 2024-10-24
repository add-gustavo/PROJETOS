
import java.util.List;

public class Quiz {
    private List<Chale> chales;
    private List<Pergunta> respostasUsuario;

    public Quiz(List<Pergunta> respostasUsuario, List<Chale> chales) {
        this.respostasUsuario = respostasUsuario;
        this.chales = chales;
    }

    public List<Chale> getChales() {
        return chales;
    }

    public List<Pergunta> getRespostasUsuario() {
        return respostasUsuario;
    }

}
