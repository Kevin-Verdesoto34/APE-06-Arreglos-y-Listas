import java.util.ArrayList;

public class Ejercicio8 {
    
    public static void main(String[] args) {
        System.out.println("========== COMPARACIÓN: INSERCIÓN EN ARREGLOS vs ARRAYLIST ==========\n");
        
        // Inserción en Arreglos
        insertarEnArreglos();
        
        System.out.println("\n" + "=".repeat(75) + "\n");
        
        // Inserción en ArrayList
        insertarEnArrayList();
        
        System.out.println("\n" + "=".repeat(75) + "\n");
        
        // Análisis de desempeño
        analizarDesempenio();
        
        System.out.println("\n" + "=".repeat(75) + "\n");
        
        // Comparativa detallada
        mostrarComparativaInsercion();
    }
    
    // Demostración de inserción en Arreglos
    static void insertarEnArreglos() {
        System.out.println(">>> INSERCIÓN EN ARREGLOS");
        System.out.println("-".repeat(75));
        
        // Arreglo original
        int[] original = {10, 20, 30, 40};
        System.out.println("✓ Arreglo original: ");
        mostrarArreglo(original);
        
        // Insertar al final (fácil)
        System.out.println("\n1. INSERTAR AL FINAL:");
        int[] conNuevoFinal = new int[5];
        System.arraycopy(original, 0, conNuevoFinal, 0, original.length);
        conNuevoFinal[4] = 50;
        System.out.println("   Resultado: ");
        mostrarArreglo(conNuevoFinal);
        System.out.println("   Código: System.arraycopy() y asignación manual");
        System.out.println("   Complejidad: O(n) - requiere copiar todo el arreglo");
        
        // Insertar al inicio (difícil)
        System.out.println("\n2. INSERTAR AL INICIO:");
        int[] conNuevoInicio = new int[5];
        conNuevoInicio[0] = 5;
        System.arraycopy(original, 0, conNuevoInicio, 1, original.length);
        System.out.println("   Resultado: ");
        mostrarArreglo(conNuevoInicio);
        System.out.println("   Código: Desplazamiento manual + System.arraycopy()");
        System.out.println("   Complejidad: O(n) - desplaza todos los elementos");
        
        // Insertar en el medio (muy difícil)
        System.out.println("\n3. INSERTAR EN EL MEDIO (posición 2):");
        int[] conNuevoMedio = new int[5];
        System.arraycopy(original, 0, conNuevoMedio, 0, 2);
        conNuevoMedio[2] = 25;
        System.arraycopy(original, 2, conNuevoMedio, 3, 2);
        System.out.println("   Resultado: ");
        mostrarArreglo(conNuevoMedio);
        System.out.println("   Código: Múltiples System.arraycopy() calls");
        System.out.println("   Complejidad: O(n) - desplaza elementos después de la posición");
        
        System.out.println("\n❌ Desventajas:");
        System.out.println("   • Tamaño fijo: hay que crear un nuevo arreglo");
        System.out.println("   • Código complejo: requiere múltiples operaciones");
        System.out.println("   • Propenso a errores: fácil equivocarse con índices");
        System.out.println("   • Ineficiente: copia datos constantemente");
    }
    
    // Demostración de inserción en ArrayList
    static void insertarEnArrayList() {
        System.out.println(">>> INSERCIÓN EN ARRAYLIST");
        System.out.println("-".repeat(75));
        
        // ArrayList original
        ArrayList<Integer> original = new ArrayList<>();
        original.add(10);
        original.add(20);
        original.add(30);
        original.add(40);
        System.out.println("✓ ArrayList original: " + original);
        
        // Insertar al final (fácil)
        System.out.println("\n1. INSERTAR AL FINAL:");
        ArrayList<Integer> conNuevoFinal = new ArrayList<>(original);
        conNuevoFinal.add(50);
        System.out.println("   Resultado: " + conNuevoFinal);
        System.out.println("   Código: list.add(50)");
        System.out.println("   Complejidad: O(1) amortizado - muy eficiente");
        
        // Insertar al inicio (fácil)
        System.out.println("\n2. INSERTAR AL INICIO:");
        ArrayList<Integer> conNuevoInicio = new ArrayList<>(original);
        conNuevoInicio.add(0, 5);
        System.out.println("   Resultado: " + conNuevoInicio);
        System.out.println("   Código: list.add(0, 5)");
        System.out.println("   Complejidad: O(n) - desplaza elementos internamente");
        
        // Insertar en el medio (fácil)
        System.out.println("\n3. INSERTAR EN EL MEDIO (posición 2):");
        ArrayList<Integer> conNuevoMedio = new ArrayList<>(original);
        conNuevoMedio.add(2, 25);
        System.out.println("   Resultado: " + conNuevoMedio);
        System.out.println("   Código: list.add(2, 25)");
        System.out.println("   Complejidad: O(n) - desplaza elementos después de la posición");
        
        System.out.println("\n✓ Ventajas:");
        System.out.println("   • Tamaño dinámico: redimensionamiento automático");
        System.out.println("   • Código simple: una línea para cualquier inserción");
        System.out.println("   • Seguro: ArrayList maneja la lógica interna");
        System.out.println("   • Flexible: métodos para insertar en cualquier posición");
    }
    
    // Análisis de desempeño
    static void analizarDesempenio() {
        System.out.println(">>> ANÁLISIS DE DESEMPEÑO");
        System.out.println("-".repeat(75));
        
        int[] tamaños = {100, 1000, 10000};
        
        for (int tamaño : tamaños) {
            System.out.println("\nInsertando en ArrayList con " + tamaño + " elementos:");
            
            ArrayList<Integer> list = new ArrayList<>();
            for (int i = 0; i < tamaño; i++) {
                list.add(i);
            }
            
            // Insertar al final
            long inicio = System.nanoTime();
            list.add(9999);
            long tiempoFinal = System.nanoTime() - inicio;
            
            // Insertar al inicio
            inicio = System.nanoTime();
            list.add(0, -1);
            long tiempoInicio = System.nanoTime() - inicio;
            
            // Insertar al medio
            inicio = System.nanoTime();
            list.add(tamaño / 2, 5000);
            long tiempoMedio = System.nanoTime() - inicio;
            
            System.out.printf("  • Al final: %,d ns (RÁPIDO)\n", tiempoFinal);
            System.out.printf("  • Al inicio: %,d ns (LENTO)\n", tiempoInicio);
            System.out.printf("  • Al medio: %,d ns (MEDIO)\n", tiempoMedio);
        }
        
        System.out.println("\n📊 Conclusión:");
        System.out.println("  • Insertar al final: O(1) - muy rápido ✓");
        System.out.println("  • Insertar al inicio: O(n) - lento (desplaza todos)");
        System.out.println("  • Insertar al medio: O(n) - lento (desplaza mitad)");
    }
    
    // Comparativa detallada
    static void mostrarComparativaInsercion() {
        System.out.println(">>> TABLA COMPARATIVA: INSERCIÓN");
        System.out.println("-".repeat(75));
        
        System.out.println(String.format("%-30s | %-20s | %-20s", "Operación", "Arreglo", "ArrayList"));
        System.out.println("-".repeat(75));
        
        System.out.println(String.format("%-30s | %-20s | %-20s", "Insertar al final", "Requiere nuevo array", "list.add(value)"));
        System.out.println(String.format("%-30s | %-20s | %-20s", "Código para el final", "7-8 líneas", "1 línea"));
        
        System.out.println(String.format("%-30s | %-20s | %-20s", "Insertar al inicio", "Desplazar todos", "list.add(0, value)"));
        System.out.println(String.format("%-30s | %-20s | %-20s", "Código para el inicio", "10+ líneas", "1 línea"));
        
        System.out.println(String.format("%-30s | %-20s | %-20s", "Insertar en el medio", "Desplazar parciales", "list.add(idx, value)"));
        System.out.println(String.format("%-30s | %-20s | %-20s", "Código para el medio", "Muy complejo", "1 línea"));
        
        System.out.println(String.format("%-30s | %-20s | %-20s", "Facilidad de uso", "Difícil ❌", "Fácil ✓"));
        System.out.println(String.format("%-30s | %-20s | %-20s", "Propenso a errores", "Sí ❌", "No ✓"));
        System.out.println(String.format("%-30s | %-20s | %-20s", "Redimensionamiento", "Manual", "Automático"));
        System.out.println(String.format("%-30s | %-20s | %-20s", "Complejidad de tiempo", "O(n)", "O(n)"));
        System.out.println(String.format("%-30s | %-20s | %-20s", "Complejidad espacial", "O(n)", "O(n)"));
        
        System.out.println("\n>>> EJEMPLO PRÁCTICO:");
        System.out.println("-".repeat(75));
        
        System.out.println("\nInsertar 5 en la posición 2 de [10, 20, 30, 40]:");
        
        System.out.println("\n❌ CON ARREGLO:");
        System.out.println("  int[] original = {10, 20, 30, 40};");
        System.out.println("  int[] nuevo = new int[5];");
        System.out.println("  System.arraycopy(original, 0, nuevo, 0, 2);");
        System.out.println("  nuevo[2] = 5;");
        System.out.println("  System.arraycopy(original, 2, nuevo, 3, 2);");
        System.out.println("  // Total: 5 líneas de código complejo");
        
        System.out.println("\n✓ CON ARRAYLIST:");
        System.out.println("  ArrayList<Integer> list = new ArrayList<>();");
        System.out.println("  list.addAll(Arrays.asList(10, 20, 30, 40));");
        System.out.println("  list.add(2, 5);");
        System.out.println("  // Total: 3 líneas, código claro");
        
        System.out.println("\n>>> RECOMENDACIÓN:");
        System.out.println("-".repeat(75));
        System.out.println("Use ArrayList para inserción frecuente en cualquier posición.");
        System.out.println("Use arreglos solo si el tamaño es fijo y no necesita insertar.");
    }
    
    // Método auxiliar para mostrar arreglo
    static void mostrarArreglo(int[] arr) {
        System.out.print("   [");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) System.out.print(", ");
        }
        System.out.println("]");
    }
}
