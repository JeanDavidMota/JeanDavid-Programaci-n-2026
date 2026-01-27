#include <iostream>
using namespace std;
int main() {
    int edad;
    cout << "ingresa su edad: ";
    cin >> edad;
    if (edad >= 18)
    {
        cout << "Acceso permitido";
    }
    else
    {
        cout << "Acceso denegado";
    }
}