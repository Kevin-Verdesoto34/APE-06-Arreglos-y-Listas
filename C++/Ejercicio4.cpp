#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> libros;

void mostrarMenu() {
    cout << "\n========== MENÚ CRUD ==========" << endl;
    cout << "1. CREATE - Agregar nuevo libro" << endl;
    cout << "2. READ   - Ver todos los libros" << endl;
    cout << "3. UPDATE - Actualizar un libro" << endl;
    cout << "4. DELETE - Eliminar un libro" << endl;
    cout << "5. SALIR" << endl;
    cout << "===============================" << endl;
}

// CREATE - Agregar un nuevo libro
void crear() {
    cout << "\nIngresa el nombre del libro: ";
    string libro;
    getline(cin, libro);
    
    libros.push_back(libro);
    cout << "✓ Libro '" << libro << "' agregado correctamente." << endl;
}

// READ - Ver todos los libros
void leer() {
    if (libros.empty()) {
        cout << "\n⚠️  No hay libros registrados." << endl;
        return;
    }
    
    cout << "\n========== LISTA DE LIBROS ==========" << endl;
    for (int i = 0; i < libros.size(); i++) {
        cout << (i + 1) << ". " << libros[i] << endl;
    }
    cout << "Total de libros: " << libros.size() << endl;
}

// UPDATE - Actualizar un libro
void actualizar() {
    if (libros.empty()) {
        cout << "\n⚠️  No hay libros para actualizar." << endl;
        return;
    }
    
    leer();
    cout << "\nIngresa el número del libro a actualizar: ";
    int indice;
    cin >> indice;
    cin.ignore();
    
    if (indice > 0 && indice <= libros.size()) {
        cout << "Ingresa el nuevo nombre del libro: ";
        string nuevoLibro;
        getline(cin, nuevoLibro);
        string libroAntiguo = libros[indice - 1];
        libros[indice - 1] = nuevoLibro;
        cout << "✓ Libro actualizado: '" << libroAntiguo << "' → '" << nuevoLibro << "'" << endl;
    } else {
        cout << "❌ Número de libro inválido." << endl;
    }
}

// DELETE - Eliminar un libro
void eliminar() {
    if (libros.empty()) {
        cout << "\n⚠️  No hay libros para eliminar." << endl;
        return;
    }
    
    leer();
    cout << "\nIngresa el número del libro a eliminar: ";
    int indice;
    cin >> indice;
    cin.ignore();
    
    if (indice > 0 && indice <= libros.size()) {
        string libroEliminado = libros[indice - 1];
        libros.erase(libros.begin() + indice - 1);
        cout << "✓ Libro '" << libroEliminado << "' eliminado correctamente." << endl;
    } else {
        cout << "❌ Número de libro inválido." << endl;
    }
}

int main() {
    int opcion;
    
    // Agregar algunos libros de ejemplo
    libros.push_back("1984 de George Orwell");
    libros.push_back("Cien años de soledad de Gabriel García Márquez");
    libros.push_back("El Quijote de Miguel de Cervantes");
    
    do {
        mostrarMenu();
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cin.ignore();
        
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
                cout << "\n¡Hasta luego!" << endl;
                break;
            default:
                cout << "\n❌ Opción inválida. Intenta de nuevo.\n" << endl;
        }
    } while (opcion != 5);
    
    return 0;
}
