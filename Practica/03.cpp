#include <iostream>
using namespace std;

int main() {
    // --- 1. VARIABLES ---
    int cantidadManzanas;
    float precioPorManzana = 0.50;
    float totalPagar;
    float dineroCliente;

    // --- 2. ENTRADA DE DATOS ---
    cout << "Bienvenido a la Fruteria Digital 🍎 \n";
    cout << "¿Cuantas manzanas desea llevar? ";
    cin >> cantidadManzanas;

    // --- 3. VALIDACIÓN (BUCLE WHILE) ---
    // Mientras la cantidad sea 0 o negativa, no dejamos avanzar al usuario
    while (cantidadManzanas <= 0) {
        cout << "Error: No puedes llevar 0 o menos manzanas." << endl;
        cout << "Por favor, ingresa una cantidad valida: ";
        cin >> cantidadManzanas;
    }

    // --- 4. CÁLCULOS ---
    // Solo llegamos aquí cuando el usuario puso un número válido
    totalPagar = cantidadManzanas * precioPorManzana;
    cout << "El total a pagar es: $" << totalPagar << endl;

    // --- 5. PAGO Y CONDICIONALES ---
    cout << "¿Con cuanto dinero va a pagar? ";
    cin >> dineroCliente;

    if (dineroCliente >= totalPagar) {
        cout << "¡Venta exitosa! Aqui tiene sus manzanas." << endl;
        // Un extra: Calcular el cambio
        cout << "Su cambio es: $" << (dineroCliente - totalPagar) << endl;
    } else {
        cout << "Lo siento, dinero insuficiente." << endl;
    }

    return 0;
}