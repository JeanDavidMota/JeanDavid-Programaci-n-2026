#include <iostream>
#include <string>
using namespace std;
struct Libro {
    int id;
    string titulo;
    string autor;
    int anio;
    bool disponible;
};
struct Usuario {
    int id;
    string nombre;
    string carrera;
};
struct Prestamo {
    int idLibro;
    int idUsuario;
    bool activo;
};
// --- VARIABLES GLOBALES (PUNTEROS) ---
Libro* biblioteca = nullptr;
int numLibros = 0;
int capLibros = 2;
Usuario* usuarios = nullptr;
int numUsuarios = 0;
int capUsuarios = 2;
Prestamo* prestamos = nullptr;
int numPrestamos = 0;
int capPrestamos = 2;
// --- GESTIÓN DE MEMORIA (REDIMENSIONAMIENTO MANUAL) ---
void redimensionarLibros(Libro*& arr, int& capacidad) {
    int nuevaCap = capacidad * 2;
    Libro* nuevoArr = new Libro[nuevaCap];
    for (int i = 0; i < numLibros; i++) {
        nuevoArr[i] = arr[i];
    }
    delete[] arr;
    arr = nuevoArr;
    capacidad = nuevaCap;
}
void redimensionarUsuarios(Usuario*& arr, int& capacidad) {
    int nuevaCap = capacidad * 2;
    Usuario* nuevoArr = new Usuario[nuevaCap];
    for (int i = 0; i < numUsuarios; i++) nuevoArr[i] = arr[i];
    delete[] arr;
    arr = nuevoArr;
    capacidad = nuevaCap;
}
void redimensionarPrestamos(Prestamo*& arr, int& capacidad) {
    int nuevaCap = capacidad * 2;
    Prestamo* nuevoArr = new Prestamo[nuevaCap];
    for (int i = 0; i < numPrestamos; i++) nuevoArr[i] = arr[i];
    delete[] arr;
    arr = nuevoArr;
    capacidad = nuevaCap;
}
// --- FUNCIONES DE BÚSQUEDA (PUNTEROS) ---
Libro* buscarLibroPorID(int id) {
    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].id == id) return &biblioteca[i];
    }
    return nullptr;
}
Usuario* buscarUsuarioPorID(int id) {
    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == id) return &usuarios[i];
    }
    return nullptr;
}
// --- FUNCIONES PRINCIPALES ---
void registrarLibro() {
    if (numLibros == capLibros) redimensionarLibros(biblioteca, capLibros);
    Libro l;
    l.id = numLibros + 1;
    l.disponible = true;
    
    cin.ignore();
    cout << "Titulo: "; getline(cin, l.titulo);
    cout << "Autor: "; getline(cin, l.autor);
    cout << "Anio de publicacion: "; cin >> l.anio;
    biblioteca[numLibros] = l;
    numLibros++;
    cout << ">> Libro registrado con ID: " << l.id << endl;
}
void registrarUsuario() {
    if (numUsuarios == capUsuarios) redimensionarUsuarios(usuarios, capUsuarios);
    Usuario u;
    u.id = numUsuarios + 1;
    
    cin.ignore();
    cout << "Nombre del Usuario: "; getline(cin, u.nombre);
    cout << "Carrera profesional: "; getline(cin, u.carrera); // NUEVO CAMPO
    usuarios[numUsuarios] = u;
    numUsuarios++;
    cout << ">> Usuario registrado con ID: " << u.id << endl;
}
void listarLibros() {
    cout << "\n--- INVENTARIO DE LIBROS ---\n";
    if (numLibros == 0) cout << "(Vacio)\n";
    for(int i=0; i<numLibros; i++) {
        cout << "ID:" << biblioteca[i].id << " | " << biblioteca[i].titulo 
             << " (" << biblioteca[i].anio << ") [" // Muestra el año
             << (biblioteca[i].disponible ? "DISPONIBLE" : "PRESTADO") << "]\n";
    }
}
void listarUsuarios() {
    cout << "\n--- LISTA DE USUARIOS ---\n";
    if (numUsuarios == 0) {
        cout << "(Sin usuarios registrados)\n";
        return;
    }
    for (int i = 0; i < numUsuarios; i++) {
        cout << "ID: " << usuarios[i].id << " | " << usuarios[i].nombre 
             << " - " << usuarios[i].carrera << endl; // Muestra carrera
    }
}
void buscarLibroPorTexto() {
    string busqueda;
    cout << "Ingrese titulo o autor a buscar: ";
    cin.ignore();
    getline(cin, busqueda);
    bool encontrado = false;
    cout << "\n--- RESULTADOS DE BUSQUEDA ---\n";
    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].titulo.find(busqueda) != string::npos || 
            biblioteca[i].autor.find(busqueda) != string::npos) {
            
            cout << "ID: " << biblioteca[i].id << " | " << biblioteca[i].titulo 
                 << " (" << biblioteca[i].anio << ")\n";
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No se encontraron libros.\n";
}
void prestarLibro() {
    int idL, idU;
    cout << "ID del Libro a prestar: "; cin >> idL;
    
    Libro* libroPtr = buscarLibroPorID(idL);
    
    if (libroPtr == nullptr) {
        cout << ">> Error: Libro no existe.\n";
        return;
    }
    if (!libroPtr->disponible) {
        cout << ">> Error: El libro ya esta prestado.\n";
        return;
    }
    listarUsuarios(); 
    cout << "ID del Usuario que recibe: "; cin >> idU;
    Usuario* usuarioPtr = buscarUsuarioPorID(idU);
    
    if (usuarioPtr == nullptr) {
        cout << ">> Error: Usuario no existe.\n";
        return;
    }
    if (numPrestamos == capPrestamos) redimensionarPrestamos(prestamos, capPrestamos);
    
    Prestamo p;
    p.idLibro = idL;
    p.idUsuario = idU;
    p.activo = true;
    prestamos[numPrestamos] = p;
    numPrestamos++;
    libroPtr->disponible = false; 
    cout << ">> Prestamo registrado con exito.\n";
}
void devolverLibro() {
    int idL;
    cout << "ID del Libro a devolver: "; cin >> idL;
    Libro* libroPtr = buscarLibroPorID(idL);
    if (libroPtr == nullptr) {
        cout << ">> Error: Libro no existe.\n";
        return;
    }
    if (libroPtr->disponible) {
        cout << ">> Error: Este libro no estaba prestado.\n";
        return;
    }
    libroPtr->disponible = true;
    // Cerrar el préstamo activo
    for (int i = 0; i < numPrestamos; i++) {
        if (prestamos[i].idLibro == idL && prestamos[i].activo) {
            prestamos[i].activo = false;
        }
    }
    cout << ">> Libro devuelto correctamente.\n";
}
// --- NUEVA FUNCIÓN: LISTAR PRÉSTAMOS ACTIVOS ---
void listarPrestamosActivos() {
    cout << "\n--- PRESTAMOS ACTIVOS ---\n";
    bool hayPrestamos = false;
    
    for (int i = 0; i < numPrestamos; i++) {
        if (prestamos[i].activo) {
            Libro* l = buscarLibroPorID(prestamos[i].idLibro);
            Usuario* u = buscarUsuarioPorID(prestamos[i].idUsuario);
            if (l != nullptr && u != nullptr) {
                cout << "Libro: [" << l->titulo << "] prestado a: [" << u->nombre << "]\n";
                hayPrestamos = true;
            }
        }
    }
    
    if (!hayPrestamos) {
        cout << "(No hay libros prestados actualmente)\n";
    }
}
void inicializarSistema() {
    biblioteca = new Libro[capLibros];
    usuarios = new Usuario[capUsuarios];
    prestamos = new Prestamo[capPrestamos];
}
void liberarMemoria() {
    delete[] biblioteca;
    delete[] usuarios;
    delete[] prestamos;
}
int main() {
    inicializarSistema();
    int op;
    do {
        cout << "\n=== SISTEMA BIBLIOTECA (EXAMEN) ===\n";
        cout << "1. Registrar Libro\n";
        cout << "2. Registrar Usuario\n";
        cout << "3. Listar Libros\n";
        cout << "4. Buscar Libro (Texto)\n";
        cout << "5. Listar Usuarios\n";
        cout << "6. Prestar Libro\n";
        cout << "7. Devolver Libro\n";
        cout << "8. Listar Prestamos Activos\n"; // NUEVA OPCIÓN
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;
        switch(op) {
            case 1: registrarLibro(); break;
            case 2: registrarUsuario(); break;
            case 3: listarLibros(); break;
            case 4: buscarLibroPorTexto(); break;
            case 5: listarUsuarios(); break;
            case 6: prestarLibro(); break;
            case 7: devolverLibro(); break;
            case 8: listarPrestamosActivos(); break;
            case 0: cout << "Finalizando programa...\n"; break;
            default: cout << "Opcion invalida\n";
        }
    } while(op != 0);
    liberarMemoria();
    return 0;
}
/*
 ==================== BITÁCORA IA ====================
 Herramienta IA usada: Google Gemini / ChatGPT
 Objetivo del uso: Entender cómo manejar memoria dinámica sin vectores y arreglar la lógica de búsqueda.
 
 Preguntas que hice a la IA (resumen):
 1) ¿Cómo crear un arreglo dinámico que crezca solo cuando se llena (sin std::vector)?
 2) ¿Cómo buscar una subcadena de texto dentro de un string en C++?
 3) ¿Cómo relacionar el ID de usuario y libro para mostrar un préstamo activo?
 
 Qué sugerencias acepté y por qué:
 - Usar funciones auxiliares 'redimensionar' con punteros temporales, porque es la forma manual de simular un vector.
 - Usar 'string::npos' para validar si existe texto dentro de otro, porque es más eficiente que recorrer char por char.
 
 Test manual diseñado por mí:
 Entrada (pasos):
 1. Registrar libro "C++ Avanzado" (ID 1).
 2. Registrar usuario "Jean" (ID 1).
 3. Prestar libro ID 1 a usuario ID 1.
 4. Intentar prestar libro ID 1 otra vez.
 Salida esperada:
 - El primer préstamo dice "Éxito".
 - El segundo intento dice "Error: Libro ya prestado".
 
 Nota de autoría:
 Declaro que entiendo el código entregado y puedo explicarlo.
 ====================================================
 */