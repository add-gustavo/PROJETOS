
public class PerguntaChale {
    private ModeloPergunta modelochale;
    private Chale chale;

    public PerguntaChale(ModeloPergunta modelochale, Chale chale) {
        this.modelochale = modelochale;
        this.chale = chale;
    }

    public Chale getChale() {
        return chale;
    }

    public void setChale(Chale chale) {
        this.chale = chale;
    }

    public ModeloPergunta getModelochale() {
        return modelochale;
    }

    public void setModelochale(ModeloPergunta modelochale) {
        this.modelochale = modelochale;
    }
}
