#include <iostream>
using namespace std;
int main() {
    int d;
    cout << "Dia (1-7): "; cin >> d;
    if (d == 1) cout << "Lunes";
    else if (d == 2) cout << "Martes";
    else cout << "Otro dia";
    return 0;
}