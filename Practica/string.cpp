#include <iostream>
#include <string>
using namespace std;
int main () {
    string nombre;
    cout <<"cual es tu nombre: ";
    // cin >> nombre;  
    getline(cin, nombre);
    cout <<"Vienvenido " << nombre << endl;
    cout <<"elije una opcion \n 1- prueba \n 2-testeo \n 3-hola";
    return 0;
}