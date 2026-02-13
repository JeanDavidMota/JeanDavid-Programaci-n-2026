#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

// ================= ESTRUCTURAS =================
struct Producto {
    char codigo[10];
    char descripcion[40];
    char unidad[5];
    int cantidad;
    double precioUnitario;
};

struct Factura {
    char rucCliente[12];
    char nombreCliente[50];
    char direccionCliente[60];
    char fecha[15];
    Producto* productos;
    int numProductos;
};

// ================= VALIDACIONES =================
bool esNumero(const char* cad) {
    for (int i = 0; cad[i]; i++)
        if (cad[i] < '0' || cad[i] > '9') return false;
    return true;
}

bool esFechaValida(const char* cad) {
    for (int i = 0; cad[i]; i++)
        if (!((cad[i] >= '0' && cad[i] <= '9') || cad[i] == '-'))
            return false;
    return true;
}

bool esSoloLetras(const char* cad) {
    for (int i = 0; cad[i]; i++)
        if (!((cad[i] >= 'A' && cad[i] <= 'Z') || 
              (cad[i] >= 'a' && cad[i] <= 'z') || 
              cad[i] == ' '))
            return false;
    return true;
}

int leerEntero(const char* msg) {
    char cad[20];
    do {
        cout << msg;
        cin >> cad;
        cin.ignore();
    } while (!esNumero(cad));
    return atoi(cad);
}

double leerDouble(const char* msg) {
    char cad[20];
    bool invalido;
    do {
        invalido = false;
        cout << msg;
        cin >> cad;
        cin.ignore();
        for (int i = 0; cad[i]; i++)
            if ((cad[i] < '0' || cad[i] > '9') && cad[i] != '.') invalido = true;
    } while (invalido);
    return atof(cad);
}

void leerCadenaNumerica(const char* msg, char* dest) {
    do {
        cout << msg;
        cin >> dest;
        cin.ignore();
    } while (!esNumero(dest));
}

void leerNombre(const char* msg, char* dest) {
    do {
        cout << msg;
        cin.getline(dest, 50);
    } while (!esSoloLetras(dest));
}

void leerFecha(const char* msg, char* dest) {
    do {
        cout << msg;
        cin >> dest;
        cin.ignore();
    } while (!esFechaValida(dest));
}

// ================= LOGIN =================
bool login() {
    char user[20], pass[20];

    while (true) {
        cout << "+--------------------------------------+\n";
        cout << "|              LOGIN SISTEMA           |\n";
        cout << "+--------------------------------------+\n";
        cout << "| Usuario : ";
        cin >> user;
        cout << "| Clave   : ";
        cin >> pass;
        cin.ignore();

        if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
            return true;
        } else {
            cout << "Usuario y/o contrasena incorrecta\n\n";
        }
    }
}

// ================= GUARDAR FACTURA =================
void guardarFactura(Factura& f) {
    ofstream file("facturas.txt", ios::app);

    file << f.rucCliente << endl;
    file << f.fecha << endl;
    file << f.nombreCliente << endl;
    file << f.direccionCliente << endl;
    file << f.numProductos << endl;

    for (int i = 0; i < f.numProductos; i++) {
        file << f.productos[i].codigo << "|"
             << f.productos[i].descripcion << "|"
             << f.productos[i].unidad << "|"
             << f.productos[i].cantidad << "|"
             << f.productos[i].precioUnitario << endl;
    }
    file << "----" << endl;
    file.close();
}

// ================= IMPRIMIR FACTURA =================
void imprimirFacturaASCII(Factura& f) {
    double total = 0;

    cout << "\n+==================================================================================+\n";
    cout << "|  EMPRESA ALL IN ONE STORE S.A.C.    +-----------------------------------------+  |\n";
    cout << "|  Av. Alameda Peru - Tingo Maria     | RUC: 20123456789                        |  |\n";
    cout << "|  Tel: 987654321                     | FACTURA ELECTRONICA                     |  |\n";
    cout << "|  Email: allinonestore@empresa.com   | F001-000123                             |  |\n";
    cout << "|  Web: www.allinonestore.com         +-----------------------------------------+  |\n";

    cout << "|  +----------------------------------------------------------------------------+  |\n";
    cout << "|  | Emision      : " << setw(58) << left << f.fecha << "  |  |\n"; 
    cout << "|  | Cliente      : " << setw(58) << f.nombreCliente << "  |  |\n";
    cout << "|  | RUC          : " << setw(58) << f.rucCliente << "  |  |\n";
    cout << "|  | Direccion    : " << setw(58) << f.direccionCliente << "  |  |\n";
    cout << "|  +----------------------------------------------------------------------------+  |\n";

    cout << "|  +----------------------------------------------------------------------------+  |\n";
    cout << "|  | Cant | Und | Codigo | Descripcion                   | P.Unit | Total       |  |\n";
    cout << "|  +------+-----+--------+-------------------------------+--------+-------------+  |\n";

    for (int i = 0; i < f.numProductos; i++) {
        double sub = f.productos[i].cantidad * f.productos[i].precioUnitario;
        total += sub;

        cout << "|  | " << setw(4) << f.productos[i].cantidad
             << " | " << setw(3) << f.productos[i].unidad
             << " | " << setw(6) << f.productos[i].codigo
             << " | " << setw(29) << left << f.productos[i].descripcion
             << " | " << setw(6) << fixed << setprecision(2)
             << f.productos[i].precioUnitario
             << " | " << setw(11) << sub << " |  |\n";
    }

    cout << "|  +----------------------------------------------------------------------------+  |\n";

    double igv = total * 0.18;

    cout << "|                                                  OP. GRAVADA   (S/): "
         << setw(10) << total << "  |\n";
    cout << "|                                                  TOTAL IGV 18% (S/): "
         << setw(10) << igv << "  |\n";
    cout << "|                                                  IMPORTE TOTAL (S/): "
         << setw(10) << total + igv << "  |\n";

    cout << "+==================================================================================+\n";
}

// ================= BUSCAR FACTURA =================
void buscarFactura() {
    ifstream file("facturas.txt");
    if (!file) {
        cout << "Archivo no existe.\n";
        return;
    }

    cout << "+--------------------------------------+\n";
    cout << "|        BUSCAR FACTURA POR            |\n";
    cout << "+--------------------------------------+\n";
    cout << "| 1. RUC del cliente                   |\n";
    cout << "| 2. Nombre del cliente                |\n";
    cout << "+--------------------------------------+\n";
    cout << "Opcion: ";

    int tipoBusqueda;
    cin >> tipoBusqueda;
    cin.ignore();

    char rucBuscado[12] = "";
    char nombreBuscado[50] = "";

    if (tipoBusqueda == 1) {
        leerCadenaNumerica("| RUC Cliente: ", rucBuscado);
    } else if (tipoBusqueda == 2) {
        leerNombre("| Nombre del cliente: ", nombreBuscado);
    } else {
        return; // opción incorrecta no muestra nada
    }

    while (!file.eof()) {
        Factura f;
        file >> f.rucCliente;
        if (file.eof()) break;

        file >> f.fecha;
        file.ignore();
        file.getline(f.nombreCliente, 50);
        file.getline(f.direccionCliente, 60);
        file >> f.numProductos;

        f.productos = new Producto[f.numProductos];

        for (int i = 0; i < f.numProductos; i++) {
            file.get();
            file.getline(f.productos[i].codigo, 10, '|');
            file.getline(f.productos[i].descripcion, 40, '|');
            file.getline(f.productos[i].unidad, 5, '|');
            file >> f.productos[i].cantidad;
            file.get();
            file >> f.productos[i].precioUnitario;
        }

        bool encontrada = false;

        if (tipoBusqueda == 1 && strcmp(f.rucCliente, rucBuscado) == 0)
            encontrada = true;

        if (tipoBusqueda == 2 && strcmp(f.nombreCliente, nombreBuscado) == 0)
            encontrada = true;

        if (encontrada) {
            imprimirFacturaASCII(f);
            delete[] f.productos;
            file.close();
            return;
        }

        delete[] f.productos;
        file.ignore(100, '\n');
    }

    cout << "Factura no encontrada.\n";
    file.close();
}

// ================= REGISTRAR FACTURA =================
void registrarFactura() {
    Factura f;

    cout << "+--------------------------------------+\n";
    cout << "|         REGISTRAR FACTURA            |\n";
    cout << "+--------------------------------------+\n";

    leerCadenaNumerica("| RUC Cliente: ", f.rucCliente);
    leerFecha("| Fecha (AAAA-MM-DD): ", f.fecha);
    leerNombre("| Nombre Cliente: ", f.nombreCliente);

    cout << "| Direccion Cliente: ";
    cin.getline(f.direccionCliente, 60);

    f.numProductos = leerEntero("| Cantidad de productos: ");
    f.productos = new Producto[f.numProductos];

    for (int i = 0; i < f.numProductos; i++) {
        cout << "+--------------------------------------+\n";
        cout << "|          REGISTRO DE PRODUCTO        |\n";
        cout << "+--------------------------------------+\n";

        cout << "| Codigo          : ";
        cin >> f.productos[i].codigo;
        cin.ignore();

        cout << "| Descripcion     : ";
        cin.getline(f.productos[i].descripcion, 40);

        cout << "| Unidad          : ";
        cin >> f.productos[i].unidad;

        f.productos[i].cantidad = leerEntero("| Cantidad        : ");
        f.productos[i].precioUnitario = leerDouble("| Precio Unitario : ");

        cout << "+--------------------------------------+\n";
    }

    guardarFactura(f);
    delete[] f.productos;

    cout << "Factura registrada correctamente.\n";
}

// ================= MAIN =================
int main() {
    login();

    int op;
    do {
        cout << "+--------------------------------------+\n";
        cout << "|           MENU PRINCIPAL             |\n";
        cout << "+--------------------------------------+\n";
        cout << "| 1. Registrar factura                 |\n";
        cout << "| 2. Buscar factura                    |\n";
        cout << "| 0. Salir                             |\n";
        cout << "+--------------------------------------+\n";
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        if (op == 1)
            registrarFactura();
        else if (op == 2)
            buscarFactura();
        // Opciones incorrectas no muestran nada y vuelven a mostrar menú
    } while (op != 0);

    return 0;
}
