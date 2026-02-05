#include <iostream> 
using namespace std; 
int main() {
    int opcion; // Variable para guardar la elección del usuario

    // INICIO DEL BUCLE DO-WHILE
    do {
        // Mostramos el menú (Esto se hace al menos una vez)
        cout << "\n=== MENU DE COMIDA ===" << endl;
        cout << "1. Hamburguesa" << endl;
        cout << "2. Pizza" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        // Evaluamos la opción
        if (opcion == 1) {
            cout << ">>> Marchando una burger! 🍔" << endl;
        } else if (opcion == 2) {
            cout << ">>> Pizza en camino! 🍕" << endl;
        } else if (opcion != 3) {
            cout << ">>> Opcion incorrecta, intenta de nuevo." << endl;
        }

    // 4. LA CONDICIÓN (El guardia de seguridad)
    // Si la opción NO es 3, repetimos el ciclo.
    } while (opcion != 3); 

    cout << "Gracias por su visita. ¡Adios! 👋" << endl;

    return 0; // Todo salió bien
}