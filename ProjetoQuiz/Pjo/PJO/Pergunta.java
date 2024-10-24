
public class Pergunta {
    String pergunta;
    int resposta;

    public Pergunta(String pergunta, int resposta) {
        this.pergunta = pergunta;
        this.resposta = resposta;
    }

    public Pergunta(String pergunta) {
        this.pergunta = pergunta;
    }

    public String getPergunta() {
        return pergunta;
    }

    public int getResposta() {
        return resposta;
    }

    public void setResposta(int resposta) {
        this.resposta = resposta;
    }

}
