#include <iostream>
using namespace std;
int obtenerMayor(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int main() {
    int n1, n2;
    cout << "Ingresa dos numeros: ";
    cin >> n1 >> n2;
    cout << "El mayor es: " << obtenerMayor(n1, n2);
    return 0;
}