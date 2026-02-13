#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <unistd.h> // Para usleep en Linux

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
    string rol;
};
struct DetalleVenta {
    string nombre;
    double precioUnitario;
    int cantidad;
    double totalLinea;
};

// --- UTILIDADES LINUX CORREGIDAS ---
void limpiarPantalla() { 
    // \033[2J limpia pantalla, \033[1;1H mueve cursor, \033[3J borra historial de scroll
    cout << "\033[2J\033[1;1H\033[3J" << flush; 
}

void escribirAnimado(string texto) {
    for (char c : texto) {
        cout << c << flush;
        usleep(15000); // Velocidad de escritura
    }
    cout << endl;
}

void pausar() { 
    cout << "\n\t \033[1;33mPresione ENTER para continuar...\033[0m"; 
    cin.clear();
    // Solo ignora si hay algo en el buffer
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.get(); 
    limpiarPantalla();
}

// --- VALIDACIONES ---
double leerNumero(string mensaje) {
    double n;
    while (true) {
        cout << mensaje;
        if (cin >> n && n >= 0) return n;
        cout << "\t \033[1;31m[!] Error: Ingrese un numero positivo.\033[0m\n";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// --- FUNCIONES DE DISEÑO ---
void dibujarCabecera(string titulo) {
    cout << "\t \033[1;36m╔══════════════════════════════════════════════════════╗" << endl;
    cout << "\t ║ " << left << setw(52) << titulo << " ║" << endl;
    cout << "\t ╚══════════════════════════════════════════════════════╝\033[0m" << endl;
}

// --- LÓGICA DE VENTA CON CARRITO ---
void realizarVenta(vector<Producto> &inventario, string vendedor) {
    vector<DetalleVenta> carrito;
    char continuar = 's';
    double totalVenta = 0.0;

    do {
        limpiarPantalla();
        dibujarCabecera("NUEVA VENTA - AGREGAR PRODUCTOS");
        
        cout << "\t ┌────┬──────────────────────┬──────────┬───────┐" << endl;
        cout << "\t │ ID │ PRODUCTO             │ PRECIO   │ STOCK │" << endl;
        cout << "\t ├────┼──────────────────────┼──────────┼───────┤" << endl;
        if(inventario.empty()) {
            cout << "\t │    │ (Inventario Vacio)   │          │       │" << endl;
        }
        for(size_t i=0; i<inventario.size(); i++) {
            cout << "\t │ " << left << setw(3) << i+1 
                 << "│ " << setw(20) << inventario[i].nombre 
                 << " │ S/." << setw(5) << inventario[i].precio 
                 << " │ " << setw(5) << inventario[i].stock << " │" << endl;
        }
        cout << "\t └────┴──────────────────────┴──────────┴───────┘" << endl;

        if(inventario.empty()) { pausar(); return; }

        int id = (int)leerNumero("\n\t \033[1;32m>\033[0m Ingrese ID del producto: ");
        if (id > 0 && id <= (int)inventario.size()) {
            if (inventario[id-1].stock > 0) {
                int cant = (int)leerNumero("\t \033[1;32m>\033[0m Cantidad a vender: ");
                
                if (cant > 0 && cant <= inventario[id-1].stock) {
                    DetalleVenta item;
                    item.nombre = inventario[id-1].nombre;
                    item.precioUnitario = inventario[id-1].precio;
                    item.cantidad = cant;
                    item.totalLinea = item.precioUnitario * cant;
                    
                    carrito.push_back(item);
                    totalVenta += item.totalLinea;
                    inventario[id-1].stock -= cant; 

                    cout << "\t \033[1;32m[OK]\033[0m Agregado: " << item.nombre << " (x" << cant << ")" << endl;
                } else {
                    cout << "\t \033[1;31m[!] Stock insuficiente.\033[0m" << endl;
                }
            } else {
                cout << "\t \033[1;31m[!] Producto agotado.\033[0m" << endl;
            }
        } else {
            cout << "\t \033[1;31m[!] ID Incorrecto.\033[0m" << endl;
        }
        
        cout << "\n\t ¿Agregar otro producto? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    if (!carrito.empty()) {
        double igv = totalVenta * 0.18;
        double totalPagar = totalVenta + igv;

        limpiarPantalla();
        escribirAnimado("\t \033[1;35mGenerando comprobante fiscal...\033[0m");
        usleep(500000);

        cout << "\n\t \033[1;37m╔══════════════════════════════════════════════════════╗" << endl;
        cout << "\t ║                 \033[1;33mBOLETA ELECTRONICA\033[1;37m                   ║" << endl;
        cout << "\t ╠══════════════════════════════════════════════════════╣" << endl;
        cout << "\t ║ RUC: 20601234567                                     ║" << endl;
        cout << "\t ║ Vendedor: " << left << setw(42) << vendedor << " ║" << endl;
        cout << "\t ╠══════════════════════════════════════════════════════╣" << endl;
        cout << "\t ║ CANT   DESCRIPCION             P.UNIT      IMPORTE   ║" << endl;
        cout << "\t ╠══════════════════════════════════════════════════════╣" << endl;

        for (const auto& item : carrito) {
            cout << "\t ║ " << left << setw(6) << item.cantidad 
                 << " " << setw(23) << item.nombre 
                 << " S/." << setw(8) << fixed << setprecision(2) << item.precioUnitario 
                 << " S/." << setw(8) << item.totalLinea << " ║" << endl;
        }

        cout << "\t ╠══════════════════════════════════════════════════════╣" << endl;
        cout << "\t ║ \033[1;32mSUB-TOTAL:                          S/." << right << setw(11) << totalVenta << "\033[1;37m ║" << endl;
        cout << "\t ║ IGV (18%):                          S/." << right << setw(11) << igv << " ║" << endl;
        cout << "\t ║ \033[1;33mTOTAL A PAGAR:                      S/." << right << setw(11) << totalPagar << "\033[1;37m ║" << endl;
        cout << "\t ╚══════════════════════════════════════════════════════╝\033[0m" << endl;
        pausar();
    }
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    vector<Producto> inventario;
    vector<Usuario> usuarios;

    usuarios.push_back({"gerente", "1234", "gerente"});
    usuarios.push_back({"operador", "1234", "operador"});

    limpiarPantalla();
    cout << "\033[1;32m";
    escribirAnimado(">> [SYS] Iniciando entorno Linux...");
    escribirAnimado(">> [SYS] Cargando modulos de Ingenieria de Sistemas...");
    escribirAnimado(">> [SYS] Sistema de Jean David Mota Garcia Listo.");
    cout << "\033[0m";
    usleep(800000);

    bool salirPrograma = false;
    while (!salirPrograma) {
        limpiarPantalla();
        dibujarCabecera("     SISTEMA DE GESTION - BIENVENIDO");
        cout << "\t ║ 1. Ingresar como \033[1;34mGERENTE\033[0m                             ║" << endl;
        cout << "\t ║ 2. Ingresar como \033[1;35mOPERADOR\033[0m                            ║" << endl;
        cout << "\t ║ 3. \033[1;31mSalir del Sistema\033[0m                                 ║" << endl;
        cout << "\t ╚══════════════════════════════════════════════════════╝" << endl;
        
        int opcionRol = (int)leerNumero("\t \033[1;32m>\033[0m Seleccione una opcion: ");

        if (opcionRol == 3) break;
        if (opcionRol != 1 && opcionRol != 2) { cout << "\t \033[1;31m[!] Opcion invalida.\033[0m"; pausar(); continue; }

        string rolEsperado = (opcionRol == 1) ? "gerente" : "operador";
        
        limpiarPantalla();
        dibujarCabecera("     LOGIN DE ACCESO: " + rolEsperado);
        string u, p;
        Usuario* usuarioActual = nullptr;
        cout << "\t \033[1;32m>\033[0m Usuario: "; cin >> u;
        cout << "\t \033[1;32m>\033[0m Contraseña: "; cin >> p;

        for (auto &usr : usuarios) {
            if (usr.username == u && usr.password == p && usr.rol == rolEsperado) {
                usuarioActual = &usr;
                break;
            }
        }

        if (!usuarioActual) { cout << "\t \033[1;31m[!] Acceso denegado.\033[0m"; pausar(); continue; }

        bool cerrarSesion = false;
        while (!cerrarSesion) {
            limpiarPantalla();
            if (rolEsperado == "gerente") {
                dibujarCabecera("     MENU PRINCIPAL - GERENTE");
                cout << "\t ║ 1. Añadir Nuevo Usuario                              ║" << endl;
                cout << "\t ║ 2. Ingresar Producto                                 ║" << endl;
                cout << "\t ║ 3. Mostrar Inventario                                ║" << endl;
                cout << "\t ║ 4. Modificar Stock                                   ║" << endl;
                cout << "\t ║ 5. \033[1;31mCerrar Sesion\033[0m                                     ║" << endl;
                cout << "\t ╚══════════════════════════════════════════════════════╝" << endl;
                
                int op = (int)leerNumero("\t \033[1;32m>\033[0m Opcion: ");
                
                if (op == 1) { 
                     Usuario n; 
                     cout << "\n\t \033[1;34m--- NUEVO USUARIO ---\033[0m\n";
                     cout << "\t > Username: "; cin >> n.username; 
                     cout << "\t > Password: "; cin >> n.password;
                     cout << "\t > Rol (1=Gerente, 2=Operador): "; 
                     int r = (int)leerNumero(""); 
                     while(r!=1 && r!=2) r=(int)leerNumero("\t (1 o 2): ");
                     n.rol=(r==1)?"gerente":"operador";
                     usuarios.push_back(n);
                     cout << "\t \033[1;32m[OK]\033[0m Usuario creado."; pausar();
                }
                else if (op == 2) { 
                    Producto pr; 
                    cout << "\n\t \033[1;34m--- NUEVO PRODUCTO ---\033[0m\n";
                    cout << "\t > Nombre: "; cin.ignore(); getline(cin, pr.nombre);
                    pr.precio=leerNumero("\t > Precio: S/."); 
                    pr.stock=(int)leerNumero("\t > Stock: ");
                    inventario.push_back(pr);
                    cout << "\t \033[1;32m[OK]\033[0m Guardado."; pausar();
                }
                else if (op == 3) {
                    limpiarPantalla();
                    dibujarCabecera("INVENTARIO GENERAL");
                    cout << "\t ┌────┬──────────────────────┬──────────┬───────┐" << endl;
                    cout << "\t │ ID │ PRODUCTO             │ PRECIO   │ STOCK │" << endl;
                    cout << "\t ├────┼──────────────────────┼──────────┼───────┤" << endl;
                    if(inventario.empty()) cout << "\t │    │ (Vacio)              │          │       │" << endl;
                    for(size_t i=0; i<inventario.size(); i++)
                        cout << "\t │ " << left << setw(3) << i+1 << "│ " << setw(20) << inventario[i].nombre << " │ S/." << setw(5) << inventario[i].precio << " │ " << setw(5) << inventario[i].stock << " │" << endl;
                    cout << "\t └────┴──────────────────────┴──────────┴───────┘" << endl;
                    pausar();
                }
                else if (op == 4) {
                     int id=(int)leerNumero("\t \033[1;32m>\033[0m ID Producto: "); 
                     if(id>0 && id<=(int)inventario.size()) {
                        cout << "\t Stock actual: " << inventario[id-1].stock << endl;
                        inventario[id-1].stock=(int)leerNumero("\t \033[1;32m>\033[0m Nuevo Stock: ");
                        cout << "\t \033[1;32m[OK]\033[0m Actualizado.";
                     } else cout << "\t \033[1;31m[!] ID Invalido.\033[0m";
                     pausar();
                }
                else if (op == 5) cerrarSesion = true;
            } 
            else { // OPERADOR
                dibujarCabecera("     MENU PRINCIPAL - OPERADOR");
                cout << "\t ║ 1. Ver Catalogo                                      ║" << endl;
                cout << "\t ║ 2. Realizar Venta (Carrito)                          ║" << endl;
                cout << "\t ║ 3. \033[1;31mCerrar Sesion\033[0m                                     ║" << endl;
                cout << "\t ╚══════════════════════════════════════════════════════╝" << endl;
                
                int op = (int)leerNumero("\t \033[1;32m>\033[0m Opcion: ");
                
                if (op == 1) {
                    limpiarPantalla();
                    dibujarCabecera("CATALOGO DE PRODUCTOS");
                    cout << "\t ┌────┬──────────────────────┬──────────┬───────┐" << endl;
                    cout << "\t │ ID │ PRODUCTO             │ PRECIO   │ STOCK │" << endl;
                    cout << "\t ├────┼──────────────────────┼──────────┼───────┤" << endl;
                    if(inventario.empty()) cout << "\t │    │ (Vacio)              │          │       │" << endl;
                    for(size_t i=0; i<inventario.size(); i++)
                        cout << "\t │ " << left << setw(3) << i+1 << "│ " << setw(20) << inventario[i].nombre << " │ S/." << setw(5) << inventario[i].precio << " │ " << setw(5) << inventario[i].stock << " │" << endl;
                    cout << "\t └────┴──────────────────────┴──────────┴───────┘" << endl;
                    pausar();
                }
                else if (op == 2) {
                    if(inventario.empty()) { cout << "\t \033[1;31m[!] Inventario vacio.\033[0m"; pausar(); }
                    else realizarVenta(inventario, usuarioActual->username);
                }
                else if (op == 3) cerrarSesion = true;
            }
        }
    }
    limpiarPantalla();
    cout << "\033[1;31m";
    escribirAnimado(">> [SYS] Cerrando sesion de Jean David...");
    escribirAnimado(">> [SYS] Sistema Apagado.");
    cout << "\033[0m";
    return 0;
}