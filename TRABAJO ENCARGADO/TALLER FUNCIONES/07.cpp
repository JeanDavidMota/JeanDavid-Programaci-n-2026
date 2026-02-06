#include <iostream>
using namespace std;
bool validarMenu(int opcion, int min, int max) {
    if (opcion >= min && opcion <= max) {
        return true;
    } else {
        return false;
    }
}
int main() {
    int eleccion;
    cout << "Seleccione una opcion (1-3): ";
    cin >> eleccion;
    if (validarMenu(eleccion, 1, 3)) {
        cout << "Opcion valida. Cargando..." << endl;
    } else {
        cout << "Error: Opcion no permitida." << endl;
    }
    return 0;
}