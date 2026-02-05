#include <iostream>
using namespace std;
int main () {
    int año;
    int edad;
    cout <<"Ingresa el año actual: ";
    cin >> año;
    cout <<"    Año que naciste: ";
    cin >> edad;
    int resta = año - edad;
    cout << "Tu edad es: " << resta;
}