#include <iostream>
#include <string>
using namespace std;
struct Producto {
    int codigo;
    string nombre;
    float precio;
    int stock;
};
const int MAX = 50; 
Producto inventario[MAX];
int contador = 0;
void registrar();
void mostrar();
void buscarPorCodigo();
void buscarPorNombre();
void mayorStock();
void masCaro();
void calcularTotal();
void ordenarPorPrecio(); 
void ordenarPorNombre(); 
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
        cout << "9. Ordenar por precio (Mayor a Menor)" << endl;
        cout << "10. Ordenar por nombre (A-Z)" << endl;
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
            case 9: ordenarPorPrecio(); break;
            case 10: ordenarPorNombre(); break;
            case 8: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }
    } while(opcion != 8);
    return 0;
}
void registrar() {
    if (contador >= MAX) {
        cout << "Error: Inventario lleno." << endl;
        return;
    }
    cout << "\n--- REGISTRO DE PRODUCTO #" << contador + 1 << " ---" << endl;
    cout << "Codigo: "; cin >> inventario[contador].codigo;
    cout << "Nombre: "; cin.ignore(); getline(cin, inventario[contador].nombre);
    do {
        cout << "Precio (mayor a 0): "; cin >> inventario[contador].precio;
        if (inventario[contador].precio <= 0) cout << "Dato invalido. Intente de nuevo." << endl;
    } while (inventario[contador].precio <= 0);
    do {
        cout << "Stock (no negativo): "; cin >> inventario[contador].stock;
        if (inventario[contador].stock < 0) cout << "Dato invalido. Intente de nuevo." << endl;
    } while (inventario[contador].stock < 0);
    contador++;
    cout << "Producto registrado exitosamente." << endl;
}
void mostrar() {
    if (contador == 0) {
        cout << "Inventario vacio." << endl;
        return;
    }
    cout << "\nCOD\tNOMBRE\t\tPRECIO\tSTOCK" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < contador; i++) {
        cout << inventario[i].codigo << "\t" 
             << inventario[i].nombre << "\t\t" 
             << inventario[i].precio << "\t" 
             << inventario[i].stock << endl;
    }
}
void buscarPorCodigo() {
    int cod;
    bool encontrado = false;
    cout << "Ingrese codigo a buscar: "; cin >> cod;
    for (int i = 0; i < contador; i++) {
        if (inventario[i].codigo == cod) {
            cout << "Encontrado -> " << inventario[i].nombre << " | Stock: " << inventario[i].stock << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) cout << "No encontrado" << endl;
}
void buscarPorNombre() {
    string nom;
    bool encontrado = false;
    cout << "Ingrese nombre a buscar: "; cin.ignore(); getline(cin, nom);
    for (int i = 0; i < contador; i++) {
        if (inventario[i].nombre == nom) {
            cout << "Encontrado -> Codigo: " << inventario[i].codigo << " | Precio: " << inventario[i].precio << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) cout << "No encontrado" << endl;
}
void mayorStock() {
    if (contador == 0) return;
    int index = 0;
    for (int i = 1; i < contador; i++) {
        if (inventario[i].stock > inventario[index].stock) index = i;
    }
    cout << "Producto con mayor stock: " << inventario[index].nombre << " (" << inventario[index].stock << ")" << endl;
}
void masCaro() {
    if (contador == 0) return;
    int index = 0;
    for (int i = 1; i < contador; i++) {
        if (inventario[i].precio > inventario[index].precio) index = i;
    }
    cout << "Producto mas caro: " << inventario[index].nombre << " ($" << inventario[index].precio << ")" << endl;
}
void calcularTotal() {
    float total = 0;
    for (int i = 0; i < contador; i++) {
        total += (inventario[i].precio * inventario[i].stock);
    }
    cout << "Valor total del inventario: $" << total << endl;
}
void ordenarPorPrecio() {
    if (contador < 2) return;
    for (int i = 0; i < contador - 1; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (inventario[j].precio < inventario[j + 1].precio) {
                Producto aux = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = aux;
            }
        }
    }
    cout << "Ordenado por precio (Mayor a Menor) con exito." << endl;
}
void ordenarPorNombre() {
    if (contador < 2) return;
    for (int i = 0; i < contador - 1; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (inventario[j].nombre > inventario[j + 1].nombre) {
                Producto aux = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = aux;
            }
        }
    }
    cout << "Ordenado por nombre (A-Z) con exito." << endl;
}