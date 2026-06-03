#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Crear un vector de strings con 5 nombres de estudiantes
    vector<string> estudiantes;
    
    // Agregar 5 nombres de estudiantes al vector
    estudiantes.push_back("Juan");
    estudiantes.push_back("María");
    estudiantes.push_back("Carlos");
    estudiantes.push_back("Ana");
    estudiantes.push_back("Luis");
    
    // Mostrar los estudiantes en el vector
    cout << "Lista de estudiantes:" << endl;
    for (string estudiante : estudiantes) {
        cout << "- " << estudiante << endl;
    }
    
    // Mostrar la cantidad de estudiantes
    cout << "\nTotal de estudiantes: " << estudiantes.size() << endl;
    
    return 0;
}
