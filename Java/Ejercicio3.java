import java.util.ArrayList;

public class Ejercicio3 {
    public static void main(String[] args) {
        // Crear un ArrayList de String para almacenar productos
        ArrayList<String> productos = new ArrayList<>();
        
        // Agregar productos al ArrayList
        productos.add("Laptop");
        productos.add("Mouse");
        productos.add("Teclado");
        productos.add("Monitor");
        productos.add("Headphones");
        productos.add("Cable USB");
        
        // Mostrar todos los productos
        System.out.println("=== LISTA DE PRODUCTOS ===");
        for (int i = 0; i < productos.size(); i++) {
            System.out.println((i + 1) + ". " + productos.get(i));
        }
        
        // Búsquedas de productos
        System.out.println("\n=== BÚSQUEDAS ===");
        
        // Buscar un producto específico
        String buscar1 = "Teclado";
        if (productos.contains(buscar1)) {
            int indice = productos.indexOf(buscar1);
            System.out.println("✓ '" + buscar1 + "' encontrado en posición " + (indice + 1));
        } else {
            System.out.println("✗ '" + buscar1 + "' no encontrado");
        }
        
        // Buscar otro producto
        String buscar2 = "Impresora";
        if (productos.contains(buscar2)) {
            int indice = productos.indexOf(buscar2);
            System.out.println("✓ '" + buscar2 + "' encontrado en posición " + (indice + 1));
        } else {
            System.out.println("✗ '" + buscar2 + "' no encontrado");
        }
        
        // Buscar por patrón (productos que contengan una palabra)
        System.out.println("\n=== BÚSQUEDA POR PATRÓN ===");
        String patron = "o";
        System.out.println("Productos que contienen '" + patron + "':");
        for (String producto : productos) {
            if (producto.toLowerCase().contains(patron.toLowerCase())) {
                System.out.println("- " + producto);
            }
        }
        
        // Información general
        System.out.println("\n=== INFORMACIÓN ===");
        System.out.println("Total de productos registrados: " + productos.size());
    }
}
