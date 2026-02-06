#include <iostream>
#include <string>
using namespace std;
struct Producto {
    int codigo;
    string nombre;
    float precio;
    int stock;
};
Producto inventario[100]; 
int contador = 0;
void registrar() {
    cout << "--- Registro de Producto ---" << endl;
    cout << "Codigo: "; cin >> inventario[contador].codigo;
    cout << "Nombre: "; cin >> inventario[contador].nombre;
    do {
        cout << "Precio: "; cin >> inventario[contador].precio;
        if (inventario[contador].precio <= 0) cout << "Error: El precio debe ser mayor a 0." << endl;
    } while (inventario[contador].precio <= 0);
    do {
        cout << "Stock: "; cin >> inventario[contador].stock;
        if (inventario[contador].stock < 0) cout << "Error: El stock no puede ser negativo." << endl;
    } while (inventario[contador].stock < 0);
    contador++;
    cout << "Producto guardado con exito." << endl;
}
void mostrar() {
    cout << "\n--- Lista de Productos ---" << endl;
    for (int i = 0; i < contador; i++) {
        cout << "Cod: " << inventario[i].codigo << " | "
             << "Nom: " << inventario[i].nombre << " | "
             << "Precio: " << inventario[i].precio << " | "
             << "Stock: " << inventario[i].stock << endl;
    }
}
int main() {
    int opcion;
    do {
        cout << "\n--- MENU DE TIENDA ---" << endl;
        cout << "1. Registrar productos" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Buscar producto por codigo" << endl;
        cout << "4. Buscar producto por nombre" << endl;
        cout << "5. Mostrar producto con mayor stock" << endl;
        cout << "6. Mostrar producto mas caro" << endl;
        cout << "7. Calcular valor total del inventario" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: registrar(); break;
            case 2: mostrar(); break;
            case 3: buscarPorCodigo(); break;
            case 4: buscarPorNombre(); break;
            case 5: mayorStock(); break;
            case 6: masCaro(); break;
            case 7: calcularTotal(); break;
            case 8: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opcion no valida, intente de nuevo." << endl;
        }
    } while(opcion != 8);
    return 0;
}