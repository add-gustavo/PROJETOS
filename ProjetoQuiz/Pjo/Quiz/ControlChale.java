
import java.util.ArrayList;

public class ControlChale {
    private ModeloChale chales;

    public ControlChale(ModeloChale chales) {
        this.chales = chales;
    }

    public void ordenarChale() {
        ArrayList<Chale> listachales = chales.listChales();
        for (int i = 0; i < listachales.size() - 1; i++) {
            for (int j = i; j < listachales.size(); j++) {
                if (listachales.get(i).getResultado() > listachales.get(j).getResultado()) {
                    Chale aux = listachales.get(i);
                    listachales.set(i, listachales.get(j));
                    listachales.set(j, aux);
                }
            }
        }

    }
}