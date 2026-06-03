#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Clase para representar un Producto
class Producto {
public:
    string nombre;
    int cantidad;
    double precio;
    
    Producto(string nombre, int cantidad, double precio) {
        this->nombre = nombre;
        this->cantidad = cantidad;
        this->precio = precio;
    }
    
    double calcularTotal() {
        return cantidad * precio;
    }
    
    string toString() const {
        stringstream ss;
        ss << nombre << " | Cantidad: " << cantidad << " | Precio: $" 
           << fixed << setprecision(2) << precio << " | Total: $" 
           << fixed << setprecision(2) << (cantidad * precio);
        return ss.str();
    }
};

#include <sstream>

vector<Producto> inventario;

// Función auxiliar para convertir a minúsculas
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void mostrarMenu() {
    cout << "\n========== SISTEMA DE INVENTARIO ==========" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Ver inventario" << endl;
    cout << "3. Actualizar cantidad" << endl;
    cout << "4. Actualizar precio" << endl;
    cout << "5. Buscar producto" << endl;
    cout << "6. Eliminar producto" << endl;
    cout << "7. Ver resumen del inventario" << endl;
    cout << "8. SALIR" << endl;
    cout << "==========================================" << endl;
}

// Agregar un nuevo producto
void agregarProducto() {
    cout << "\nIngresa el nombre del producto: ";
    string nombre;
    getline(cin, nombre);
    
    cout << "Ingresa la cantidad: ";
    int cantidad;
    cin >> cantidad;
    
    cout << "Ingresa el precio unitario: $";
    double precio;
    cin >> precio;
    cin.ignore();
    
    if (cantidad > 0 && precio > 0) {
        inventario.push_back(Producto(nombre, cantidad, precio));
        cout << "✓ Producto '" << nombre << "' agregado al inventario." << endl;
    } else {
        cout << "❌ La cantidad y el precio deben ser mayores a 0." << endl;
    }
}

// Ver todo el inventario
void verInventario() {
    if (inventario.empty()) {
        cout << "\n⚠️  El inventario está vacío." << endl;
        return;
    }
    
    cout << "\n========== INVENTARIO ==========" << endl;
    for (int i = 0; i < inventario.size(); i++) {
        cout << (i + 1) << ". " << inventario[i].toString() << endl;
    }
    cout << "Total de productos diferentes: " << inventario.size() << endl;
}

// Actualizar cantidad de un producto
void actualizarCantidad() {
    if (inventario.empty()) {
        cout << "\n⚠️  El inventario está vacío." << endl;
        return;
    }
    
    verInventario();
    cout << "\nIngresa el número del producto: ";
    int indice;
    cin >> indice;
    cin.ignore();
    
    if (indice > 0 && indice <= inventario.size()) {
        Producto& prod = inventario[indice - 1];
        cout << "Ingresa la nueva cantidad: ";
        int nuevaCantidad;
        cin >> nuevaCantidad;
        cin.ignore();
        
        if (nuevaCantidad >= 0) {
            int cantidadAnterior = prod.cantidad;
            prod.cantidad = nuevaCantidad;
            cout << "✓ Cantidad actualizada: " << cantidadAnterior << " → " << nuevaCantidad << endl;
        } else {
            cout << "❌ La cantidad no puede ser negativa." << endl;
        }
    } else {
        cout << "❌ Número de producto inválido." << endl;
    }
}

// Actualizar precio de un producto
void actualizarPrecio() {
    if (inventario.empty()) {
        cout << "\n⚠️  El inventario está vacío." << endl;
        return;
    }
    
    verInventario();
    cout << "\nIngresa el número del producto: ";
    int indice;
    cin >> indice;
    
    if (indice > 0 && indice <= inventario.size()) {
        Producto& prod = inventario[indice - 1];
        cout << "Ingresa el nuevo precio: $";
        double nuevoPrecio;
        cin >> nuevoPrecio;
        cin.ignore();
        
        if (nuevoPrecio > 0) {
            double precioAnterior = prod.precio;
            prod.precio = nuevoPrecio;
            cout << fixed << setprecision(2) << "✓ Precio actualizado: $" << precioAnterior 
                 << " → $" << nuevoPrecio << endl;
        } else {
            cout << "❌ El precio debe ser mayor a 0." << endl;
        }
    } else {
        cout << "❌ Número de producto inválido." << endl;
    }
}

// Buscar un producto por nombre
void buscarProducto() {
    if (inventario.empty()) {
        cout << "\n⚠️  El inventario está vacío." << endl;
        return;
    }
    
    cout << "\nIngresa el nombre a buscar: ";
    string nombre;
    getline(cin, nombre);
    
    cout << "\n========== RESULTADOS DE BÚSQUEDA ==========" << endl;
    bool encontrado = false;
    for (const Producto& prod : inventario) {
        if (toLower(prod.nombre).find(toLower(nombre)) != string::npos) {
            cout << "✓ " << prod.toString() << endl;
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << "❌ No se encontraron productos con ese nombre." << endl;
    }
}

// Eliminar un producto
void eliminarProducto() {
    if (inventario.empty()) {
        cout << "\n⚠️  El inventario está vacío." << endl;
        return;
    }
    
    verInventario();
    cout << "\nIngresa el número del producto a eliminar: ";
    int indice;
    cin >> indice;
    cin.ignore();
    
    if (indice > 0 && indice <= inventario.size()) {
        Producto productoEliminado = inventario[indice - 1];
        inventario.erase(inventario.begin() + indice - 1);
        cout << "✓ Producto '" << productoEliminado.nombre << "' eliminado del inventario." << endl;
    } else {
        cout << "❌ Número de producto inválido." << endl;
    }
}

// Ver resumen del inventario
void mostrarResumen() {
    if (inventario.empty()) {
        cout << "\n⚠️  El inventario está vacío." << endl;
        return;
    }
    
    int totalItems = 0;
    double valorTotal = 0;
    double precioPromedio = 0;
    double precioMayor = inventario[0].precio;
    double precioMenor = inventario[0].precio;
    string productoMasCaro = inventario[0].nombre;
    string productoMasBarato = inventario[0].nombre;
    
    for (const Producto& prod : inventario) {
        totalItems += prod.cantidad;
        valorTotal += prod.calcularTotal();
        precioPromedio += prod.precio;
        
        if (prod.precio > precioMayor) {
            precioMayor = prod.precio;
            productoMasCaro = prod.nombre;
        }
        if (prod.precio < precioMenor) {
            precioMenor = prod.precio;
            productoMasBarato = prod.nombre;
        }
    }
    
    precioPromedio = precioPromedio / inventario.size();
    
    cout << "\n========== RESUMEN DEL INVENTARIO ==========" << endl;
    cout << "Cantidad total de artículos: " << totalItems << endl;
    cout << "Número de productos diferentes: " << inventario.size() << endl;
    cout << fixed << setprecision(2) << "Valor total del inventario: $" << valorTotal << endl;
    cout << "Precio promedio: $" << precioPromedio << endl;
    cout << "Producto más caro: " << productoMasCaro << " ($" << precioMayor << ")" << endl;
    cout << "Producto más barato: " << productoMasBarato << " ($" << precioMenor << ")" << endl;
}

int main() {
    int opcion;
    
    // Agregar algunos productos de ejemplo
    inventario.push_back(Producto("Laptop", 5, 899.99));
    inventario.push_back(Producto("Mouse", 20, 29.99));
    inventario.push_back(Producto("Teclado", 15, 79.99));
    inventario.push_back(Producto("Monitor", 8, 299.99));
    
    do {
        mostrarMenu();
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cin.ignore();
        
        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                verInventario();
                break;
            case 3:
                actualizarCantidad();
                break;
            case 4:
                actualizarPrecio();
                break;
            case 5:
                buscarProducto();
                break;
            case 6:
                eliminarProducto();
                break;
            case 7:
                mostrarResumen();
                break;
            case 8:
                cout << "\n¡Hasta luego!" << endl;
                break;
            default:
                cout << "\n❌ Opción inválida.\n" << endl;
        }
    } while (opcion != 8);
    
    return 0;
}
