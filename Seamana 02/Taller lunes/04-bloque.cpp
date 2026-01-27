#include <iostream>
using namespace std;
int main() {
    cout << "MENU DE OPCIONES" << endl;
    cout << "1: SUMAR" << endl;
    cout << "2: RESTAR" << endl;
    cout << "3: MULTIPLICAR" << endl;
    cout << "4: DIVIDIR" << endl;
    cout << "INGRESA SU OPCION: ";
    
    int opcion;
    cin >> opcion;
    switch (opcion){
    case 1: 
        cout << "Suma"; 
        break;
    case 2: 
        cout << "Resta"; 
        break;
    case 3: 
        cout << "Multiplicación"; 
        break;
    case 4: 
        cout << "División"; 
        break;
    default:
        cout << "Opción no válida"; 
    }
}