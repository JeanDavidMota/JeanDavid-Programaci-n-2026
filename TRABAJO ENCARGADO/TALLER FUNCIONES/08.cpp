#include <iostream>
using namespace std;
long long calcularFactorial(int n) {
    long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
int main() {
    int num;
    cout << "Ingresa un numero para calcular su factorial: ";
    cin >> num;
    if (num < 0) {
        cout << "No existe factorial de numeros negativos." << endl;
    } else {
        cout << "El factorial de " << num << " es: " << calcularFactorial(num) << endl;
    }
    return 0;
}