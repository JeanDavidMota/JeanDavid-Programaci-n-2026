#include <iostream>

using namespace std;

int main() {
    // Variables de control de estado
    int opcion = 0;
    bool diaCerrado = false;

    // Variables para Reporte de Ventas
    float ingresoNeto = 0;
    int ventasValidas = 0;
    int devoluciones = 0;
    int transInvalidas = 0;
    float mayorIngreso = -999999; // Valor inicial muy bajo
    float menorIngreso = 999999;  // Valor inicial muy alto
    float sumaAbsolutaVentas = 0;

    // Variables de entrada
    int unidades, codigo;
    float precio, ingreso;

    while (opcion != 5) {
        cout << "\n--- MENU DEL SISTEMA ---\n";
        cout << "1) Registrar transaccion\n";
        cout << "2) Reporte de ventas del dia\n";
        cout << "3) Reporte por transaccion\n";
        cout << "4) Cerrar dia\n";
        cout << "5) Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        if (opcion == 1) {
            if (diaCerrado) {
                cout << "NO SE PUEDEN REGISTRAR MAS TRANSACCIONES. DIA CERRADO.\n";
            } else {
                cin >> unidades >> precio >> codigo;

                // Validación de transacción
                if (unidades != 0 && precio > 0) {
                    ingreso = unidades * precio;
                    ingresoNeto += ingreso;

                    if (unidades > 0) {
                        ventasValidas++;
                        sumaAbsolutaVentas += ingreso;
                    } else {
                        devoluciones++;
                    }

                    // Calcular Mayor y Menor Ingreso
                    if (ingreso > mayorIngreso) mayorIngreso = ingreso;
                    if (ingreso < menorIngreso) menorIngreso = ingreso;

                    // Lógica del Reporte por Transacción (Opción 3)
                    // Nota: Se pide por cada código registrado. 
                    // Como no hay arreglos, la letra se calcula y muestra aquí o se guarda.
                    // Para cumplir con el enunciado de "generar reportes basados en datos",
                    // procesamos el código actual.
                    
                    int absCodigo = (codigo < 0) ? -codigo : codigo;
                    int sumaDigitos = 0;
                    int tempCodigo = absCodigo;
                    int contadorDigitos = 0;

                    // Suma de dígitos y contador
                    if (tempCodigo == 0) contadorDigitos = 1;
                    while (tempCodigo > 0) {
                        sumaDigitos += tempCodigo % 10;
                        tempCodigo /= 10;
                        contadorDigitos++;
                    }

                    // Evaluación de Categorías A, B, C, D
                    if (sumaDigitos % 2 == 0 && absCodigo % 4 == 0) {
                        cout << "CATEGORIA: A\n";
                    } else if (sumaDigitos % 2 != 0 && absCodigo % 6 == 0) {
                        cout << "CATEGORIA: B\n";
                    } else if (contadorDigitos == 3) {
                        cout << "CATEGORIA: C\n";
                    } else {
                        cout << "CATEGORIA: D\n";
                    }

                } else {
                    transInvalidas++;
                }
            }
        } 
        else if (opcion == 2) {
            cout << "INGRESO_NETO=" << ingresoNeto << endl;
            cout << "VENTAS_VALIDAS=" << ventasValidas << endl;
            cout << "DEVOLUCIONES=" << devoluciones << endl;
            cout << "TRANS_INVALIDAS=" << transInvalidas << endl;
            
            if (ventasValidas + devoluciones > 0) {
                cout << "MAYOR_ING=" << mayorIngreso << endl;
                cout << "MENOR_ING=" << menorIngreso << endl;
            } else {
                cout << "MAYOR_ING=0\nMENOR_ING=0\n";
            }

            if (ventasValidas > 0) {
                cout << "PROM_VENTA=" << (sumaAbsolutaVentas / ventasValidas) << endl;
            } else {
                cout << "PROM_VENTA=NO EXISTE" << endl;
            }
        } 
        else if (opcion == 3) {
            cout << "(Los resultados de categorias se muestran al registrar segun la logica sin arreglos)\n";
        }
        else if (opcion == 4) {
            diaCerrado = true;
            cout << "DIA CERRADO.\n";
        }
    }

    return 0;
}