#include <iostream>
using namespace std;
float calcularPromedio(int notas[], int tamano) {
    float suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma += notas[i];
    }
    return suma / tamano;
}
int main() {
    int misNotas[] = {14, 16, 11, 19};
    int n = 4;
    cout << "El promedio de notas es: " << calcularPromedio(misNotas, n) << endl;
    return 0;
}