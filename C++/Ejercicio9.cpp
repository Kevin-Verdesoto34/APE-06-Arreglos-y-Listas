#include <iostream>
#include <list>
#include <string>

using namespace std;

// Clase para representar un Turno
class Turno {
public:
    int numero;
    string cliente;
    string servicio;
    string estado; // "Esperando", "En atención", "Completado"
    
    Turno(int numero, string cliente, string servicio) {
        this->numero = numero;
        this->cliente = cliente;
        this->servicio = servicio;
        this->estado = "Esperando";
    }
    
    string toString() const {
        return "Turno #" + to_string(numero) + " - Cliente: " + cliente + 
               " | Servicio: " + servicio + " | Estado: " + estado;
    }
};

list<Turno> turnos;
int numeroTurno = 1;

void mostrarMenu() {
    cout << "\n========== SISTEMA DE TURNOS CON LIST ==========" << endl;
    cout << "1. Generar nuevo turno" << endl;
    cout << "2. Ver todos los turnos" << endl;
    cout << "3. Atender siguiente turno" << endl;
    cout << "4. Cancelar un turno" << endl;
    cout << "5. Ver estadísticas" << endl;
    cout << "6. Demostrar operaciones de list" << endl;
    cout << "7. SALIR" << endl;
    cout << "===============================================" << endl;
}

// Generar un nuevo turno
void generarTurno() {
    cout << "\nIngresa el nombre del cliente: ";
    string cliente;
    getline(cin, cliente);
    
    cout << "Ingresa el tipo de servicio: ";
    string servicio;
    getline(cin, servicio);
    
    Turno nuevoTurno(numeroTurno++, cliente, servicio);
    turnos.push_back(nuevoTurno);
    cout << "✓ Turno generado: " << nuevoTurno.toString() << endl;
}

// Ver todos los turnos
void verTurnos() {
    if (turnos.empty()) {
        cout << "\n⚠️  No hay turnos registrados." << endl;
        return;
    }
    
    cout << "\n========== COLA DE TURNOS ==========" << endl;
    int contador = 1;
    for (const Turno& t : turnos) {
        cout << contador << ". " << t.toString() << endl;
        contador++;
    }
    cout << "Total de turnos en la cola: " << turnos.size() << endl;
}

// Atender siguiente turno (FIFO - First In, First Out)
void atenderTurno() {
    if (turnos.empty()) {
        cout << "\n⚠️  No hay turnos para atender." << endl;
        return;
    }
    
    Turno& turnoActual = turnos.front();
    turnoActual.estado = "En atención";
    cout << "\n✓ Atendiendo: " << turnoActual.toString() << endl;
    
    cout << "¿Deseas completar este turno? (s/n): ";
    string respuesta;
    getline(cin, respuesta);
    
    if (respuesta == "s" || respuesta == "S") {
        turnos.pop_front();
        turnoActual.estado = "Completado";
        cout << "✓ Turno completado y eliminado de la cola." << endl;
        cout << "  " << turnoActual.toString() << endl;
    } else {
        turnoActual.estado = "Esperando";
        cout << "✓ Turno devuelto a la cola de espera." << endl;
    }
}

// Cancelar un turno
void cancelarTurno() {
    if (turnos.empty()) {
        cout << "\n⚠️  No hay turnos para cancelar." << endl;
        return;
    }
    
    verTurnos();
    cout << "\nIngresa el número del turno a cancelar: ";
    int numero;
    cin >> numero;
    cin.ignore();
    
    for (auto it = turnos.begin(); it != turnos.end(); ++it) {
        if (it->numero == numero) {
            turnos.erase(it);
            cout << "✓ Turno #" << numero << " cancelado." << endl;
            return;
        }
    }
    cout << "❌ Turno no encontrado." << endl;
}

// Ver estadísticas
void verEstadisticas() {
    cout << "\n========== ESTADÍSTICAS DE TURNOS ==========" << endl;
    cout << "Total de turnos en cola: " << turnos.size() << endl;
    
    if (!turnos.empty()) {
        cout << "\n✓ Primer turno (próximo a atender):" << endl;
        cout << "  " << turnos.front().toString() << endl;
        
        cout << "\n✓ Último turno registrado:" << endl;
        cout << "  " << turnos.back().toString() << endl;
        
        int esperando = 0;
        int enAtencion = 0;
        
        for (const Turno& turno : turnos) {
            if (turno.estado == "Esperando") esperando++;
            else if (turno.estado == "En atención") enAtencion++;
        }
        
        cout << "\n✓ Estado de turnos:" << endl;
        cout << "  - Esperando: " << esperando << endl;
        cout << "  - En atención: " << enAtencion << endl;
    }
}

// Demostrar operaciones específicas de list
void demostrarOperacionesLinkedList() {
    cout << "\n========== DEMOSTRACIONES DE LIST ==========" << endl;
    
    list<string> demo;
    demo.push_back("A");
    demo.push_back("B");
    demo.push_back("C");
    
    cout << "✓ list inicial: A B C" << endl;
    
    // push_front y push_back
    cout << "\n1. push_front() y push_back():" << endl;
    demo.push_front("X");
    cout << "   push_front('X'): ";
    for (const string& s : demo) cout << s << " ";
    cout << endl;
    
    demo.push_back("Z");
    cout << "   push_back('Z'): ";
    for (const string& s : demo) cout << s << " ";
    cout << endl;
    
    // front y back
    cout << "\n2. front() y back():" << endl;
    cout << "   front(): " << demo.front() << endl;
    cout << "   back(): " << demo.back() << endl;
    
    // pop_front y pop_back
    cout << "\n3. pop_front() y pop_back():" << endl;
    string primero = demo.front();
    demo.pop_front();
    cout << "   pop_front(): Eliminó '" << primero << "'" << endl;
    cout << "   Estado: ";
    for (const string& s : demo) cout << s << " ";
    cout << endl;
    
    string ultimo = demo.back();
    demo.pop_back();
    cout << "   pop_back(): Eliminó '" << ultimo << "'" << endl;
    cout << "   Estado: ";
    for (const string& s : demo) cout << s << " ";
    cout << endl;
    
    // Recorrido hacia adelante
    cout << "\n4. Recorrido hacia adelante:" << endl;
    cout << "   ";
    for (const string& s : demo) cout << s << " ";
    cout << endl;
    
    // Recorrido hacia atrás (con iterador reverso)
    cout << "\n5. Recorrido hacia atrás (reverse_iterator):" << endl;
    cout << "   ";
    for (auto it = demo.rbegin(); it != demo.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "\n>>> VENTAJAS DE LIST (std::list):" << endl;
    cout << "   ✓ Inserción/eliminación al principio: O(1)" << endl;
    cout << "   ✓ Inserción/eliminación al final: O(1)" << endl;
    cout << "   ✓ Ideal para colas (FIFO)" << endl;
    cout << "   ✓ Ideal para pilas (LIFO)" << endl;
    cout << "   ✓ push_front/push_back muy eficientes" << endl;
    cout << "   ✓ pop_front/pop_back muy eficientes" << endl;
    
    cout << "\n>>> DESVENTAJAS DE LIST (std::list):" << endl;
    cout << "   ✗ Acceso por índice: O(n)" << endl;
    cout << "   ✗ Búsqueda: O(n)" << endl;
    cout << "   ✗ Usa más memoria (referencias)" << endl;
}

int main() {
    int opcion;
    
    // Agregar algunos turnos de ejemplo
    turnos.push_back(Turno(numeroTurno++, "Juan García", "Depósito"));
    turnos.push_back(Turno(numeroTurno++, "María López", "Retiro"));
    turnos.push_back(Turno(numeroTurno++, "Carlos Pérez", "Consulta"));
    
    do {
        mostrarMenu();
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cin.ignore();
        
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
                cout << "\n¡Hasta luego!" << endl;
                break;
            default:
                cout << "\n❌ Opción inválida.\n" << endl;
        }
    } while (opcion != 7);
    
    return 0;
}
