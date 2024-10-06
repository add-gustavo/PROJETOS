
public class Chale {
    private String deus;
    private String descricao;
    private int resultado;

    public Chale(String deus, String descricao, int resultado) {
        this.deus = deus;
        this.descricao = descricao;
        this.resultado = resultado;
    }

    public String getDeus() {
        return deus;
    }

    public void setDeus(String deus) {
        this.deus = deus;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public int getResultado() {
        return resultado;
    }

    public void setResultado(int resultado) {
        this.resultado = resultado;
    }
}