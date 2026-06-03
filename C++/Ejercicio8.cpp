#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;

// Función auxiliar para mostrar arreglo
void mostrarArreglo(const vector<int>& arr) {
    cout << "   [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Función auxiliar para crear líneas de separación
string crearSeparador(int longitud, char caracter = '=') {
    return string(longitud, caracter);
}

void insertarEnArreglos() {
    cout << ">>> INSERCIÓN EN ARREGLOS" << endl;
    cout << crearSeparador(75, '-') << endl;
    
    // Arreglo original
    vector<int> original = {10, 20, 30, 40};
    cout << "✓ Arreglo original: " << endl;
    mostrarArreglo(original);
    
    // Insertar al final (requiere copiar)
    cout << "\n1. INSERTAR AL FINAL:" << endl;
    vector<int> conNuevoFinal(original);
    conNuevoFinal.resize(5);
    conNuevoFinal[4] = 50;
    cout << "   Resultado: " << endl;
    mostrarArreglo(conNuevoFinal);
    cout << "   Código: resize() y asignación manual" << endl;
    cout << "   Complejidad: O(n) - requiere copiar datos" << endl;
    
    // Insertar al inicio
    cout << "\n2. INSERTAR AL INICIO:" << endl;
    vector<int> conNuevoInicio(5);
    conNuevoInicio[0] = 5;
    copy(original.begin(), original.end(), conNuevoInicio.begin() + 1);
    cout << "   Resultado: " << endl;
    mostrarArreglo(conNuevoInicio);
    cout << "   Código: Desplazamiento manual + copy()" << endl;
    cout << "   Complejidad: O(n) - desplaza todos los elementos" << endl;
    
    // Insertar en el medio
    cout << "\n3. INSERTAR EN EL MEDIO (posición 2):" << endl;
    vector<int> conNuevoMedio(5);
    copy(original.begin(), original.begin() + 2, conNuevoMedio.begin());
    conNuevoMedio[2] = 25;
    copy(original.begin() + 2, original.end(), conNuevoMedio.begin() + 3);
    cout << "   Resultado: " << endl;
    mostrarArreglo(conNuevoMedio);
    cout << "   Código: Múltiples copy() calls" << endl;
    cout << "   Complejidad: O(n) - desplaza elementos después de la posición" << endl;
    
    cout << "\n❌ Desventajas:" << endl;
    cout << "   • Tamaño fijo: hay que crear un nuevo vector/array" << endl;
    cout << "   • Código complejo: requiere múltiples operaciones" << endl;
    cout << "   • Propenso a errores: fácil equivocarse con índices" << endl;
    cout << "   • Ineficiente: copia datos constantemente" << endl;
}

void insertarEnVector() {
    cout << ">>> INSERCIÓN EN VECTOR" << endl;
    cout << crearSeparador(75, '-') << endl;
    
    // Vector original
    vector<int> original = {10, 20, 30, 40};
    cout << "✓ Vector original: ";
    for (int val : original) cout << val << " ";
    cout << endl;
    
    // Insertar al final
    cout << "\n1. INSERTAR AL FINAL:" << endl;
    vector<int> conNuevoFinal = original;
    conNuevoFinal.push_back(50);
    cout << "   Resultado: ";
    for (int val : conNuevoFinal) cout << val << " ";
    cout << endl;
    cout << "   Código: vec.push_back(50)" << endl;
    cout << "   Complejidad: O(1) amortizado - muy eficiente" << endl;
    
    // Insertar al inicio
    cout << "\n2. INSERTAR AL INICIO:" << endl;
    vector<int> conNuevoInicio = original;
    conNuevoInicio.insert(conNuevoInicio.begin(), 5);
    cout << "   Resultado: ";
    for (int val : conNuevoInicio) cout << val << " ";
    cout << endl;
    cout << "   Código: vec.insert(vec.begin(), 5)" << endl;
    cout << "   Complejidad: O(n) - desplaza elementos internamente" << endl;
    
    // Insertar en el medio
    cout << "\n3. INSERTAR EN EL MEDIO (posición 2):" << endl;
    vector<int> conNuevoMedio = original;
    conNuevoMedio.insert(conNuevoMedio.begin() + 2, 25);
    cout << "   Resultado: ";
    for (int val : conNuevoMedio) cout << val << " ";
    cout << endl;
    cout << "   Código: vec.insert(vec.begin() + 2, 25)" << endl;
    cout << "   Complejidad: O(n) - desplaza elementos después de la posición" << endl;
    
    cout << "\n✓ Ventajas:" << endl;
    cout << "   • Tamaño dinámico: redimensionamiento automático" << endl;
    cout << "   • Código simple: una línea para cualquier inserción" << endl;
    cout << "   • Seguro: vector maneja la lógica interna" << endl;
    cout << "   • Flexible: métodos para insertar en cualquier posición" << endl;
}

void analizarDesempenio() {
    cout << ">>> ANÁLISIS DE DESEMPEÑO" << endl;
    cout << crearSeparador(75, '-') << endl;
    
    int tamaños[] = {100, 1000, 10000};
    
    for (int tamaño : tamaños) {
        cout << "\nInsertando en vector con " << tamaño << " elementos:" << endl;
        
        vector<int> vec;
        for (int i = 0; i < tamaño; i++) {
            vec.push_back(i);
        }
        
        // Insertar al final
        auto inicio = chrono::high_resolution_clock::now();
        vec.push_back(9999);
        auto tiempoFinal = chrono::high_resolution_clock::now();
        auto duracionFinal = chrono::duration_cast<chrono::nanoseconds>(tiempoFinal - inicio).count();
        
        // Recrear vector
        vec.clear();
        for (int i = 0; i < tamaño; i++) {
            vec.push_back(i);
        }
        
        // Insertar al inicio
        inicio = chrono::high_resolution_clock::now();
        vec.insert(vec.begin(), -1);
        auto tiempoInicio = chrono::high_resolution_clock::now();
        auto duracionInicio = chrono::duration_cast<chrono::nanoseconds>(tiempoInicio - inicio).count();
        
        // Recrear vector
        vec.clear();
        for (int i = 0; i < tamaño; i++) {
            vec.push_back(i);
        }
        
        // Insertar al medio
        inicio = chrono::high_resolution_clock::now();
        vec.insert(vec.begin() + tamaño / 2, 5000);
        auto tiempoMedio = chrono::high_resolution_clock::now();
        auto duracionMedio = chrono::duration_cast<chrono::nanoseconds>(tiempoMedio - inicio).count();
        
        cout << "  • Al final: " << duracionFinal << " ns (RÁPIDO)" << endl;
        cout << "  • Al inicio: " << duracionInicio << " ns (LENTO)" << endl;
        cout << "  • Al medio: " << duracionMedio << " ns (MEDIO)" << endl;
    }
    
    cout << "\n📊 Conclusión:" << endl;
    cout << "  • Insertar al final: O(1) - muy rápido ✓" << endl;
    cout << "  • Insertar al inicio: O(n) - lento (desplaza todos)" << endl;
    cout << "  • Insertar al medio: O(n) - lento (desplaza mitad)" << endl;
}

void mostrarComparativaInsercion() {
    cout << ">>> TABLA COMPARATIVA: INSERCIÓN" << endl;
    cout << crearSeparador(75, '-') << endl;
    
    cout << left << setw(30) << "Operación" << " | " 
         << setw(20) << "Arreglo/Vector" << " | " 
         << setw(20) << "Vector STL" << endl;
    cout << crearSeparador(75, '-') << endl;
    
    cout << left << setw(30) << "Insertar al final" << " | " 
         << setw(20) << "Requiere resize" << " | " 
         << setw(20) << "vec.push_back()" << endl;
    cout << left << setw(30) << "Código para el final" << " | " 
         << setw(20) << "7-8 líneas" << " | " 
         << setw(20) << "1 línea" << endl;
    
    cout << left << setw(30) << "Insertar al inicio" << " | " 
         << setw(20) << "Desplazar todos" << " | " 
         << setw(20) << "vec.insert()" << endl;
    cout << left << setw(30) << "Código para el inicio" << " | " 
         << setw(20) << "10+ líneas" << " | " 
         << setw(20) << "1 línea" << endl;
    
    cout << left << setw(30) << "Insertar en el medio" << " | " 
         << setw(20) << "Desplazar parciales" << " | " 
         << setw(20) << "vec.insert()" << endl;
    cout << left << setw(30) << "Código para el medio" << " | " 
         << setw(20) << "Muy complejo" << " | " 
         << setw(20) << "1 línea" << endl;
    
    cout << left << setw(30) << "Facilidad de uso" << " | " 
         << setw(20) << "Difícil ❌" << " | " 
         << setw(20) << "Fácil ✓" << endl;
    cout << left << setw(30) << "Propenso a errores" << " | " 
         << setw(20) << "Sí ❌" << " | " 
         << setw(20) << "No ✓" << endl;
    cout << left << setw(30) << "Redimensionamiento" << " | " 
         << setw(20) << "Manual" << " | " 
         << setw(20) << "Automático" << endl;
    
    cout << "\n>>> EJEMPLO PRÁCTICO:" << endl;
    cout << crearSeparador(75, '-') << endl;
    
    cout << "\nInsertar 5 en la posición 2 de [10, 20, 30, 40]:" << endl;
    
    cout << "\n❌ CON ARREGLO MANUAL:" << endl;
    cout << "  int arr[4] = {10, 20, 30, 40};" << endl;
    cout << "  int nuevo[5];" << endl;
    cout << "  copy(arr, arr + 2, nuevo);" << endl;
    cout << "  nuevo[2] = 5;" << endl;
    cout << "  copy(arr + 2, arr + 4, nuevo + 3);" << endl;
    cout << "  // Total: 5 líneas de código complejo" << endl;
    
    cout << "\n✓ CON VECTOR:" << endl;
    cout << "  vector<int> vec = {10, 20, 30, 40};" << endl;
    cout << "  vec.insert(vec.begin() + 2, 5);" << endl;
    cout << "  // Total: 2 líneas, código claro" << endl;
    
    cout << "\n>>> RECOMENDACIÓN:" << endl;
    cout << crearSeparador(75, '-') << endl;
    cout << "Use vector para inserción frecuente en cualquier posición." << endl;
    cout << "Use arreglos solo si el tamaño es fijo y no necesita insertar." << endl;
}

int main() {
    cout << "========== COMPARACIÓN: INSERCIÓN EN ARREGLOS vs VECTOR ==========\n" << endl;
    
    insertarEnArreglos();
    
    cout << "\n" << crearSeparador(75) << "\n" << endl;
    
    insertarEnVector();
    
    cout << "\n" << crearSeparador(75) << "\n" << endl;
    
    analizarDesempenio();
    
    cout << "\n" << crearSeparador(75) << "\n" << endl;
    
    mostrarComparativaInsercion();
    
    return 0;
}
