#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> nombres;
    vector<double> precios;
    vector<double> cantidades;

    int opcion, i;
    int totalProductos = 0;

    do {
        cout << "====== SISTEMA DE INVENTARIO ======" << endl;
        cout << "1. Ingresar producto" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Modificar stock" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;

        while (opcion < 1 || opcion > 4) {
            cout << "Opción inválida. Intente nuevamente: ";
            cin >> opcion;
        }

        switch (opcion) {

        case 1: {
            string nombre;
            double precio, cantidad;

            cout << "Ingrese nombre del producto: ";
            cin >> nombre;

            do {
                cout << "Ingrese precio del producto: ";
                cin >> precio;
            } while (precio <= 0);

            do {
                cout << "Ingrese cantidad del producto: ";
                cin >> cantidad;
            } while (cantidad < 0);

            nombres.push_back(nombre);
            precios.push_back(precio);
            cantidades.push_back(cantidad);

            totalProductos++;

            cout << "Producto registrado correctamente." << endl;
            break;
        }

        case 2:
            if (totalProductos == 0) {
                cout << "No hay productos en el inventario." << endl;
            } else {
                for (i = 0; i < totalProductos; i++) {
                    cout << "Producto " << (i + 1) << endl;
                    cout << "Nombre: " << nombres[i] << endl;
                    cout << "Precio: " << precios[i] << endl;
                    cout << "Cantidad: " << cantidades[i] << endl;
                    cout << "----------------------" << endl;
                }
            }
            break;

        case 3:
            if (totalProductos == 0) {
                cout << "No hay productos para actualizar." << endl;
            } else {
                cout << "Ingrese el número del producto (1 - " << totalProductos << "): ";
                cin >> i;

                while (i < 1 || i > totalProductos) {
                    cout << "Número inválido. Intente nuevamente: ";
                    cin >> i;
                }

                do {
                    cout << "Ingrese nueva cantidad: ";
                    cin >> cantidades[i - 1];
                } while (cantidades[i - 1] < 0);

                cout << "Stock actualizado." << endl;
            }
            break;

        case 4:
            cout << "Gracias por usar el sistema de inventario" << endl;
            break;
        }

    } while (opcion != 4);

    return 0;
}