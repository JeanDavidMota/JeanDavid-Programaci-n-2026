#include <iostream>
using namespace std;
int sumarElementos(int arreglo[], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += arreglo[i];
    }
    return suma;
}
int main() {
    int datos[] = {10, 20, 30, 40};
    int n = 4;
    cout << "La suma de los elementos es: " << sumarElementos(datos, n) << endl;
    return 0;
}