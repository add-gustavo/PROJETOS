
import java.util.List;

public class Chale {
    private String deus;
    private String descricao;
    private List<Pergunta> respostas;
    private int resultado;

    public Chale(String deus, String descricao, List<Pergunta> respostas) {
        this.deus = deus;
        this.descricao = descricao;
        this.respostas = respostas;
    }

    public String getDeus() {
        return deus;
    }

    public String getDescricao() {
        return descricao;
    }

    public int getResultado() {
        return resultado;
    }

    public void setResultado(int resultado) {
        this.resultado = resultado;
    }

    public List<Pergunta> getRespostas() {
        return respostas;
    }
}