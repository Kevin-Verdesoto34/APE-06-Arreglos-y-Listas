import java.util.ArrayList;
import java.util.Scanner;

public class Ejercicio4 {
    static ArrayList<String> libros = new ArrayList<>();
    static Scanner scanner = new Scanner(System.in);
    
    public static void main(String[] args) {
        int opcion;
        
        // Agregar algunos libros de ejemplo
        libros.add("1984 de George Orwell");
        libros.add("Cien años de soledad de Gabriel García Márquez");
        libros.add("El Quijote de Miguel de Cervantes");
        
        do {
            mostrarMenu();
            System.out.print("Selecciona una opción: ");
            opcion = scanner.nextInt();
            scanner.nextLine(); // Limpiar el buffer
            
            switch (opcion) {
                case 1:
                    crear();
                    break;
                case 2:
                    leer();
                    break;
                case 3:
                    actualizar();
                    break;
                case 4:
                    eliminar();
                    break;
                case 5:
                    System.out.println("\n¡Hasta luego!");
                    break;
                default:
                    System.out.println("\n❌ Opción inválida. Intenta de nuevo.\n");
            }
        } while (opcion != 5);
        
        scanner.close();
    }
    
    static void mostrarMenu() {
        System.out.println("\n========== MENÚ CRUD ==========");
        System.out.println("1. CREATE - Agregar nuevo libro");
        System.out.println("2. READ   - Ver todos los libros");
        System.out.println("3. UPDATE - Actualizar un libro");
        System.out.println("4. DELETE - Eliminar un libro");
        System.out.println("5. SALIR");
        System.out.println("===============================");
    }
    
    // CREATE - Agregar un nuevo libro
    static void crear() {
        System.out.print("\nIngresa el nombre del libro: ");
        String libro = scanner.nextLine();
        
        if (libros.add(libro)) {
            System.out.println("✓ Libro '" + libro + "' agregado correctamente.");
        } else {
            System.out.println("❌ Error al agregar el libro.");
        }
    }
    
    // READ - Ver todos los libros
    static void leer() {
        if (libros.isEmpty()) {
            System.out.println("\n⚠️  No hay libros registrados.");
            return;
        }
        
        System.out.println("\n========== LISTA DE LIBROS ==========");
        for (int i = 0; i < libros.size(); i++) {
            System.out.println((i + 1) + ". " + libros.get(i));
        }
        System.out.println("Total de libros: " + libros.size());
    }
    
    // UPDATE - Actualizar un libro
    static void actualizar() {
        if (libros.isEmpty()) {
            System.out.println("\n⚠️  No hay libros para actualizar.");
            return;
        }
        
        leer();
        System.out.print("\nIngresa el número del libro a actualizar: ");
        int indice = scanner.nextInt();
        scanner.nextLine();
        
        if (indice > 0 && indice <= libros.size()) {
            System.out.print("Ingresa el nuevo nombre del libro: ");
            String nuevoLibro = scanner.nextLine();
            String libroAntiguo = libros.set(indice - 1, nuevoLibro);
            System.out.println("✓ Libro actualizado: '" + libroAntiguo + "' → '" + nuevoLibro + "'");
        } else {
            System.out.println("❌ Número de libro inválido.");
        }
    }
    
    // DELETE - Eliminar un libro
    static void eliminar() {
        if (libros.isEmpty()) {
            System.out.println("\n⚠️  No hay libros para eliminar.");
            return;
        }
        
        leer();
        System.out.print("\nIngresa el número del libro a eliminar: ");
        int indice = scanner.nextInt();
        scanner.nextLine();
        
        if (indice > 0 && indice <= libros.size()) {
            String libroEliminado = libros.remove(indice - 1);
            System.out.println("✓ Libro '" + libroEliminado + "' eliminado correctamente.");
        } else {
            System.out.println("❌ Número de libro inválido.");
        }
    }
}
