#include <iostream>
using namespace std;
int main() {
    int asistencia[3][5];
    int totalAula = 0;
    for (int i = 0; i < 3; i++) {
        cout << "Asistencia Estudiante " << i + 1 << " (5 dias): ";
        for (int j = 0; j < 5; j++) {
            cin >> asistencia[i][j];
        }
    }
    cout << "\n--- Reporte de Asistencia ---" << endl;
    for (int i = 0; i < 3; i++) {
        int sumaEstudiante = 0;
        for (int j = 0; j < 5; j++) {
            sumaEstudiante += asistencia[i][j];
        }
        cout << "Estudiante " << i + 1 << ": " << sumaEstudiante;
        if (sumaEstudiante == 5) {
            cout << " (ASISTENCIA PERFECTA)";
        }
        cout << endl;
        totalAula += sumaEstudiante;
    }
    cout << "Total de asistencias del aula: " << totalAula << endl;
    return 0;
}