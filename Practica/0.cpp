#include <iostream>
#include <vector>
using namespace std;
int main() {
    int f, c;
    cout << "Filas: "; cin >> f;
    cout << "Columnas: "; cin >> c;
    vector<vector<int>> matriz(f, vector<int>(c));
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Valor en [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
    cout << "\n--- MATRIZ ---\n";
    for (int i = 0; i < f; i++) {
        int sumaFila = 0;
        for (int j = 0; j < c; j++) {
            cout << matriz[i][j] << "\t";
            sumaFila += matriz[i][j];
        }
        cout << "| Suma: " << sumaFila << endl;
    }
    return 0;
}