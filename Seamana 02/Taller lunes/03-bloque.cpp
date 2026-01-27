#include <iostream>
using namespace std;
int main () {
    int notas;
    cout << "Ingresa las notas: ";
    cin >> notas;
    if (notas >= 90)
    {
        cout << "exelente";
    }
    else if (notas >= 70)
    cout << "aprobado";
    else
    {
        cout << "REPROBADO";
    }
    
}