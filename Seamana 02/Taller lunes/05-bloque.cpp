#include <iostream>
using namespace std;
int main() {
    int hora;
    cout << "Ingrese la hora (0-23): ";
    cin >> hora;
    if (hora >= 6 and hora <= 11)
    {
        cout << "Buenos días";
    }
    else if (hora >= 12 and hora <= 18)
    {
        cout << "Buenas tardes";
    }
    else if (hora >= 19 and hora <= 23)
    {
        cout << "Buenas noches";
    }
    else
    {
        cout << "HORA NO INAVLIDO";
    }
}

// MAESTRO NO SE QUE PONER DEL 0 AL 6 NO LO ESPECIFICAS EN EL WORD?? 
// Podria ser "Madrugada" pero el codigo lo mandara a "Hora no valida"