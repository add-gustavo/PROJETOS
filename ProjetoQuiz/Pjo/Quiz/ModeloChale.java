
import java.util.ArrayList;

public class ModeloChale {
    private ArrayList<Chale> chales;

    public ModeloChale() {
        chales = new ArrayList<>();
    }

    public void addChale(Chale chale) {
        chales.add(chale);
    }

    public ArrayList<Chale> listChales() {
        return chales;
    }
}
