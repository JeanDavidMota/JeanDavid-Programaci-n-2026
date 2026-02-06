#include <iostream>
using namespace std;
bool buscarValor(int arreglo[], int tamano, int valorBuscado) {
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == valorBuscado) {
            return true;
        }
    }
    return false;
}
int main() {
    int misDatos[] = {5, 12, 8, 20, 3};
    int n = 5;
    int buscar = 8;
    if (buscarValor(misDatos, n, buscar)) {
        cout << "El valor " << buscar << " si existe en el arreglo." << endl;
    } else {
        cout << "El valor no fue encontrado." << endl;
    }
    return 0;
}