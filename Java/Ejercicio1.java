import java.util.ArrayList;

public class Ejercicio1 {
    public static void main(String[] args) {
        // Crear un ArrayList de String con 5 nombres de estudiantes
        ArrayList<String> estudiantes = new ArrayList<>();
        
        // Agregar 5 nombres de estudiantes al ArrayList
        estudiantes.add("Juan");
        estudiantes.add("María");
        estudiantes.add("Carlos");
        estudiantes.add("Ana");
        estudiantes.add("Luis");
        
        // Mostrar los estudiantes en el ArrayList
        System.out.println("Lista de estudiantes:");
        for (String estudiante : estudiantes) {
            System.out.println("- " + estudiante);
        }
        
        // Mostrar la cantidad de estudiantes
        System.out.println("\nTotal de estudiantes: " + estudiantes.size());
    }
}
