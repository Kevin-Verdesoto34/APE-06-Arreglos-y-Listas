import java.util.LinkedList;
import java.util.Scanner;

public class Ejercicio9 {
    
    // Clase interna para representar un Turno
    static class Turno {
        int numero;
        String cliente;
        String servicio;
        String estado; // "Esperando", "En atención", "Completado"
        
        Turno(int numero, String cliente, String servicio) {
            this.numero = numero;
            this.cliente = cliente;
            this.servicio = servicio;
            this.estado = "Esperando";
        }
        
        public String toString() {
            return "Turno #" + numero + " - Cliente: " + cliente + " | Servicio: " + servicio + " | Estado: " + estado;
        }
    }
    
    static LinkedList<Turno> turnos = new LinkedList<>();
    static Scanner scanner = new Scanner(System.in);
    static int numeroTurno = 1;
    
    public static void main(String[] args) {
        int opcion;
        
        // Agregar algunos turnos de ejemplo
        turnos.add(new Turno(numeroTurno++, "Juan García", "Depósito"));
        turnos.add(new Turno(numeroTurno++, "María López", "Retiro"));
        turnos.add(new Turno(numeroTurno++, "Carlos Pérez", "Consulta"));
        
        do {
            mostrarMenu();
            System.out.print("Selecciona una opción: ");
            opcion = scanner.nextInt();
            scanner.nextLine();
            
            switch (opcion) {
                case 1:
                    generarTurno();
                    break;
                case 2:
                    verTurnos();
                    break;
                case 3:
                    atenderTurno();
                    break;
                case 4:
                    cancelarTurno();
                    break;
                case 5:
                    verEstadisticas();
                    break;
                case 6:
                    demostrarOperacionesLinkedList();
                    break;
                case 7:
                    System.out.println("\n¡Hasta luego!");
                    break;
                default:
                    System.out.println("\n❌ Opción inválida.\n");
            }
        } while (opcion != 7);
        
        scanner.close();
    }
    
    static void mostrarMenu() {
        System.out.println("\n========== SISTEMA DE TURNOS CON LINKEDLIST ==========");
        System.out.println("1. Generar nuevo turno");
        System.out.println("2. Ver todos los turnos");
        System.out.println("3. Atender siguiente turno");
        System.out.println("4. Cancelar un turno");
        System.out.println("5. Ver estadísticas");
        System.out.println("6. Demostrar operaciones LinkedList");
        System.out.println("7. SALIR");
        System.out.println("=====================================================");
    }
    
    // Generar un nuevo turno
    static void generarTurno() {
        System.out.print("\nIngresa el nombre del cliente: ");
        String cliente = scanner.nextLine();
        
        System.out.print("Ingresa el tipo de servicio: ");
        String servicio = scanner.nextLine();
        
        Turno nuevoTurno = new Turno(numeroTurno++, cliente, servicio);
        turnos.addLast(nuevoTurno);
        System.out.println("✓ Turno generado: " + nuevoTurno);
    }
    
    // Ver todos los turnos
    static void verTurnos() {
        if (turnos.isEmpty()) {
            System.out.println("\n⚠️  No hay turnos registrados.");
            return;
        }
        
        System.out.println("\n========== COLA DE TURNOS ==========");
        for (int i = 0; i < turnos.size(); i++) {
            System.out.println((i + 1) + ". " + turnos.get(i));
        }
        System.out.println("Total de turnos en la cola: " + turnos.size());
    }
    
    // Atender siguiente turno (FIFO - First In, First Out)
    static void atenderTurno() {
        if (turnos.isEmpty()) {
            System.out.println("\n⚠️  No hay turnos para atender.");
            return;
        }
        
        Turno turnoActual = turnos.getFirst();
        turnoActual.estado = "En atención";
        System.out.println("\n✓ Atendiendo: " + turnoActual);
        
        System.out.print("¿Deseas completar este turno? (s/n): ");
        String respuesta = scanner.nextLine();
        
        if (respuesta.equalsIgnoreCase("s")) {
            turnos.removeFirst();
            turnoActual.estado = "Completado";
            System.out.println("✓ Turno completado y eliminado de la cola.");
            System.out.println("  " + turnoActual);
        } else {
            turnoActual.estado = "Esperando";
            System.out.println("✓ Turno devuelto a la cola de espera.");
        }
    }
    
    // Cancelar un turno
    static void cancelarTurno() {
        if (turnos.isEmpty()) {
            System.out.println("\n⚠️  No hay turnos para cancelar.");
            return;
        }
        
        verTurnos();
        System.out.print("\nIngresa el número del turno a cancelar: ");
        int numero = scanner.nextInt();
        scanner.nextLine();
        
        for (Turno turno : turnos) {
            if (turno.numero == numero) {
                turnos.remove(turno);
                System.out.println("✓ Turno #" + numero + " cancelado.");
                return;
            }
        }
        System.out.println("❌ Turno no encontrado.");
    }
    
    // Ver estadísticas
    static void verEstadisticas() {
        System.out.println("\n========== ESTADÍSTICAS DE TURNOS ==========");
        System.out.println("Total de turnos en cola: " + turnos.size());
        
        if (!turnos.isEmpty()) {
            System.out.println("\n✓ Primer turno (próximo a atender):");
            System.out.println("  " + turnos.getFirst());
            
            System.out.println("\n✓ Último turno registrado:");
            System.out.println("  " + turnos.getLast());
            
            int esperando = 0;
            int enAtencion = 0;
            
            for (Turno turno : turnos) {
                if (turno.estado.equals("Esperando")) esperando++;
                else if (turno.estado.equals("En atención")) enAtencion++;
            }
            
            System.out.println("\n✓ Estado de turnos:");
            System.out.println("  - Esperando: " + esperando);
            System.out.println("  - En atención: " + enAtencion);
        }
    }
    
    // Demostrar operaciones específicas de LinkedList
    static void demostrarOperacionesLinkedList() {
        System.out.println("\n========== DEMOSTRACIONES DE LINKEDLIST ==========");
        
        LinkedList<String> demo = new LinkedList<>();
        demo.add("A");
        demo.add("B");
        demo.add("C");
        
        System.out.println("✓ LinkedList inicial: " + demo);
        
        // addFirst y addLast
        System.out.println("\n1. addFirst() y addLast():");
        demo.addFirst("X");
        System.out.println("   addFirst('X'): " + demo);
        demo.addLast("Z");
        System.out.println("   addLast('Z'): " + demo);
        
        // getFirst y getLast
        System.out.println("\n2. getFirst() y getLast():");
        System.out.println("   getFirst(): " + demo.getFirst());
        System.out.println("   getLast(): " + demo.getLast());
        
        // removeFirst y removeLast
        System.out.println("\n3. removeFirst() y removeLast():");
        String primero = demo.removeFirst();
        System.out.println("   removeFirst(): Eliminó '" + primero + "'");
        System.out.println("   Estado: " + demo);
        
        String ultimo = demo.removeLast();
        System.out.println("   removeLast(): Eliminó '" + ultimo + "'");
        System.out.println("   Estado: " + demo);
        
        // Iterator (recorrido desde el principio)
        System.out.println("\n4. Recorrido con iterator:");
        System.out.print("   ");
        demo.forEach(elem -> System.out.print(elem + " "));
        System.out.println();
        
        // Descendente
        System.out.println("\n5. Recorrido descendente (descendingIterator):");
        System.out.print("   ");
        demo.descendingIterator().forEachRemaining(elem -> System.out.print(elem + " "));
        System.out.println();
        
        System.out.println("\n>>> VENTAJAS DE LINKEDLIST:");
        System.out.println("   ✓ Inserción/eliminación al principio: O(1)");
        System.out.println("   ✓ Inserción/eliminación al final: O(1)");
        System.out.println("   ✓ Ideal para colas (FIFO)");
        System.out.println("   ✓ Ideal para pilas (LIFO)");
        System.out.println("   ✓ addFirst/addLast muy eficientes");
        System.out.println("   ✓ removeFirst/removeLast muy eficientes");
        
        System.out.println("\n>>> DESVENTAJAS DE LINKEDLIST:");
        System.out.println("   ✗ Acceso por índice: O(n)");
        System.out.println("   ✗ Búsqueda: O(n)");
        System.out.println("   ✗ Usa más memoria (referencias)");
    }
}