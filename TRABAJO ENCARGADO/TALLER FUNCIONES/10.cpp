#include <iostream>
using namespace std;
bool estaOrdenado(int arreglo[], int tamano) {
    for (int i = 0; i < tamano - 1; i++) { 
        if (arreglo[i] > arreglo[i + 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    int datos[] = {1, 5, 8, 12, 20};
    int n = 5;
    if (estaOrdenado(datos, n)) {
        cout << "El arreglo esta ordenado correctamente." << endl;
    } else {
        cout << "El arreglo no esta ordenado." << endl;
    }
    return 0;
}