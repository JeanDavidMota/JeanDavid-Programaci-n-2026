#include <iostream>
using namespace std;
int main() {
    int a;
    cout << "----VIENVENIDO---- \n";
    cout << "Escribe su edad \n";
    cin >> a;
    while (a!=10)
    {
        cout << "recien naciste \n";
        cout << "Escribe su edad ";
        cin >> a;
    }
    if (a<18)
    {
        cout << "Usted es menor de edad no peudes ingrsar su edad es \n" << a; 
    }
    else
    {
        cout << "----VIENVENIDO---- \n";
        cout << "Usted es manor de edad puede ingresar";
    }
}