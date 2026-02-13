#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits> // Necesario para limpiar el buffer de entrada

using namespace std;

// --- ESTRUCTURAS ---
struct Producto {
    string nombre;
    double precio;
    int stock;
};

struct Usuario {
    string username;
    string password;
    string rol; // "admin" o "cliente"
};

// --- FUNCIONES DE LINUX (SOLICITADAS) ---

void limpiarPantalla() {
    system("clear"); // Comando nativo de Linux
}

void pausar() {
    cout << "\n\t Presione ENTER para continuar...";
    cin.get(); // Espera una tecla en Linux (reemplazo de system("pause"))
}

// --- VALIDACIONES ---

// Lee un número y evita que el programa falle si ponen letras o negativos
double leerNumero(string mensaje) {
    double n;
    while (true) {
        cout << mensaje;
        // Valida que sea numero Y que sea mayor o igual a 0
        if (cin >> n && n >= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer (enter residual)
            return n;
        }
        cout << "\t [!] Error: Solo ingrese numeros positivos.\n";
        cin.clear(); // Limpia el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
    }
}

// --- LOGICA DE NEGOCIO ---

void generarBoleta(string cliente, Producto p, int cant) {
    double importe = p.precio * cant;      // Valor de venta
    double igv = importe * 0.18;           // IGV 18%
    double total = importe + igv;          // Total a pagar

    limpiarPantalla();
    cout << "\n\t ╔══════════════════════════════════════════╗" << endl;
    cout << "\t ║            BOLETA ELECTRONICA            ║" << endl;
    cout << "\t ╠══════════════════════════════════════════╣" << endl;
    cout << "\t ║ RUC: 20601234567                         ║" << endl;
    cout << "\t ║ Dir: Av. Universitaria - Tingo Maria     ║" << endl;
    cout << "\t ║ Cliente: " << left << setw(31) << cliente << "║" << endl;
    cout << "\t ╠══════════════════════════════════════════╣" << endl;
    cout << "\t ║ " << left << setw(18) << "PRODUCTO" << setw(8) << "P.UNIT" << setw(6) << "CANT" << setw(8) << "TOTAL" << "║" << endl;
    cout << "\t ║ " << left << setw(18) << p.nombre << setw(8) << p.precio << setw(6) << cant << setw(8) << total << "║" << endl;
    cout << "\t ╠══════════════════════════════════════════╣" << endl;
    cout << "\t ║ IMPORTE:                  S/." << right << setw(10) << fixed << setprecision(2) << importe << " ║" << endl;
    cout << "\t ║ IGV (18%):                S/." << right << setw(10) << igv << " ║" << endl;
    cout << "\t ║ TOTAL A PAGAR:            S/." << right << setw(10) << total << " ║" << endl;
    cout << "\t ╚══════════════════════════════════════════╝" << endl;
    pausar();
}

int main() {
    vector<Producto> inventario;
    vector<Usuario> usuarios;
    
    // Usuario Admin por defecto
    usuarios.push_back({"admin", "1234", "admin"});

    int opcionPrincipal;

    do {
        limpiarPantalla();
        cout << "\t ╔══════════════════════════════════════╗" << endl;
        cout << "\t ║      SISTEMA DE GESTION - UNAS       ║" << endl;
        cout << "\t ╠══════════════════════════════════════╣" << endl;
        cout << "\t ║  1. Iniciar Sesion                   ║" << endl;
        cout << "\t ║  2. Registrarse (Crear cuenta)       ║" << endl;
        cout << "\t ║  3. Salir                            ║" << endl;
        cout << "\t ╚══════════════════════════════════════╝" << endl;
        opcionPrincipal = (int)leerNumero("\t Seleccione opcion: ");

        if (opcionPrincipal == 2) { // REGISTRO
            Usuario nuevo;
            cout << "\t > Cree un Usuario: "; cin >> nuevo.username;
            cout << "\t > Cree una Contraseña: "; cin >> nuevo.password;
            nuevo.rol = "cliente"; // Por defecto todos se crean como clientes
            usuarios.push_back(nuevo);
            cout << "\t [OK] Usuario creado exitosamente.";
            cin.ignore(); pausar();
        } 
        else if (opcionPrincipal == 1) { // LOGIN
            string user, pass;
            Usuario* usuarioActual = nullptr;
            
            cout << "\t > Usuario: "; cin >> user;
            cout << "\t > Contraseña: "; cin >> pass;
            cin.ignore(); // Limpiar el enter que deja el cin >> pass

            // Buscar usuario
            for (int i = 0; i < (int)usuarios.size(); i++) { // Casteo (int) solicitado
                if (usuarios[i].username == user && usuarios[i].password == pass) {
                    usuarioActual = &usuarios[i];
                    break;
                }
            }

            if (usuarioActual != nullptr) {
                int opMenu;
                do {
                    limpiarPantalla();
                    cout << "\t BIEVENIDO: " << usuarioActual->username << " [" << usuarioActual->rol << "]" << endl;
                    cout << "\t ---------------------------------" << endl;

                    if (usuarioActual->rol == "admin") {
                        // MENU ADMIN
                        cout << "\t 1. Agregar Producto" << endl;
                        cout << "\t 2. Modificar Stock" << endl; // Modificar añadido
                        cout << "\t 3. Ver Todo el Inventario" << endl;
                        cout << "\t 4. Cerrar Sesion" << endl;
                        opMenu = (int)leerNumero("\n\t Opcion Admin: ");

                        if (opMenu == 1) {
                            Producto p;
                            cout << "\t Nombre del Producto: "; getline(cin, p.nombre);
                            p.precio = leerNumero("\t Precio Unitario: ");
                            p.stock = (int)leerNumero("\t Stock Inicial: ");
                            inventario.push_back(p);
                            cout << "\t [OK] Producto guardado."; pausar();
                        } 
                        else if (opMenu == 2) {
                            // Modificar Stock
                             if (inventario.empty()) {
                                cout << "\t [!] Inventario vacio.";
                            } else {
                                cout << "\t --- LISTA PARA MODIFICAR ---" << endl;
                                for(int i=0; i<(int)inventario.size(); i++) 
                                    cout << "\t ID " << i+1 << ": " << inventario[i].nombre << " (Stock: " << inventario[i].stock << ")" << endl;
                                
                                int id = (int)leerNumero("\t ID a modificar: ");
                                if (id > 0 && id <= (int)inventario.size()) { // Validacion con casteo
                                    int nuevoStock = (int)leerNumero("\t Nuevo Stock (positivo): ");
                                    inventario[id-1].stock = nuevoStock;
                                    cout << "\t [OK] Stock actualizado.";
                                } else {
                                    cout << "\t [!] ID Incorrecto.";
                                }
                            }
                            pausar();
                        }
                        else if (opMenu == 3) {
                            cout << "\n\t INVENTARIO GENERAL:" << endl;
                            for (int i = 0; i < (int)inventario.size(); i++) { // Casteo (int)
                                cout << "\t " << i + 1 << ". " << inventario[i].nombre 
                                     << " | Precio: S/." << inventario[i].precio 
                                     << " | Stock: " << inventario[i].stock << endl;
                            }
                            pausar();
                        }

                    } else {
                        // MENU CLIENTE
                        cout << "\t 1. Ver Catalogo y Comprar" << endl;
                        cout << "\t 2. Cerrar Sesion" << endl;
                        opMenu = (int)leerNumero("\n\t Opcion Cliente: ");

                        if (opMenu == 1) {
                            if (inventario.empty()) {
                                cout << "\t [!] No hay productos disponibles aun.";
                            } else {
                                cout << "\n\t --- CATALOGO DE PRODUCTOS ---" << endl;
                                for (int i = 0; i < (int)inventario.size(); i++) { // Casteo (int)
                                    cout << "\t " << i + 1 << ". " << inventario[i].nombre 
                                         << " - S/." << inventario[i].precio 
                                         << " (Disp: " << inventario[i].stock << ")" << endl;
                                }
                                
                                int sel = (int)leerNumero("\n\t Ingrese ID del producto a comprar: ");
                                int cant = (int)leerNumero("\t Cantidad a llevar: ");

                                if (sel > 0 && sel <= (int)inventario.size()) { // Validacion rango
                                    if (cant <= inventario[sel-1].stock) {
                                        generarBoleta(usuarioActual->username, inventario[sel-1], cant);
                                        inventario[sel-1].stock -= cant; // Resta stock
                                        cout << "\n\t [OK] Compra realizada y stock actualizado.";
                                    } else {
                                        cout << "\t [!] Error: Stock insuficiente.";
                                    }
                                } else {
                                    cout << "\t [!] Error: ID de producto no existe.";
                                }
                            }
                            pausar();
                        }
                    }

                } while ((usuarioActual->rol == "admin" && opMenu != 4) || (usuarioActual->rol == "cliente" && opMenu != 2));
            } else {
                cout << "\t [!] Usuario o contraseña incorrectos.";
                pausar();
            }
        }

    } while (opcionPrincipal != 3);

    return 0;
}