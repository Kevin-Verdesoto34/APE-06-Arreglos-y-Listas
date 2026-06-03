import java.util.ArrayList;

public class Ejercicio7 {
    
    public static void main(String[] args) {
        System.out.println("========== COMPARACIÓN: ARREGLOS vs ARRAYLIST ==========\n");
        
        // Demostración de Arreglos
        demostrarArreglos();
        
        System.out.println("\n" + "=".repeat(60) + "\n");
        
        // Demostración de ArrayList
        demostrarArrayList();
        
        System.out.println("\n" + "=".repeat(60) + "\n");
        
        // Tabla comparativa
        mostrarComparativa();
    }
    
    // Demostración de Arreglos
    static void demostrarArreglos() {
        System.out.println(">>> ARREGLOS (Arrays)");
        System.out.println("-".repeat(60));
        
        // Crear un arreglo de tamaño fijo
        int[] numeros = new int[5];
        System.out.println("✓ Arreglo creado con tamaño fijo: 5");
        
        // Llenar el arreglo
        for (int i = 0; i < numeros.length; i++) {
            numeros[i] = (i + 1) * 10;
        }
        System.out.println("\n✓ Contenido del arreglo:");
        for (int i = 0; i < numeros.length; i++) {
            System.out.println("  numeros[" + i + "] = " + numeros[i]);
        }
        
        // Características de los arreglos
        System.out.println("\nCaracterísticas:");
        System.out.println("  • Tamaño: " + numeros.length + " (fijo)");
        System.out.println("  • Tipo: int[]");
        System.out.println("  • Acceso por índice: ✓ Rápido O(1)");
        System.out.println("  • Insertar/eliminar elementos: ✗ Difícil");
        System.out.println("  • Redimensionamiento: ✗ No automático");
        
        // Intentar agregar un elemento (no es posible directamente)
        System.out.println("\n❌ Limitación: No se pueden agregar elementos más allá del tamaño fijo.");
        System.out.println("   El arreglo tiene tamaño 5, no se puede agregar un sexto elemento.");
    }
    
    // Demostración de ArrayList
    static void demostrarArrayList() {
        System.out.println(">>> ARRAYLIST");
        System.out.println("-".repeat(60));
        
        // Crear un ArrayList dinámico
        ArrayList<Integer> numeros = new ArrayList<>();
        System.out.println("✓ ArrayList creado sin tamaño fijo (dinámico)");
        
        // Agregar elementos
        for (int i = 1; i <= 5; i++) {
            numeros.add(i * 10);
        }
        System.out.println("\n✓ Se agregaron 5 elementos:");
        for (int i = 0; i < numeros.size(); i++) {
            System.out.println("  numeros.get(" + i + ") = " + numeros.get(i));
        }
        
        // Agregar más elementos (se redimensiona automáticamente)
        numeros.add(60);
        numeros.add(70);
        System.out.println("\n✓ Se agregaron 2 elementos más (redimensionamiento automático):");
        System.out.println("  Tamaño actual: " + numeros.size());
        System.out.println("  Contenido: " + numeros);
        
        // Eliminar un elemento
        Integer eliminado = numeros.remove(2);
        System.out.println("\n✓ Se eliminó el elemento en índice 2 (valor: " + eliminado + ")");
        System.out.println("  Tamaño actual: " + numeros.size());
        System.out.println("  Contenido: " + numeros);
        
        // Características de ArrayList
        System.out.println("\nCaracterísticas:");
        System.out.println("  • Tamaño: " + numeros.size() + " (dinámico)");
        System.out.println("  • Tipo: ArrayList<Integer>");
        System.out.println("  • Acceso por índice: ✓ O(1)");
        System.out.println("  • Insertar/eliminar elementos: ✓ Fácil");
        System.out.println("  • Redimensionamiento: ✓ Automático");
        System.out.println("  • Type-safe: ✓ Generics <T>");
    }
    
    // Mostrar comparativa
    static void mostrarComparativa() {
        System.out.println(">>> TABLA COMPARATIVA");
        System.out.println("-".repeat(60));
        
        System.out.println(String.format("%-25s | %-20s | %-20s", "Característica", "Arreglo", "ArrayList"));
        System.out.println("-".repeat(60));
        
        System.out.println(String.format("%-25s | %-20s | %-20s", "Tamaño", "Fijo", "Dinámico"));
        System.out.println(String.format("%-25s | %-20s | %-20s", "Redimensionamiento", "Manual", "Automático"));
        System.out.println(String.format("%-25s | %-20s | %-20s", "Agregar elemento", "Difícil", "Fácil (.add())"));
        System.out.println(String.format("%-25s | %-20s | %-20s", "Eliminar elemento", "Difícil", "Fácil (.remove())"));
        System.out.println(String.format("%-25s | %-20s | %-20s", "Acceso por índice", "Rápido", "Rápido"));
        System.out.println(String.format("%-25s | %-20s | %-20s", "Tipos de datos", "Un tipo", "Type-safe"));
        System.out.println(String.format("%-25s | %-20s | %-20s", "Búsqueda (.indexOf)", "No", "Sí"));
        System.out.println(String.format("%-25s | %-20s | %-20s", "Ordenamiento", "Manual", "Collections.sort()"));
        System.out.println(String.format("%-25s | %-20s | %-20s", "Memoria", "Exacta", "Un poco más"));
        System.out.println(String.format("%-25s | %-20s | %-20s", "Rendimiento", "Muy rápido", "Rápido"));
        
        System.out.println("\n>>> CUÁNDO USAR CADA UNO:");
        System.out.println("-".repeat(60));
        System.out.println("Use ARREGLOS cuando:");
        System.out.println("  • El tamaño es fijo y conocido");
        System.out.println("  • Necesita máximo rendimiento");
        System.out.println("  • Está trabajando con tipos primitivos (int[], double[], etc.)");
        System.out.println("  • Los elementos no cambian después de la creación");
        
        System.out.println("\nUse ARRAYLIST cuando:");
        System.out.println("  • El tamaño es variable");
        System.out.println("  • Necesita agregar/eliminar elementos frecuentemente");
        System.out.println("  • Necesita type-safety con Generics");
        System.out.println("  • Necesita métodos como contains(), indexOf(), sort()");
        System.out.println("  • Prefiere trabajar con objetos");
        
        System.out.println("\n>>> EJEMPLOS DE CÓDIGO:");
        System.out.println("-".repeat(60));
        
        System.out.println("ARREGLO:");
        System.out.println("  int[] arr = new int[5];");
        System.out.println("  arr[0] = 10;");
        System.out.println("  System.out.println(arr.length); // 5");
        
        System.out.println("\nARRAYLIST:");
        System.out.println("  ArrayList<Integer> list = new ArrayList<>();");
        System.out.println("  list.add(10);");
        System.out.println("  System.out.println(list.size()); // 1");
        System.out.println("  list.add(20);");
        System.out.println("  System.out.println(list.size()); // 2");
    }
}
