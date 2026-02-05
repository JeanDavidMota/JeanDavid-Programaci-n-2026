#include <iostream>
using namespace std;
int main() {
    int opc, diaCerrado = 0;
    int units, transactionCode;
    float unitPrice, ingreso;
    
    float neto = 0, sumaVentasValidas = 0;
    int vValidas = 0, devol = 0, inv = 0;
    float mayor = 0, menor = 0;
    do {
        cout << "MENU DEL SISTEMA" << endl;
        cout << "1) Registrar transaccion" << endl;
        cout << "2) Reporte de ventas del dia" << endl;
        cout << "3) Reporte por transaccion (A / B / C / D)" << endl;
        cout << "4) Cerrar dia" << endl;
        cout << "5) Salir" << endl;
        cin >> opc;
        if (opc == 1) {
            if (diaCerrado == 1) {
                cout << "NO SE PUEDEN REGISTRAR MAS TRANSACCIONES. DIA CERRADO." << endl;
            } else {
                cout << "Ingresa units, unitPrice y transactionCode: ";
                cin >> units >> unitPrice >> transactionCode;
                if (units != 0 && unitPrice > 0) {
                    ingreso = units * unitPrice;
                    neto = neto + ingreso;
                    if (vValidas == 0 && devol == 0) {
                        mayor = ingreso;
                        menor = ingreso;
                    } else {
                        if (ingreso > mayor) mayor = ingreso;
                        if (ingreso < menor) menor = ingreso;
                    }
                    if (units > 0) {
                        vValidas = vValidas + 1;
                        sumaVentasValidas = sumaVentasValidas + ingreso;
                    } else {
                        devol = devol + 1;
                    }
                    int vAbs = transactionCode;
                    if (vAbs < 0) vAbs = -vAbs;
                    int sumaD = 0, temp = vAbs, cD = 0;
                    while (temp > 0) {
                        sumaD = sumaD + (temp % 10);
                        temp = temp / 10;
                        cD = cD + 1;
                    }
                    if (vAbs == 0) cD = 1;
                    if (sumaD % 2 == 0 && vAbs % 4 == 0) cout << "A" << endl;
                    else if (sumaD % 2 != 0 && vAbs % 6 == 0) cout << "B" << endl;
                    else if (cD == 3) cout << "C" << endl;
                    else cout << "D" << endl;
                } else {
                    inv = inv + 1;
                }
            }
        }
        if (opc == 2) {
            cout << "INGRESO_NETO=" << neto << endl;
            cout << "VENTAS_VALIDAS=" << vValidas << endl;
            cout << "DEVOLUCIONES=" << devol << endl;
            cout << "TRANS_INVALIDAS=" << inv << endl;
            cout << "MAYOR_ING=" << mayor << endl;
            cout << "MENOR_ING=" << menor << endl;
            
            if (vValidas > 0) {
                cout << "PROM_VENTA=" << (sumaVentasValidas / vValidas) << endl;
            } else {
                cout << "PROM_VENTA=NO EXISTE" << endl;
            }
        }
        if (opc == 4) {
            diaCerrado = 1;
            cout << "DIA CERRADO" << endl;
        }
    } while (opc != 5);
    return 0;
}