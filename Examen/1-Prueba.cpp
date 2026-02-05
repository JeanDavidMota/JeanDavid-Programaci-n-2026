#include <iostream>
using namespace std;
int main () {
    int opc;
    do
    {
        cout << "MENU DEL SISTEMA" << endl;
        cout << "1) Registrar transacción" << endl;
        cout << "2) Reporte de ventas del dia" << endl;
        cout << "3) Reporte por transacción (A / B / C / D" << endl;
        cout << "4) Cerrar dia" << endl;
        cout << "5) Salir" << endl;
        cin >> opc;
        do
        {
        
    switch (opc!=5)
    {
    case 1:
    int units, unitPrice, transactionCode;
        cout << "Ingresa el units(unidad) \n";
        cin >> units;
        cout << "Ingresa el unitPrice(precio) \n";
        cin >> unitPrice;
        cout << "Ingresa el transactionCode(codigo) \n";
        cin >> transactionCode;
        if (units > 0)
        {
            /* code */
        }
        
        break;
    case 2:
        
    default:
        break;
    }
    } while ( opc != 4);
    cout << "dia cerrado";
    } while ( opc != 5);
}