#include <iostream>
using namespace std;

int main() {
    float n1, n2, n3, promedio;
    char respuesta; 
    do {
        cout << "\n--- EVALUADOR DE NOTAS ---" << endl;
        cout << "Ingrese Nota 1: ";
        cin >> n1;
        cout << "Ingrese Nota 2: ";
        cin >> n2;
        cout << "Ingrese Nota 3: ";
        cin >> n3;
        promedio = (n1 + n2 + n3) / 3.0;
        cout << ">> Promedio final: " << promedio << endl;
        if (promedio >= 10.5) {
            cout << "✅ ESTADO: ¡APROBADO! Felicidades." << endl;
        } else {
            cout << "❌ ESTADO: DESAPROBADO. A estudiar más." << endl;
        }
        cout << "\n¿Calificar a otro alumno? (S/N): ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'x');
    cout << "Programa finalizado." << endl;
    return 0;
}