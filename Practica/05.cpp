#include <iostream>
using namespace std;

int main() {
    int numero;
    do {
        // 1. PRIMERO hace la pregunta (siempre pasa al menos una vez)
        cout << "Adivina el numero secreto (del 1 al 10): ";
        cin >> numero;

    } while (numero != 7); // 2. LUEGO verifica: ¿Es diferente de 7? Repite.

    cout << "¡Felicidades! Adivinaste el 7." << endl;

    return 0;
}