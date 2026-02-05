#include <iostream>
using namespace std;
int main() {
    int asistencia[3][5];
    int totalAula = 0;
    for (int i = 0; i < 3; i++) {
        cout << "Estudiante" << i + 1 << " ---" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "Dia " << j + 1 << " (1=Asistio, 0=Falto): ";
            cin >> asistencia[i][j];
        }
        cout << endl;
    }
    cout << "REPORTE FINAL" << endl;
    for (int i = 0; i < 3; i++) {
        int asistenciaIndividual = 0;
        for (int j = 0; j < 5; j++) {
            if (asistencia[i][j] == 1) {
                asistenciaIndividual++;
                totalAula++;
            }
        }
        cout << "Estudiante " << i + 1 << ": " << asistenciaIndividual << " asistencias";
        
        if (asistenciaIndividual == 5) {
            cout << " ASISTENCIA PERFECTA";
        }
        cout << endl;
    }
    cout << "\nTotal de asistencias en el aula: " << totalAula << endl;
    return 0;
}