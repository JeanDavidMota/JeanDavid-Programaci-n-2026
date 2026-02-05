#include <iostream>
using namespace std;

int main() {
    int opcion;
    do {
        cout << "\n--- MENU DE JUEGO ---" << endl;
        cout << "1. Atacar" << endl;
        cout << "2. Defender" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        // AQUI ESTA EL CAMBIO: Usamos las llaves { } como siempre
        if (opcion == 1) {
            cout << "¡Pow! Lanzaste un golpe. 🥊" << endl;
        }
        if (opcion == 2) {
            cout << "Te cubres con el escudo. 🛡️" << endl;
        }
    } while (opcion != 3); // Repetir mientras NO elija salir (3)
    cout << "Juego terminado. ¡Adios!";
    return 0;
}