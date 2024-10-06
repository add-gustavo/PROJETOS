
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        ModeloPerguntaChale modeloschales = new ModeloPerguntaChale();
        View view = new View();
        int choice;
        do {
            ModeloPergunta modelousuario = new ModeloPergunta();
            ModeloChale chales = new ModeloChale();
            ControlPergunta control = new ControlPergunta(view, modelousuario, modeloschales, chales);
            choice = view.iniciar(scan);
            control.iniciar(choice, scan);
        } while (choice != 2);
        scan.close();
    }
}