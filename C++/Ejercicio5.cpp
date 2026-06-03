#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Clase para representar un Estudiante
class Estudiante {
public:
    string nombre;
    double nota;
    
    Estudiante(string nombre, double nota) {
        this->nombre = nombre;
        this->nota = nota;
    }
    
    string toString() const {
        return nombre + " - Nota: " + to_string(nota);
    }
};

vector<Estudiante> estudiantes;

// Función auxiliar para convertir a minúsculas
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void mostrarMenu() {
    cout << "\n========== REGISTRAR ESTUDIANTES Y NOTAS ==========" << endl;
    cout << "1. Registrar nuevo estudiante" << endl;
    cout << "2. Ver todos los estudiantes" << endl;
    cout << "3. Buscar estudiante por nombre" << endl;
    cout << "4. Calcular promedio de notas" << endl;
    cout << "5. Ver estadísticas" << endl;
    cout << "6. SALIR" << endl;
    cout << "==================================================" << endl;
}

// Registrar un nuevo estudiante
void registrarEstudiante() {
    cout << "\nIngresa el nombre del estudiante: ";
    string nombre;
    getline(cin, nombre);
    
    cout << "Ingresa la nota del estudiante: ";
    double nota;
    cin >> nota;
    cin.ignore();
    
    if (nota >= 0 && nota <= 100) {
        estudiantes.push_back(Estudiante(nombre, nota));
        cout << "✓ Estudiante '" << nombre << "' registrado con nota " << nota << endl;
    } else {
        cout << "❌ La nota debe estar entre 0 y 100." << endl;
    }
}

// Ver todos los estudiantes
void verTodos() {
    if (estudiantes.empty()) {
        cout << "\n⚠️  No hay estudiantes registrados." << endl;
        return;
    }
    
    cout << "\n========== LISTA DE ESTUDIANTES ==========" << endl;
    for (int i = 0; i < estudiantes.size(); i++) {
        cout << (i + 1) << ". " << estudiantes[i].toString() << endl;
    }
    cout << "Total de estudiantes: " << estudiantes.size() << endl;
}

// Buscar un estudiante por nombre
void buscarEstudiante() {
    if (estudiantes.empty()) {
        cout << "\n⚠️  No hay estudiantes para buscar." << endl;
        return;
    }
    
    cout << "\nIngresa el nombre a buscar: ";
    string nombre;
    getline(cin, nombre);
    
    cout << "\n========== RESULTADOS DE BÚSQUEDA ==========" << endl;
    bool encontrado = false;
    for (const Estudiante& est : estudiantes) {
        if (toLower(est.nombre).find(toLower(nombre)) != string::npos) {
            cout << "✓ " << est.toString() << endl;
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << "❌ No se encontraron estudiantes con ese nombre." << endl;
    }
}

// Calcular el promedio de notas
void calcularPromedio() {
    if (estudiantes.empty()) {
        cout << "\n⚠️  No hay estudiantes para calcular promedio." << endl;
        return;
    }
    
    double suma = 0;
    for (const Estudiante& est : estudiantes) {
        suma += est.nota;
    }
    
    double promedio = suma / estudiantes.size();
    cout << "\n========== PROMEDIO DE NOTAS ==========" << endl;
    cout << "Suma total: " << fixed << setprecision(1) << suma << endl;
    cout << "Cantidad de estudiantes: " << estudiantes.size() << endl;
    cout << "Promedio: " << fixed << setprecision(2) << promedio << endl;
}

// Ver estadísticas
void verEstadisticas() {
    if (estudiantes.empty()) {
        cout << "\n⚠️  No hay estudiantes para mostrar estadísticas." << endl;
        return;
    }
    
    double notaMayor = estudiantes[0].nota;
    double notaMenor = estudiantes[0].nota;
    double suma = 0;
    string estudianteMejor = estudiantes[0].nombre;
    string estudiantePeor = estudiantes[0].nombre;
    
    for (const Estudiante& est : estudiantes) {
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
    
    cout << "\n========== ESTADÍSTICAS ==========" << endl;
    cout << "Promedio: " << fixed << setprecision(2) << promedio << endl;
    cout << "Nota mayor: " << notaMayor << " (" << estudianteMejor << ")" << endl;
    cout << "Nota menor: " << notaMenor << " (" << estudiantePeor << ")" << endl;
    cout << "Total de estudiantes: " << estudiantes.size() << endl;
}

int main() {
    int opcion;
    
    // Agregar algunos estudiantes de ejemplo
    estudiantes.push_back(Estudiante("Juan Pérez", 85.5));
    estudiantes.push_back(Estudiante("María García", 92.0));
    estudiantes.push_back(Estudiante("Carlos López", 78.3));
    
    do {
        mostrarMenu();
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cin.ignore();
        
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
                cout << "\n¡Hasta luego!" << endl;
                break;
            default:
                cout << "\n❌ Opción inválida.\n" << endl;
        }
    } while (opcion != 6);
    
    return 0;
}
