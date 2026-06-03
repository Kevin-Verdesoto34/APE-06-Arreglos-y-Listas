#include <iostream>
#include <list>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

// Clase para representar una Persona en la fila
class Persona {
public:
    static int contador;
    int id;
    string nombre;
    string motivo;
    chrono::system_clock::time_point horaLlegada;
    int prioridad; // 1: Alta, 2: Normal, 3: Baja
    
    Persona(string nombre, string motivo, int prioridad) {
        this->id = ++contador;
        this->nombre = nombre;
        this->motivo = motivo;
        this->prioridad = prioridad;
        this->horaLlegada = chrono::system_clock::now();
    }
    
    long getTiempoEspera() const {
        auto ahora = chrono::system_clock::now();
        auto duracion = chrono::duration_cast<chrono::seconds>(ahora - horaLlegada);
        return duracion.count() / 60; // Convertir a minutos
    }
    
    string getPrioridadTexto() const {
        switch (prioridad) {
            case 1: return "🔴 ALTA";
            case 2: return "🟡 NORMAL";
            case 3: return "🟢 BAJA";
            default: return "DESCONOCIDA";
        }
    }
    
    string toString() const {
        return "ID: #" + to_string(id) + " | Nombre: " + nombre + " | Motivo: " + motivo + 
               " | Prioridad: " + getPrioridadTexto() + " | Tiempo espera: " + 
               to_string(getTiempoEspera()) + " min";
    }
};

int Persona::contador = 0;

list<Persona> fila;
list<Persona> atendidas;
int personasAtendidas = 0;

void mostrarMenu() {
    cout << "\n========== SISTEMA DE FILA DE ATENCIÓN ==========" << endl;
    cout << "1. Agregar persona a la fila" << endl;
    cout << "2. Ver fila de espera" << endl;
    cout << "3. Atender siguiente persona" << endl;
    cout << "4. Ver estadísticas" << endl;
    cout << "5. Simular atención rápida (5 personas)" << endl;
    cout << "6. Ver personas ya atendidas" << endl;
    cout << "7. SALIR" << endl;
    cout << "=================================================" << endl;
}

// Agregar una persona a la fila
void agregarPersona() {
    cout << "\nIngresa el nombre: ";
    string nombre;
    getline(cin, nombre);
    
    cout << "Ingresa el motivo: ";
    string motivo;
    getline(cin, motivo);
    
    cout << "\nNivel de prioridad:" << endl;
    cout << "  1 - Urgencia (Prioridad ALTA)" << endl;
    cout << "  2 - Normal (Prioridad NORMAL)" << endl;
    cout << "  3 - Consulta (Prioridad BAJA)" << endl;
    cout << "Selecciona (1-3): ";
    int prioridad;
    cin >> prioridad;
    cin.ignore();
    
    if (prioridad < 1 || prioridad > 3) {
        cout << "❌ Prioridad inválida. Se asignó NORMAL." << endl;
        prioridad = 2;
    }
    
    Persona nueva(nombre, motivo, prioridad);
    
    // Insertar respetando prioridades
    if (prioridad == 1) {
        // Alta prioridad: ir al principio de otras altas
        auto it = fila.begin();
        for (; it != fila.end(); ++it) {
            if (it->prioridad > 1) break;
        }
        fila.insert(it, nueva);
    } else {
        // Normal o baja: ir al final
        fila.push_back(nueva);
    }
    
    cout << "✓ " << nombre << " agregado a la fila." << endl;
    
    // Obtener posición
    int posicion = 1;
    for (const auto& p : fila) {
        if (p.id == nueva.id) {
            cout << "  Posición en la fila: #" << posicion << endl;
            break;
        }
        posicion++;
    }
}

// Ver fila de espera
void verFila() {
    if (fila.empty()) {
        cout << "\n✓ La fila está vacía. No hay personas esperando." << endl;
        return;
    }
    
    cout << "\n========== FILA DE ESPERA ==========" << endl;
    cout << "Total personas en fila: " << fila.size() << "\n" << endl;
    
    int contador = 0;
    for (const Persona& p : fila) {
        string marca = (contador == 0) ? "👤 [ATENDIENDO] " : "  [" + to_string(contador + 1) + "] ";
        cout << marca << p.toString() << endl;
        contador++;
    }
}

// Atender a la siguiente persona
void atenderPersona() {
    if (fila.empty()) {
        cout << "\n✓ No hay personas en la fila." << endl;
        return;
    }
    
    Persona persona = fila.front();
    fila.pop_front();
    long tiempoEspera = persona.getTiempoEspera();
    personasAtendidas++;
    
    cout << "\n========== ATENDIENDO ==========" << endl;
    cout << "✓ " << persona.nombre << endl;
    cout << "  ID: #" << persona.id << endl;
    cout << "  Motivo: " << persona.motivo << endl;
    cout << "  Prioridad: " << persona.getPrioridadTexto() << endl;
    cout << "  Tiempo de espera: " << tiempoEspera << " minutos" << endl;
    
    cout << "\n¿Cuánto tiempo tardará la atención? (segundos): ";
    int segundos;
    cin >> segundos;
    cin.ignore();
    
    cout << "⏳ Atendiendo a " << persona.nombre << "..." << endl;
    
    // Simular tiempo de atención
    int tiempoSimulacion = min(segundos / 10, 3); // Máximo 3 segundos
    this_thread::sleep_for(chrono::milliseconds(tiempoSimulacion * 100));
    
    atendidas.push_back(persona);
    cout << "✓ Atención completada." << endl;
    cout << "  Personas en la fila: " << fila.size() << endl;
}

// Ver estadísticas
void verEstadisticas() {
    cout << "\n========== ESTADÍSTICAS ==========" << endl;
    cout << "Personas en fila: " << fila.size() << endl;
    cout << "Personas atendidas: " << personasAtendidas << endl;
    cout << "Total procesadas: " << (fila.size() + personasAtendidas) << endl;
    
    if (!fila.empty()) {
        cout << "\n✓ Próxima persona a atender:" << endl;
        cout << "  " << fila.front().toString() << endl;
        
        cout << "\n✓ Última persona en fila:" << endl;
        cout << "  " << fila.back().toString() << endl;
        
        // Estadísticas por prioridad
        int alta = 0, normal = 0, baja = 0;
        long tiempoPromedioEspera = 0;
        
        for (const Persona& p : fila) {
            if (p.prioridad == 1) alta++;
            else if (p.prioridad == 2) normal++;
            else baja++;
            tiempoPromedioEspera += p.getTiempoEspera();
        }
        
        cout << "\n✓ Distribución por prioridad:" << endl;
        cout << "  🔴 Urgencia: " << alta << endl;
        cout << "  🟡 Normal: " << normal << endl;
        cout << "  🟢 Baja: " << baja << endl;
        
        if (fila.size() > 0) {
            cout << fixed << setprecision(1) 
                 << "  Tiempo promedio espera: " 
                 << (double)tiempoPromedioEspera / fila.size() << " min" << endl;
        }
    }
}

// Simular atención rápida
void simularAtencion() {
    if (fila.empty()) {
        cout << "\n✓ No hay personas en la fila para atender." << endl;
        return;
    }
    
    int atender = min(5, (int)fila.size());
    cout << "\n⏳ Simulando atención a " << atender << " personas...\n" << endl;
    
    for (int i = 0; i < atender; i++) {
        if (!fila.empty()) {
            Persona persona = fila.front();
            fila.pop_front();
            atendidas.push_back(persona);
            personasAtendidas++;
            cout << (i + 1) << ". ✓ " << persona.nombre << " - Atendido" << endl;
            
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
    
    cout << "\n✓ Simulación completada." << endl;
    cout << "Personas en fila: " << fila.size() << endl;
    cout << "Personas atendidas: " << personasAtendidas << endl;
}

// Ver personas ya atendidas
void verPersonasAtendidas() {
    if (atendidas.empty()) {
        cout << "\n✓ No hay personas atendidas aún." << endl;
        return;
    }
    
    cout << "\n========== PERSONAS ATENDIDAS ==========" << endl;
    cout << "Total: " << atendidas.size() << "\n" << endl;
    
    int contador = 1;
    for (const Persona& p : atendidas) {
        cout << contador << ". " << p.toString() << endl;
        contador++;
    }
}

int main() {
    int opcion;
    
    // Agregar algunas personas de ejemplo
    fila.push_back(Persona("Ana Martínez", "Consulta", 2));
    fila.push_back(Persona("Carlos López", "Trámite", 3));
    fila.push_back(Persona("Rosa García", "Urgencia", 1));
    
    do {
        mostrarMenu();
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cin.ignore();
        
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
                cout << "\n¡Gracias por usar el sistema!" << endl;
                break;
            default:
                cout << "\n❌ Opción inválida.\n" << endl;
        }
    } while (opcion != 7);
    
    return 0;
}
