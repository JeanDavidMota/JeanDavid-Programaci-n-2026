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
    string rol; // "gerente" o "operador"
};

// --- UTILIDADES PARA LINUX ---
void limpiarPantalla() {
    system("clear");
}

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
        if (cin >> n && n >= 0) {
            return n;
        }
        cout << "\t [!] Error: Solo numeros positivos.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// --- BOLETA ---
void generarBoleta(string vendedor, Producto p, int cant) {
    double importe = p.precio * cant;
    double igv = importe * 0.18;
    double total = importe + igv;

    limpiarPantalla();
    cout << "\n\t ╔══════════════════════════════════════════╗" << endl;
    cout << "\t ║            BOLETA ELECTRONICA            ║" << endl;
    cout << "\t ╠══════════════════════════════════════════╣" << endl;
    cout << "\t ║ RUC: 20601234567                         ║" << endl;
    cout << "\t ║ Atendido por: " << left << setw(26) << vendedor << "║" << endl;
    cout << "\t ╠══════════════════════════════════════════╣" << endl;
    cout << "\t ║ " << left << setw(18) << "PRODUCTO" << setw(8) << "P.UNIT" << setw(6) << "CANT" << setw(8) << "TOTAL" << "║" << endl;
    cout << "\t ║ " << left << setw(18) << p.nombre << setw(8) << p.precio << setw(6) << cant << setw(8) << total << "║" << endl;
    cout << "\t ╠══════════════════════════════════════════╣" << endl;
    cout << "\t ║ SUB-TOTAL:                S/." << right << setw(10) << fixed << setprecision(2) << importe << " ║" << endl;
    cout << "\t ║ IGV (18%):                S/." << right << setw(10) << igv << " ║" << endl;
    cout << "\t ║ TOTAL A PAGAR:            S/." << right << setw(10) << total << " ║" << endl;
    cout << "\t ╚══════════════════════════════════════════╝" << endl;
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
        limpiarPantalla();
        // --- 1. PRIMERO SELECCIONAR EL ROL ---
        cout << "\t ╔══════════════════════════════════════╗" << endl;
        cout << "\t ║      SISTEMA DE GESTION - INICIO     ║" << endl;
        cout << "\t ╠══════════════════════════════════════╣" << endl;
        cout << "\t ║  1. Ingresar como GERENTE            ║" << endl;
        cout << "\t ║  2. Ingresar como OPERADOR           ║" << endl;
        cout << "\t ║  3. Salir del Sistema                ║" << endl;
        cout << "\t ╚══════════════════════════════════════╝" << endl;
        
        int opcionRol = (int)leerNumero("\t Seleccione una opcion: ");

        if (opcionRol == 3) {
            salirPrograma = true;
            break;
        }

        if (opcionRol != 1 && opcionRol != 2) {
            cout << "\t [!] Opcion invalida.";
            pausar();
            continue;
        }

        // Determinar rol esperado segun la selección
        string rolEsperado = (opcionRol == 1) ? "gerente" : "operador";
        
        // --- 2. LOGIN (SOLO SI SELECCIONÓ UN ROL VÁLIDO) ---
        limpiarPantalla();
        cout << "\t ╔══════════════════════════════════════╗" << endl;
        cout << "\t ║      LOGIN DE ACCESO: " << left << setw(13) << (opcionRol == 1 ? "GERENTE" : "OPERADOR") << "  ║" << endl;
        cout << "\t ╚══════════════════════════════════════╝" << endl;

        string u, p;
        Usuario* usuarioActual = nullptr;

        cout << "\t > Usuario: "; cin >> u;
        cout << "\t > Contraseña: "; cin >> p;

        // Validar usuario, password Y QUE EL ROL COINCIDA con lo que seleccionó
        for (size_t i = 0; i < usuarios.size(); i++) {
            if (usuarios[i].username == u && usuarios[i].password == p && usuarios[i].rol == rolEsperado) {
                usuarioActual = &usuarios[i];
                break;
            }
        }

        if (usuarioActual == nullptr) {
            cout << "\n\t [!] ERROR: Credenciales incorrectas o no tiene permisos de " << rolEsperado << ".";
            pausar();
            continue;
        }

        // --- 3. MENU ESPECIFICO SEGUN LA SELECCION ---
        bool cerrarSesion = false;
        while (!cerrarSesion) {
            limpiarPantalla();
            
            if (rolEsperado == "gerente") {
                // *** MENU EXCLUSIVO GERENTE ***
                cout << "\t ╔══════════════════════════════════════╗" << endl;
                cout << "\t ║       MENU PRINCIPAL - GERENTE       ║" << endl;
                cout << "\t ╠══════════════════════════════════════╣" << endl;
                cout << "\t ║ 1. Añadir Usuario                    ║" << endl; // Orden pedido
                cout << "\t ║ 2. Ingresar Producto                 ║" << endl;
                cout << "\t ║ 3. Mostrar Productos                 ║" << endl;
                cout << "\t ║ 4. Modificar Stock                   ║" << endl;
                cout << "\t ║ 5. Salir (Cerrar Sesion)             ║" << endl;
                cout << "\t ╚══════════════════════════════════════╝" << endl;

                int op = (int)leerNumero("\t Opcion: ");

                switch(op) {
                    case 1: { // Añadir Usuario
                        Usuario nUser;
                        cout << "\n\t --- NUEVO USUARIO ---";
                        cout << "\n\t Username: "; cin >> nUser.username;
                        cout << "\t Password: "; cin >> nUser.password;
                        cout << "\n\t Rol (1=Gerente, 2=Operador): ";
                        int r = (int)leerNumero(""); 
                        while(r!=1 && r!=2) { r=(int)leerNumero("\t (1 o 2): "); }
                        nUser.rol = (r==1) ? "gerente" : "operador";
                        usuarios.push_back(nUser);
                        cout << "\t [OK] Usuario creado."; pausar();
                        break;
                    }
                    case 2: { // Ingresar Producto
                        Producto pr;
                        cout << "\n\t Nombre: "; cin.ignore(); getline(cin, pr.nombre);
                        pr.precio = leerNumero("\t Precio: S/.");
                        pr.stock = (int)leerNumero("\t Stock: ");
                        inventario.push_back(pr);
                        cout << "\t [OK] Guardado."; pausar();
                        break;
                    }
                    case 3: // Mostrar
                        cout << "\n\t --- INVENTARIO ---" << endl;
                        if(inventario.empty()) cout << "\t [Vacio]";
                        for(size_t i=0; i<inventario.size(); i++)
                             cout << "\t " << i+1 << ". " << inventario[i].nombre << " | S/." << inventario[i].precio << " | Stock: " << inventario[i].stock << endl;
                        pausar();
                        break;
                    case 4: // Modificar Stock
                        if(!inventario.empty()) {
                            int id = (int)leerNumero("\t ID Producto: ");
                            if(id>0 && id<=(int)inventario.size()) {
                                inventario[id-1].stock = (int)leerNumero("\t Nuevo Stock: ");
                                cout << "\t [OK] Actualizado.";
                            } else cout << "\t [!] ID Invalido.";
                        } else cout << "\t [!] Vacio.";
                        pausar();
                        break;
                    case 5: cerrarSesion = true; break;
                }

            } else {
                // *** MENU EXCLUSIVO OPERADOR ***
                cout << "\t ╔══════════════════════════════════════╗" << endl;
                cout << "\t ║       MENU PRINCIPAL - OPERADOR      ║" << endl;
                cout << "\t ╠══════════════════════════════════════╣" << endl;
                cout << "\t ║ 1. Mostrar Inventario                ║" << endl;
                cout << "\t ║ 2. Hacer Boleta (Vender)             ║" << endl;
                cout << "\t ║ 3. Salir (Cerrar Sesion)             ║" << endl;
                cout << "\t ╚══════════════════════════════════════╝" << endl;

                int op = (int)leerNumero("\t Opcion: ");

                switch(op) {
                    case 1:
                        cout << "\n\t --- CATALOGO ---" << endl;
                        if(inventario.empty()) cout << "\t [Vacio]";
                        for(size_t i=0; i<inventario.size(); i++)
                             cout << "\t " << i+1 << ". " << inventario[i].nombre << " - S/." << inventario[i].precio << " (Disp: " << inventario[i].stock << ")" << endl;
                        pausar();
                        break;
                    case 2:
                        if(!inventario.empty()) {
                            int id = (int)leerNumero("\t ID Producto: ");
                            if(id>0 && id<=(int)inventario.size()) {
                                int cant = (int)leerNumero("\t Cantidad: ");
                                if(cant <= inventario[id-1].stock && cant > 0) {
                                    generarBoleta(usuarioActual->username, inventario[id-1], cant);
                                    inventario[id-1].stock -= cant;
                                    pausar();
                                } else cout << "\t [!] Stock insuficiente.";
                            } else cout << "\t [!] ID Invalido.";
                        } else cout << "\t [!] Vacio.";
                        pausar(); // Pausa para leer errores si los hay
                        break;
                    case 3: cerrarSesion = true; break;
                }
            }
        }
    }
    return 0;
}