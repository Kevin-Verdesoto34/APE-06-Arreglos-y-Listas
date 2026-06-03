import java.util.ArrayList;

public class Ejercicio2 {
    public static void main(String[] args) {
        // Crear un ArrayList de Double con 6 notas
        ArrayList<Double> notas = new ArrayList<>();
        
        // Agregar 6 notas al ArrayList
        notas.add(85.5);
        notas.add(92.0);
        notas.add(78.3);
        notas.add(88.7);
        notas.add(95.2);
        notas.add(81.0);
        
        // Mostrar las notas
        System.out.println("Lista de notas:");
        for (int i = 0; i < notas.size(); i++) {
            System.out.println("Nota " + (i + 1) + ": " + notas.get(i));
        }
        
        // Calcular el promedio
        double suma = 0;
        for (Double nota : notas) {
            suma += nota;
        }
        double promedio = suma / notas.size();
        
        System.out.println("\nTotal de notas: " + notas.size());
        System.out.println("Suma total: " + suma);
        System.out.println("Promedio: " + promedio);
    }
}
