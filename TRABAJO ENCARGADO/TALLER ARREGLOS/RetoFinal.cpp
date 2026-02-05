#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Ingrese la cantidad de dias a registrar: ";
    cin >> n;
    int ganancias[n];
    cout << "Ingrese los registros diarios:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> ganancias[i];
    }
    int rachaActual = 0;
    int mayorRacha = 0;
    for (int i = 0; i < n; i++) {
        if (ganancias[i] > 0) {
            rachaActual++;
        } else {
            if (rachaActual > mayorRacha) {
                mayorRacha = rachaActual;
            }
            rachaActual = 0;
        }
    }
    if (rachaActual > mayorRacha) {
        mayorRacha = rachaActual;
    }
    cout << "\nMayor racha positiva: " << mayorRacha << " dias" << endl;
    return 0;
}