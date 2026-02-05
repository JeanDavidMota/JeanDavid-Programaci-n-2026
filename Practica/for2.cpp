#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "--- APRENDIENDO A MULTIPLICAR ---" << endl;
    cout << "¿Qué tabla quieres ver hoy? Ingresa el número: ";
    cin >> numero;
    cout << "\nAquí tienes la tabla del " << numero << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << numero << " x " << i << " = " << (numero * i) << endl;
    }
    return 0;
}