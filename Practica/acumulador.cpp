#include <iostream>
using namespace std;

int main() {
    // 1. Variables
    float precio;
    float total = 0; // IMPORTANTE: La caja empieza vacía

    cout << "--- CAJA REGISTRADORA ---" << endl;
    cout << "(Escribe 0 para terminar y cobrar)" << endl;

    // 2. El Ciclo (Repetir)
    do {
        cout << "Ingrese el precio del producto: ";
        cin >> precio;

        // 3. El Acumulador (Suma al saco)
        // La nueva suma es igual a lo que había antes + el nuevo precio
        total = total + precio; 

    // 4. La Condición
    // Repite MIENTRAS el precio sea DIFERENTE de 0
    } while (precio != 0);

    // 5. Resultado Final
    cout << "-----------------------------" << endl;
    cout << "💰 TOTAL A PAGAR: S/" << total << endl;
    cout << "-----------------------------" << endl;

    return 0;
}