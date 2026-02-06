#include <iostream>
using namespace std;
int hallarMinimo(int arreglo[], int tamano) {
    int minimo = arreglo[0];
    
    for (int i = 1; i < tamano; i++) {
        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
        }
    }
    return minimo;
}
int main() {
    int datos[] = {15, 4, 22, 1, 8};
    int n = 5;
    cout << "El valor minimo es: " << hallarMinimo(datos, n) << endl;
    return 0;
}