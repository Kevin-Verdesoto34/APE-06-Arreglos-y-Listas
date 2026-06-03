#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Función auxiliar para crear líneas de separación
string crearSeparador(int longitud, char caracter = '=') {
    return string(longitud, caracter);
}

void demostrarArreglos() {
    cout << ">>> ARREGLOS (Arrays)" << endl;
    cout << crearSeparador(60, '-') << endl;
    
    // Crear un arreglo de tamaño fijo
    int numeros[5];
    cout << "✓ Arreglo creado con tamaño fijo: 5" << endl;
    
    // Llenar el arreglo
    for (int i = 0; i < 5; i++) {
        numeros[i] = (i + 1) * 10;
    }
    
    cout << "\n✓ Contenido del arreglo:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  numeros[" << i << "] = " << numeros[i] << endl;
    }
    
    // Características de los arreglos
    cout << "\nCaracterísticas:" << endl;
    cout << "  • Tamaño: 5 (fijo)" << endl;
    cout << "  • Tipo: int[]" << endl;
    cout << "  • Acceso por índice: ✓ Rápido O(1)" << endl;
    cout << "  • Insertar/eliminar elementos: ✗ Difícil" << endl;
    cout << "  • Redimensionamiento: ✗ No automático" << endl;
    
    // Limitación
    cout << "\n❌ Limitación: No se pueden agregar elementos más allá del tamaño fijo." << endl;
    cout << "   El arreglo tiene tamaño 5, no se puede agregar un sexto elemento." << endl;
}

void demostrarVector() {
    cout << ">>> VECTOR (Equivalente a ArrayList)" << endl;
    cout << crearSeparador(60, '-') << endl;
    
    // Crear un vector dinámico
    vector<int> numeros;
    cout << "✓ Vector creado sin tamaño fijo (dinámico)" << endl;
    
    // Agregar elementos
    for (int i = 1; i <= 5; i++) {
        numeros.push_back(i * 10);
    }
    
    cout << "\n✓ Se agregaron 5 elementos:" << endl;
    for (int i = 0; i < numeros.size(); i++) {
        cout << "  numeros[" << i << "] = " << numeros[i] << endl;
    }
    
    // Agregar más elementos (se redimensiona automáticamente)
    numeros.push_back(60);
    numeros.push_back(70);
    cout << "\n✓ Se agregaron 2 elementos más (redimensionamiento automático):" << endl;
    cout << "  Tamaño actual: " << numeros.size() << endl;
    cout << "  Contenido: ";
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i];
        if (i < numeros.size() - 1) cout << ", ";
    }
    cout << endl;
    
    // Eliminar un elemento
    int eliminado = numeros[2];
    numeros.erase(numeros.begin() + 2);
    cout << "\n✓ Se eliminó el elemento en índice 2 (valor: " << eliminado << ")" << endl;
    cout << "  Tamaño actual: " << numeros.size() << endl;
    cout << "  Contenido: ";
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i];
        if (i < numeros.size() - 1) cout << ", ";
    }
    cout << endl;
    
    // Características del vector
    cout << "\nCaracterísticas:" << endl;
    cout << "  • Tamaño: " << numeros.size() << " (dinámico)" << endl;
    cout << "  • Tipo: vector<int>" << endl;
    cout << "  • Acceso por índice: ✓ O(1)" << endl;
    cout << "  • Insertar/eliminar elementos: ✓ Fácil" << endl;
    cout << "  • Redimensionamiento: ✓ Automático" << endl;
    cout << "  • Type-safe: ✓ Templates <T>" << endl;
}

void mostrarComparativa() {
    cout << ">>> TABLA COMPARATIVA" << endl;
    cout << crearSeparador(60, '-') << endl;
    
    cout << left << setw(25) << "Característica" << " | " 
         << setw(20) << "Arreglo" << " | " 
         << setw(20) << "Vector" << endl;
    cout << crearSeparador(60, '-') << endl;
    
    cout << left << setw(25) << "Tamaño" << " | " 
         << setw(20) << "Fijo" << " | " 
         << setw(20) << "Dinámico" << endl;
    cout << left << setw(25) << "Redimensionamiento" << " | " 
         << setw(20) << "Manual" << " | " 
         << setw(20) << "Automático" << endl;
    cout << left << setw(25) << "Agregar elemento" << " | " 
         << setw(20) << "Difícil" << " | " 
         << setw(20) << "Fácil (.push_back())" << endl;
    cout << left << setw(25) << "Eliminar elemento" << " | " 
         << setw(20) << "Difícil" << " | " 
         << setw(20) << "Fácil (.erase())" << endl;
    cout << left << setw(25) << "Acceso por índice" << " | " 
         << setw(20) << "Rápido" << " | " 
         << setw(20) << "Rápido" << endl;
    cout << left << setw(25) << "Tipos de datos" << " | " 
         << setw(20) << "Un tipo" << " | " 
         << setw(20) << "Template" << endl;
    cout << left << setw(25) << "Búsqueda (find)" << " | " 
         << setw(20) << "No" << " | " 
         << setw(20) << "Sí" << endl;
    cout << left << setw(25) << "Ordenamiento" << " | " 
         << setw(20) << "Manual" << " | " 
         << setw(20) << "std::sort()" << endl;
    cout << left << setw(25) << "Memoria" << " | " 
         << setw(20) << "Exacta" << " | " 
         << setw(20) << "Un poco más" << endl;
    cout << left << setw(25) << "Rendimiento" << " | " 
         << setw(20) << "Muy rápido" << " | " 
         << setw(20) << "Rápido" << endl;
    
    cout << "\n>>> CUÁNDO USAR CADA UNO:" << endl;
    cout << crearSeparador(60, '-') << endl;
    cout << "Use ARREGLOS cuando:" << endl;
    cout << "  • El tamaño es fijo y conocido" << endl;
    cout << "  • Necesita máximo rendimiento" << endl;
    cout << "  • Está trabajando con tipos primitivos" << endl;
    cout << "  • Los elementos no cambian después de la creación" << endl;
    
    cout << "\nUse VECTOR cuando:" << endl;
    cout << "  • El tamaño es variable" << endl;
    cout << "  • Necesita agregar/eliminar elementos frecuentemente" << endl;
    cout << "  • Necesita type-safety con Templates" << endl;
    cout << "  • Necesita métodos como find(), sort()" << endl;
    cout << "  • Prefiere trabajar con objetos" << endl;
    
    cout << "\n>>> EJEMPLOS DE CÓDIGO:" << endl;
    cout << crearSeparador(60, '-') << endl;
    
    cout << "ARREGLO:" << endl;
    cout << "  int arr[5];" << endl;
    cout << "  arr[0] = 10;" << endl;
    cout << "  // Tamaño: 5 (constante)" << endl;
    
    cout << "\nVECTOR:" << endl;
    cout << "  vector<int> vec;" << endl;
    cout << "  vec.push_back(10);" << endl;
    cout << "  cout << vec.size(); // 1" << endl;
    cout << "  vec.push_back(20);" << endl;
    cout << "  cout << vec.size(); // 2" << endl;
}

int main() {
    cout << "========== COMPARACIÓN: ARREGLOS vs VECTOR ==========\n" << endl;
    
    // Demostración de Arreglos
    demostrarArreglos();
    
    cout << "\n" << crearSeparador(60) << "\n" << endl;
    
    // Demostración de Vector
    demostrarVector();
    
    cout << "\n" << crearSeparador(60) << "\n" << endl;
    
    // Tabla comparativa
    mostrarComparativa();
    
    return 0;
}
