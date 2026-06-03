import java.util.LinkedList;
import java.util.Scanner;
import java.time.LocalTime;
import java.time.temporal.ChronoUnit;

public class Ejercicio10 {
    
    // Clase interna para representar una Persona en la fila
    static class Persona {
        static int contador = 0;
        int id;
        String nombre;
        String motivo;
        LocalTime horaLlegada;
        int prioridad; // 1: Alta, 2: Normal, 3: Baja
        
        Persona(String nombre, String motivo, int prioridad) {
            this.id = ++contador;
            this.nombre = nombre;
            this.motivo = motivo;
            this.prioridad = prioridad;
            this.horaLlegada = LocalTime.now();
        }
        
        long getTiempoEspera() {
            return ChronoUnit.MINUTES.between(horaLlegada, LocalTime.now());
        }
        
        String getPrioridadTexto() {
            switch (prioridad) {
                case 1: return "🔴 ALTA";
                case 2: return "🟡 NORMAL";
                case 3: return "🟢 BAJA";
                default: return "DESCONOCIDA";
            }
        }
        
        public String toString() {
            return "ID: #" + id + " | Nombre: " + nombre + " | Motivo: " + motivo + 
                   " | Prioridad: " + getPrioridadTexto() + " | Tiempo espera: " + getTiempoEspera() + " min";
        }
    }
    
    static LinkedList<Persona> fila = new LinkedList<>();
    static LinkedList<Persona> atendidas = new LinkedList<>();
    static Scanner scanner = new Scanner(System.in);
    static int personasAtendidas = 0;
    
    public static void main(String[] args) {
        int opcion;
        
        // Agregar algunas personas de ejemplo
        fila.addLast(new Persona("Ana Martínez", "Consulta", 2));
        fila.addLast(new Persona("Carlos López", "Trámite", 3));
        fila.addLast(new Persona("Rosa García", "Urgencia", 1));
        
        do {
            mostrarMenu();
            System.out.print("Selecciona una opción: ");
            opcion = scanner.nextInt();
            scanner.nextLine();
            
            switch (opcion) {
                case 1:
                    agregarPersona();
                    break;
                case 2:
                    verFila();
                    break;
                case 3:
                    atenderPersona();
                    break;
                case 4:
                    verEstadisticas();
                    break;
                case 5:
                    simularAtencion();
                    break;
                case 6:
                    verPersonasAtendidas();
                    break;
                case 7:
                    System.out.println("\n¡Gracias por usar el sistema!");
                    break;
                default:
                    System.out.println("\n❌ Opción inválida.\n");
            }
        } while (opcion != 7);
        
        scanner.close();
    }
    
    static void mostrarMenu() {
        System.out.println("\n========== SISTEMA DE FILA DE ATENCIÓN ==========");
        System.out.println("1. Agregar persona a la fila");
        System.out.println("2. Ver fila de espera");
        System.out.println("3. Atender siguiente persona");
        System.out.println("4. Ver estadísticas");
        System.out.println("5. Simular atención rápida (5 personas)");
        System.out.println("6. Ver personas ya atendidas");
        System.out.println("7. SALIR");
        System.out.println("================================================");
    }
    
    // Agregar una persona a la fila
    static void agregarPersona() {
        System.out.print("\nIngresa el nombre: ");
        String nombre = scanner.nextLine();
        
        System.out.print("Ingresa el motivo: ");
        String motivo = scanner.nextLine();
        
        System.out.println("\nNivel de prioridad:");
        System.out.println("  1 - Urgencia (Prioridad ALTA)");
        System.out.println("  2 - Normal (Prioridad NORMAL)");
        System.out.println("  3 - Consulta (Prioridad BAJA)");
        System.out.print("Selecciona (1-3): ");
        int prioridad = scanner.nextInt();
        scanner.nextLine();
        
        if (prioridad < 1 || prioridad > 3) {
            System.out.println("❌ Prioridad inválida. Se asignó NORMAL.");
            prioridad = 2;
        }
        
        Persona nueva = new Persona(nombre, motivo, prioridad);
        
        // Insertar respetando prioridades
        if (prioridad == 1) {
            // Alta prioridad: ir al principio de otras altas
            int posicion = 0;
            for (int i = 0; i < fila.size(); i++) {
                if (fila.get(i).prioridad < 1) break;
                posicion = i + 1;
            }
            fila.add(posicion, nueva);
        } else {
            // Normal o baja: ir al final
            fila.addLast(nueva);
        }
        
        System.out.println("✓ " + nombre + " agregado a la fila.");
        System.out.println("  Posición en la fila: #" + (obtenerPosicion(nueva) + 1));
    }
    
    // Ver fila de espera
    static void verFila() {
        if (fila.isEmpty()) {
            System.out.println("\n✓ La fila está vacía. No hay personas esperando.");
            return;
        }
        
        System.out.println("\n========== FILA DE ESPERA ==========");
        System.out.println("Total personas en fila: " + fila.size() + "\n");
        
        for (int i = 0; i < fila.size(); i++) {
            String marca = (i == 0) ? "👤 [ATENDIENDO] " : "  [" + (i + 1) + "] ";
            System.out.println(marca + fila.get(i));
        }
    }
    
    // Atender a la siguiente persona
    static void atenderPersona() {
        if (fila.isEmpty()) {
            System.out.println("\n✓ No hay personas en la fila.");
            return;
        }
        
        Persona persona = fila.removeFirst();
        long tiempoEspera = persona.getTiempoEspera();
        personasAtendidas++;
        
        System.out.println("\n========== ATENDIENDO ==========");
        System.out.println("✓ " + persona.nombre);
        System.out.println("  ID: #" + persona.id);
        System.out.println("  Motivo: " + persona.motivo);
        System.out.println("  Prioridad: " + persona.getPrioridadTexto());
        System.out.println("  Tiempo de espera: " + tiempoEspera + " minutos");
        
        System.out.print("\n¿Cuánto tiempo tardará la atención? (segundos): ");
        int segundos = scanner.nextInt();
        scanner.nextLine();
        
        System.out.println("⏳ Atendiendo a " + persona.nombre + "...");
        
        // Simular tiempo de atención
        try {
            Thread.sleep(Math.min(segundos * 100, 3000)); // Máximo 3 segundos
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        persona.getTiempoEspera(); // Actualizar tiempo
        atendidas.addLast(persona);
        System.out.println("✓ Atención completada.");
        System.out.println("  Personas en la fila: " + fila.size());
    }
    
    // Ver estadísticas
    static void verEstadisticas() {
        System.out.println("\n========== ESTADÍSTICAS ==========");
        System.out.println("Personas en fila: " + fila.size());
        System.out.println("Personas atendidas: " + personasAtendidas);
        System.out.println("Total procesadas: " + (fila.size() + personasAtendidas));
        
        if (!fila.isEmpty()) {
            System.out.println("\n✓ Próxima persona a atender:");
            System.out.println("  " + fila.getFirst());
            
            System.out.println("\n✓ Última persona en fila:");
            System.out.println("  " + fila.getLast());
            
            // Estadísticas por prioridad
            int alta = 0, normal = 0, baja = 0;
            long tiempoPromedioEspera = 0;
            
            for (Persona p : fila) {
                if (p.prioridad == 1) alta++;
                else if (p.prioridad == 2) normal++;
                else baja++;
                tiempoPromedioEspera += p.getTiempoEspera();
            }
            
            System.out.println("\n✓ Distribución por prioridad:");
            System.out.println("  🔴 Urgencia: " + alta);
            System.out.println("  🟡 Normal: " + normal);
            System.out.println("  🟢 Baja: " + baja);
            
            if (fila.size() > 0) {
                System.out.printf("  Tiempo promedio espera: %.1f min\n", 
                    (double) tiempoPromedioEspera / fila.size());
            }
        }
    }
    
    // Simular atención rápida
    static void simularAtencion() {
        if (fila.isEmpty()) {
            System.out.println("\n✓ No hay personas en la fila para atender.");
            return;
        }
        
        int atender = Math.min(5, fila.size());
        System.out.println("\n⏳ Simulando atención a " + atender + " personas...\n");
        
        for (int i = 0; i < atender; i++) {
            if (!fila.isEmpty()) {
                Persona persona = fila.removeFirst();
                atendidas.addLast(persona);
                personasAtendidas++;
                System.out.println((i + 1) + ". ✓ " + persona.nombre + " - Atendido");
                
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
        
        System.out.println("\n✓ Simulación completada.");
        System.out.println("Personas en fila: " + fila.size());
        System.out.println("Personas atendidas: " + personasAtendidas);
    }
    
    // Ver personas ya atendidas
    static void verPersonasAtendidas() {
        if (atendidas.isEmpty()) {
            System.out.println("\n✓ No hay personas atendidas aún.");
            return;
        }
        
        System.out.println("\n========== PERSONAS ATENDIDAS ==========");
        System.out.println("Total: " + atendidas.size() + "\n");
        
        for (int i = 0; i < atendidas.size(); i++) {
            System.out.println((i + 1) + ". " + atendidas.get(i));
        }
    }
    
    // Método auxiliar para obtener posición de una persona
    static int obtenerPosicion(Persona persona) {
        for (int i = 0; i < fila.size(); i++) {
            if (fila.get(i).id == persona.id) {
                return i;
            }
        }
        return -1;
    }
}
