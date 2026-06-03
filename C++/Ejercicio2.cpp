#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    // Crear un vector de doubles con 6 notas
    vector<double> notas;
    
    // Agregar 6 notas al vector
    notas.push_back(85.5);
    notas.push_back(92.0);
    notas.push_back(78.3);
    notas.push_back(88.7);
    notas.push_back(95.2);
    notas.push_back(81.0);
    
    // Mostrar las notas
    cout << "Lista de notas:" << endl;
    for (int i = 0; i < notas.size(); i++) {
        cout << "Nota " << (i + 1) << ": " << notas[i] << endl;
    }
    
    // Calcular el promedio
    double suma = 0;
    for (double nota : notas) {
        suma += nota;
    }
    double promedio = suma / notas.size();
    
    cout << "\nTotal de notas: " << notas.size() << endl;
    cout << "Suma total: " << fixed << setprecision(1) << suma << endl;
    cout << "Promedio: " << fixed << setprecision(2) << promedio << endl;
    
    return 0;
}
