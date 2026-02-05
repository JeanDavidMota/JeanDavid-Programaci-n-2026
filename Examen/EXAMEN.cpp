#include <iostream>
using namespace std;

int main() {
    int opc, diaCerrado = 0;
    int units, transactionCode;
    float unitPrice, ingreso;
    float ingresoNeto = 0;
    int ventasValidas = 0;
    int devoluciones = 0;
    int transInvalidas = 0;
    float mayorIng = 0;
    float menorIng = 0;
    float sumaIngresoVentas = 0;
    do {
        cout << "\n--- MENU DEL SISTEMA ---" << endl;
        cout << "1) Registrar transaccion" << endl;
        cout << "2) Reporte de ventas del dia" << endl;
        cout << "3) Reporte por transaccion (A / B / C / D)" << endl;
        cout << "4) Cerrar dia" << endl;
        cout << "5) Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opc;
        switch (opc) {
            case 1:
                if (diaCerrado == 1) {
                    cout << "NO SE PUEDEN REGISTRAR MAS TRANSACCIONES. DIA CERRADO." << endl;
                } else {
                    cout << "Ingrese units, unitPrice y transactionCode: ";
                    cin >> units >> unitPrice >> transactionCode;
                    if (units != 0 && unitPrice > 0) {
                        ingreso = units * unitPrice;
                        ingresoNeto = ingresoNeto + ingreso;
                        if (ventasValidas == 0 && devoluciones == 0) {
                            mayorIng = ingreso;
                            menorIng = ingreso;
                        } else {
                            if (ingreso > mayorIng) {
                                mayorIng = ingreso;
                            }
                            if (ingreso < menorIng) {
                                menorIng = ingreso;
                            }
                        }
                        if (units > 0) {
                            ventasValidas = ventasValidas + 1;
                            sumaIngresoVentas = sumaIngresoVentas + ingreso;
                        } else {
                            devoluciones = devoluciones + 1;
                        }
                        int valorAbs = transactionCode;
                        if (valorAbs < 0) {
                            valorAbs = -valorAbs;
                        }
                        int sumaD = 0, temp = valorAbs, cuentaD = 0;
                        while (temp > 0) {
                            sumaD = sumaD + (temp % 10);
                            temp = temp / 10;
                            cuentaD = cuentaD + 1;
                        }
                        if (valorAbs == 0) {
                            cuentaD = 1;
                        }
                        cout << "RESULTADO: ";
                        if (sumaD % 2 == 0 && valorAbs % 4 == 0) {
                            cout << "A" << endl;
                        } else if (sumaD % 2 != 0 && valorAbs % 6 == 0) {
                            cout << "B" << endl;
                        } else if (cuentaD == 3) {
                            cout << "C" << endl;
                        } else {
                            cout << "D" << endl;
                        }
                    } else {
                        transInvalidas = transInvalidas + 1;
                    }
                }
                break;
            case 2:
                cout << "\nINGRESO_NETO=" << ingresoNeto << endl;
                cout << "VENTAS_VALIDAS=" << ventasValidas << endl;
                cout << "DEVOLUCIONES=" << devoluciones << endl;
                cout << "TRANS_INVALIDAS=" << transInvalidas << endl;
                cout << "MAYOR_ING=" << mayorIng << endl;
                cout << "MENOR_ING=" << menorIng << endl;
                
                if (ventasValidas > 0) {
                    cout << "PROM_VENTA=" << (sumaIngresoVentas / ventasValidas) << endl;
                } else {
                    cout << "PROM_VENTA=NO EXISTE" << endl;
                }
                break;
            case 3:
                cout << "Nota: Los reportes A/B/C/D se imprimen al registrar cada transaccion." << endl;
                break;
            case 4:
                diaCerrado = 1;
                cout << "DIA CERRADO CON EXITO." << endl;
                break;
            case 5:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opc != 5);
    return 0;
}