#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Función auxiliar para convertir a minúsculas
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Función para buscar un elemento en el vector
int indexOf(const vector<string>& vec, const string& valor) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == valor) {
            return i;
        }
    }
    return -1;
}

// Función para verificar si contiene un elemento
bool contains(const vector<string>& vec, const string& valor) {
    return indexOf(vec, valor) != -1;
}

int main() {
    // Crear un vector de strings para almacenar productos
    vector<string> productos;
    
    // Agregar productos al vector
    productos.push_back("Laptop");
    productos.push_back("Mouse");
    productos.push_back("Teclado");
    productos.push_back("Monitor");
    productos.push_back("Headphones");
    productos.push_back("Cable USB");
    
    // Mostrar todos los productos
    cout << "=== LISTA DE PRODUCTOS ===" << endl;
    for (int i = 0; i < productos.size(); i++) {
        cout << (i + 1) << ". " << productos[i] << endl;
    }
    
    // Búsquedas de productos
    cout << "\n=== BÚSQUEDAS ===" << endl;
    
    // Buscar un producto específico
    string buscar1 = "Teclado";
    if (contains(productos, buscar1)) {
        int indice = indexOf(productos, buscar1);
        cout << "✓ '" << buscar1 << "' encontrado en posición " << (indice + 1) << endl;
    } else {
        cout << "✗ '" << buscar1 << "' no encontrado" << endl;
    }
    
    // Buscar otro producto
    string buscar2 = "Impresora";
    if (contains(productos, buscar2)) {
        int indice = indexOf(productos, buscar2);
        cout << "✓ '" << buscar2 << "' encontrado en posición " << (indice + 1) << endl;
    } else {
        cout << "✗ '" << buscar2 << "' no encontrado" << endl;
    }
    
    // Buscar por patrón (productos que contengan una palabra)
    cout << "\n=== BÚSQUEDA POR PATRÓN ===" << endl;
    string patron = "o";
    cout << "Productos que contienen '" << patron << "':" << endl;
    for (string producto : productos) {
        if (toLower(producto).find(toLower(patron)) != string::npos) {
            cout << "- " << producto << endl;
        }
    }
    
    // Información general
    cout << "\n=== INFORMACIÓN ===" << endl;
    cout << "Total de productos registrados: " << productos.size() << endl;
    
    return 0;
}
