#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Producto {
    string nombre;
    double precio;
    int stock;
};

// Función corregida para Linux/macOS
void limpiarPantalla() {
    system("clear"); // En Linux se usa 'clear', no 'cls'
}

// Función corregida para pausar en Linux
void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get(); 
}

void generarBoleta(string cliente, Producto p, int cantidad) {
    double total = p.precio * cantidad;
    cout << "\n\t========================================" << endl;
    cout << "\t           BOLETA DE VENTA             " << endl;
    cout << "\t========================================" << endl;
    cout << "\t Cliente: " << cliente << endl;
    cout << "\t----------------------------------------" << endl;
    cout << "\t " << left << setw(15) << "Producto" << setw(10) << "Precio" << "Cant." << endl;
    cout << "\t " << left << setw(15) << p.nombre << "S/." << setw(7) << p.precio << cantidad << endl;
    cout << "\t----------------------------------------" << endl;
    cout << "\t TOTAL A PAGAR:           S/." << fixed << setprecision(2) << total << endl;
    cout << "\t========================================" << endl;
    pausar();
}

int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        limpiarPantalla();
        cout << "\t╔══════════════════════════════════════╗" << endl;
        cout << "\t║       SISTEMA DE INVENTARIO V1.0     ║" << endl;
        cout << "\t╠══════════════════════════════════════╣" << endl;
        cout << "\t║  1. Registrar Nuevo Producto         ║" << endl;
        cout << "\t║  2. Ver Almacen Completo             ║" << endl;
        cout << "\t║  3. Generar Venta (Boleta)           ║" << endl;
        cout << "\t║  4. Salir del Sistema                ║" << endl;
        cout << "\t╚══════════════════════════════════════╝" << endl;
        cout << "\t Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Producto n;
                cout << "\n\tNombre: "; cin.ignore(); getline(cin, n.nombre);
                cout << "\tPrecio: S/."; cin >> n.precio;
                cout << "\tStock: "; cin >> n.stock;
                inventario.push_back(n);
                cout << "\n\t[OK] Producto guardado.";
                pausar();
                break;
            }
            case 2:
                cout << "\n\t--- INVENTARIO ACTUAL ---" << endl;
                if(inventario.empty()) {
                    cout << "\tVacio." << endl;
                } else {
                    for (int i = 0; i < inventario.size(); i++) {
                        cout << "\t" << i+1 << ". " << inventario[i].nombre << " | S/." << inventario[i].precio << " | Cant: " << inventario[i].stock << endl;
                    }
                }
                pausar();
                break;
            case 3: {
                if(inventario.empty()) { 
                    cout << "\tNo hay productos."; 
                    pausar(); 
                    break; 
                }
                int sel, cant; string cli;
                cout << "\tNro de producto: "; cin >> sel;
                cout << "\tCantidad: "; cin >> cant;
                if (sel > 0 && sel <= (int)inventario.size() && inventario[sel-1].stock >= cant) {
                    cout << "\tNombre Cliente: "; cin.ignore(); getline(cin, cli);
                    generarBoleta(cli, inventario[sel-1], cant);
                    inventario[sel-1].stock -= cant;
                } else {
                    cout << "\tError en seleccion o stock."; 
                    pausar();
                }
                break;
            }
        }
    } while (opcion != 4);

    return 0;
}