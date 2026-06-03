import java.util.ArrayList;
import java.util.Scanner;

public class Ejercicio5 {
    
    // Clase interna para representar un Estudiante
    static class Estudiante {
        String nombre;
        double nota;
        
        Estudiante(String nombre, double nota) {
            this.nombre = nombre;
            this.nota = nota;
        }
        
        public String toString() {
            return nombre + " - Nota: " + nota;
        }
    }
    
    static ArrayList<Estudiante> estudiantes = new ArrayList<>();
    static Scanner scanner = new Scanner(System.in);
    
    public static void main(String[] args) {
        int opcion;
        
        // Agregar algunos estudiantes de ejemplo
        estudiantes.add(new Estudiante("Juan Pérez", 85.5));
        estudiantes.add(new Estudiante("María García", 92.0));
        estudiantes.add(new Estudiante("Carlos López", 78.3));
        
        do {
            mostrarMenu();
            System.out.print("Selecciona una opción: ");
            opcion = scanner.nextInt();
            scanner.nextLine();
            
            switch (opcion) {
                case 1:
                    registrarEstudiante();
                    break;
                case 2:
                    verTodos();
                    break;
                case 3:
                    buscarEstudiante();
                    break;
                case 4:
                    calcularPromedio();
                    break;
                case 5:
                    verEstadisticas();
                    break;
                case 6:
                    System.out.println("\n¡Hasta luego!");
                    break;
                default:
                    System.out.println("\n❌ Opción inválida.\n");
            }
        } while (opcion != 6);
        
        scanner.close();
    }
    
    static void mostrarMenu() {
        System.out.println("\n========== REGISTRAR ESTUDIANTES Y NOTAS ==========");
        System.out.println("1. Registrar nuevo estudiante");
        System.out.println("2. Ver todos los estudiantes");
        System.out.println("3. Buscar estudiante por nombre");
        System.out.println("4. Calcular promedio de notas");
        System.out.println("5. Ver estadísticas");
        System.out.println("6. SALIR");
        System.out.println("==================================================");
    }
    
    // Registrar un nuevo estudiante
    static void registrarEstudiante() {
        System.out.print("\nIngresa el nombre del estudiante: ");
        String nombre = scanner.nextLine();
        
        System.out.print("Ingresa la nota del estudiante: ");
        double nota = scanner.nextDouble();
        scanner.nextLine();
        
        if (nota >= 0 && nota <= 100) {
            estudiantes.add(new Estudiante(nombre, nota));
            System.out.println("✓ Estudiante '" + nombre + "' registrado con nota " + nota);
        } else {
            System.out.println("❌ La nota debe estar entre 0 y 100.");
        }
    }
    
    // Ver todos los estudiantes
    static void verTodos() {
        if (estudiantes.isEmpty()) {
            System.out.println("\n⚠️  No hay estudiantes registrados.");
            return;
        }
        
        System.out.println("\n========== LISTA DE ESTUDIANTES ==========");
        for (int i = 0; i < estudiantes.size(); i++) {
            System.out.println((i + 1) + ". " + estudiantes.get(i));
        }
        System.out.println("Total de estudiantes: " + estudiantes.size());
    }
    
    // Buscar un estudiante por nombre
    static void buscarEstudiante() {
        if (estudiantes.isEmpty()) {
            System.out.println("\n⚠️  No hay estudiantes para buscar.");
            return;
        }
        
        System.out.print("\nIngresa el nombre a buscar: ");
        String nombre = scanner.nextLine();
        
        System.out.println("\n========== RESULTADOS DE BÚSQUEDA ==========");
        boolean encontrado = false;
        for (Estudiante est : estudiantes) {
            if (est.nombre.toLowerCase().contains(nombre.toLowerCase())) {
                System.out.println("✓ " + est);
                encontrado = true;
            }
        }
        
        if (!encontrado) {
            System.out.println("❌ No se encontraron estudiantes con ese nombre.");
        }
    }
    
    // Calcular el promedio de notas
    static void calcularPromedio() {
        if (estudiantes.isEmpty()) {
            System.out.println("\n⚠️  No hay estudiantes para calcular promedio.");
            return;
        }
        
        double suma = 0;
        for (Estudiante est : estudiantes) {
            suma += est.nota;
        }
        
        double promedio = suma / estudiantes.size();
        System.out.println("\n========== PROMEDIO DE NOTAS ==========");
        System.out.println("Suma total: " + suma);
        System.out.println("Cantidad de estudiantes: " + estudiantes.size());
        System.out.printf("Promedio: %.2f\n", promedio);
    }
    
    // Ver estadísticas
    static void verEstadisticas() {
        if (estudiantes.isEmpty()) {
            System.out.println("\n⚠️  No hay estudiantes para mostrar estadísticas.");
            return;
        }
        
        double notaMayor = estudiantes.get(0).nota;
        double notaMenor = estudiantes.get(0).nota;
        double suma = 0;
        String estudianteMejor = estudiantes.get(0).nombre;
        String estudiantePeor = estudiantes.get(0).nombre;
        
        for (Estudiante est : estudiantes) {
            suma += est.nota;
            if (est.nota > notaMayor) {
                notaMayor = est.nota;
                estudianteMejor = est.nombre;
            }
            if (est.nota < notaMenor) {
                notaMenor = est.nota;
                estudiantePeor = est.nombre;
            }
        }
        
        double promedio = suma / estudiantes.size();
        
        System.out.println("\n========== ESTADÍSTICAS ==========");
        System.out.printf("Promedio: %.2f\n", promedio);
        System.out.println("Nota mayor: " + notaMayor + " (" + estudianteMejor + ")");
        System.out.println("Nota menor: " + notaMenor + " (" + estudiantePeor + ")");
        System.out.println("Total de estudiantes: " + estudiantes.size());
    }
}
