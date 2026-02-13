#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
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

// --- UTILIDADES LINUX ---
void limpiarPantalla() { system("clear"); }
void pausar() { 
    cout << "\n\t Presione ENTER para continuar..."; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get(); 
}

// --- VALIDACIONES ---
double leerNumero(string mensaje) {
    double n;
    while (true) {
        cout << mensaje;
        if (cin >> n && n >= 0) return n;
        cout << "\t [!] Error: Ingrese un numero positivo.\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// --- FUNCIONES DE DISEÑO ---
void dibujarCabecera(string titulo) {
    limpiarPantalla();
    cout << "\t ╔══════════════════════════════════════════════════════╗" << endl;
    cout << "\t ║ " << left << setw(52) << titulo << " ║" << endl;
    cout << "\t ╚══════════════════════════════════════════════════════╝" << endl;
}

// --- LÓGICA DE VENTA CON CARRITO ---
void realizarVenta(vector<Producto> &inventario, string vendedor) {
    vector<DetalleVenta> carrito;
    char continuar = 's';
    double totalVenta = 0.0;

    do {
        dibujarCabecera("NUEVA VENTA - AGREGAR PRODUCTOS");
        
        // Mostrar inventario con diseño
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

        int id = (int)leerNumero("\n\t > Ingrese ID del producto: ");
        if (id > 0 && id <= (int)inventario.size()) {
            if (inventario[id-1].stock > 0) {
                int cant = (int)leerNumero("\t > Cantidad a vender: ");
                
                if (cant > 0 && cant <= inventario[id-1].stock) {
                    // Agregar al carrito
                    DetalleVenta item;
                    item.nombre = inventario[id-1].nombre;
                    item.precioUnitario = inventario[id-1].precio;
                    item.cantidad = cant;
                    item.totalLinea = item.precioUnitario * cant;
                    
                    carrito.push_back(item);
                    totalVenta += item.totalLinea;
                    inventario[id-1].stock -= cant; // Restar stock temporalmente

                    cout << "\t [OK] Agregado: " << item.nombre << " (x" << cant << ")" << endl;
                } else {
                    cout << "\t [!] Stock insuficiente." << endl;
                }
            } else {
                cout << "\t [!] Producto agotado." << endl;
            }
        } else {
            cout << "\t [!] ID Incorrecto." << endl;
        }
        
        cout << "\n\t ¿Agregar otro producto? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    // --- IMPRIMIR BOLETA FINAL ---
    if (!carrito.empty()) {
        double igv = totalVenta * 0.18;
        double totalPagar = totalVenta + igv;

        limpiarPantalla();
        cout << "\n\t ╔══════════════════════════════════════════════════════╗" << endl;
        cout << "\t ║                 BOLETA ELECTRONICA                   ║" << endl;
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
        cout << "\t ║ SUB-TOTAL:                          S/." << right << setw(11) << totalVenta << " ║" << endl;
        cout << "\t ║ IGV (18%):                          S/." << right << setw(11) << igv << " ║" << endl;
        cout << "\t ║ TOTAL A PAGAR:                      S/." << right << setw(11) << totalPagar << " ║" << endl;
        cout << "\t ╚══════════════════════════════════════════════════════╝" << endl;
        pausar();
    }
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    vector<Producto> inventario;
    vector<Usuario> usuarios;

    // Usuarios iniciales
    usuarios.push_back({"gerente", "1234", "gerente"});
    usuarios.push_back({"operador", "1234", "operador"});

    bool salirPrograma = false;

    while (!salirPrograma) {
        dibujarCabecera("     SISTEMA DE GESTION - BIENVENIDO");
        cout << "\t ║ 1. Ingresar como GERENTE                             ║" << endl;
        cout << "\t ║ 2. Ingresar como OPERADOR                            ║" << endl;
        cout << "\t ║ 3. Salir del Sistema                                 ║" << endl;
        cout << "\t ╚══════════════════════════════════════════════════════╝" << endl;
        
        int opcionRol = (int)leerNumero("\t > Seleccione una opcion: ");

        if (opcionRol == 3) break;
        if (opcionRol != 1 && opcionRol != 2) { cout << "\t [!] Opcion invalida."; pausar(); continue; }

        string rolEsperado = (opcionRol == 1) ? "gerente" : "operador";
        
        // LOGIN
        dibujarCabecera("     LOGIN DE ACCESO: " + rolEsperado);
        string u, p;
        Usuario* usuarioActual = nullptr;
        cout << "\t > Usuario: "; cin >> u;
        cout << "\t > Contraseña: "; cin >> p;

        for (auto &usr : usuarios) {
            if (usr.username == u && usr.password == p && usr.rol == rolEsperado) {
                usuarioActual = &usr;
                break;
            }
        }

        if (!usuarioActual) { cout << "\t [!] Acceso denegado."; pausar(); continue; }

        // MENUS DE USUARIO
        bool cerrarSesion = false;
        while (!cerrarSesion) {
            if (rolEsperado == "gerente") {
                dibujarCabecera("     MENU PRINCIPAL - GERENTE");
                cout << "\t ║ 1. Añadir Nuevo Usuario                              ║" << endl;
                cout << "\t ║ 2. Ingresar Producto                                 ║" << endl;
                cout << "\t ║ 3. Mostrar Inventario                                ║" << endl;
                cout << "\t ║ 4. Modificar Stock                                   ║" << endl;
                cout << "\t ║ 5. Cerrar Sesion                                     ║" << endl;
                cout << "\t ╚══════════════════════════════════════════════════════╝" << endl;
                
                int op = (int)leerNumero("\t > Opcion: ");
                
                if (op == 1) { 
                     Usuario n; 
                     cout << "\n\t --- NUEVO USUARIO ---\n";
                     cout << "\t > Username: "; cin >> n.username; 
                     cout << "\t > Password: "; cin >> n.password;
                     cout << "\t > Rol (1=Gerente, 2=Operador): "; 
                     int r = (int)leerNumero(""); 
                     while(r!=1 && r!=2) r=(int)leerNumero("\t (1 o 2): ");
                     n.rol=(r==1)?"gerente":"operador";
                     usuarios.push_back(n);
                     cout << "\t [OK] Usuario creado."; pausar();
                }
                else if (op == 2) { 
                    Producto pr; 
                    cout << "\n\t --- NUEVO PRODUCTO ---\n";
                    cout << "\t > Nombre: "; cin.ignore(); getline(cin, pr.nombre);
                    pr.precio=leerNumero("\t > Precio: S/."); 
                    pr.stock=(int)leerNumero("\t > Stock: ");
                    inventario.push_back(pr);
                    cout << "\t [OK] Guardado."; pausar();
                }
                else if (op == 3) {
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
                     int id=(int)leerNumero("\t > ID Producto: "); 
                     if(id>0 && id<=(int)inventario.size()) {
                        cout << "\t Stock actual: " << inventario[id-1].stock << endl;
                        inventario[id-1].stock=(int)leerNumero("\t > Nuevo Stock: ");
                        cout << "\t [OK] Actualizado.";
                     } else cout << "\t [!] ID Invalido.";
                     pausar();
                }
                else if (op == 5) cerrarSesion = true;
            } 
            else { // OPERADOR
                dibujarCabecera("     MENU PRINCIPAL - OPERADOR");
                cout << "\t ║ 1. Ver Catalogo                                      ║" << endl;
                cout << "\t ║ 2. Realizar Venta (Carrito)                          ║" << endl;
                cout << "\t ║ 3. Cerrar Sesion                                     ║" << endl;
                cout << "\t ╚══════════════════════════════════════════════════════╝" << endl;
                
                int op = (int)leerNumero("\t > Opcion: ");
                
                if (op == 1) {
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
                    if(inventario.empty()) { cout << "\t [!] Inventario vacio."; pausar(); }
                    else realizarVenta(inventario, usuarioActual->username);
                }
                else if (op == 3) cerrarSesion = true;
            }
        }
    }
    return 0;
}