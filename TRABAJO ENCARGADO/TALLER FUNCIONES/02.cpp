#include <iostream>
using namespace std;
bool esPar(int numero) {
    if (numero % 2 == 0) {
        return true;
    } else {
        return false;
    }
}
int main() {
    int num;
    cout << "Ingresa un numero: ";
    cin >> num;
    if (esPar(num)) {
        cout << "El numero es Par" << endl;
    } else {
        cout << "El numero es Impar" << endl;
    }
    return 0;
}