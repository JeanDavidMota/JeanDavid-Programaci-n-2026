#include <iostream>
using namespace std;
int main() {
    int N, num;
    int max, min;
    int cantPrimos = 0, cantParesPos = 0, mayorMasImpares;
    double sumaParesPos = 0;
    bool existeMasImpares = false;
    cout << "Ingrese la cantidad de numeros (N): ";
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << "Ingrese el numero " << i << ": ";
        cin >> num;
        if (i == 1) {
            max = num;
            min = num;
        } else {
            if (num > max) max = num;
            if (num < min) min = num;
        }
        if (num > 1) {
            bool esPrimo = true;
            for (int d = 2; d * d <= num; d++) {
                if (num % d == 0) {
                    esPrimo = false;
                    break;
                }
            }
            if (esPrimo) cantPrimos++;
        }
        if (num > 0 && num % 2 == 0) {
            sumaParesPos += num;
            cantParesPos++;
        }
        int temp = (num < 0) ? -num : num;
        int imp = 0, par = 0;
        if (temp == 0) par++;
        while (temp > 0) {
            int digito = temp % 10;
            if (digito % 2 == 0) par++;
            else imp++;
            temp /= 10;
        }
        if (imp > par) {
            if (!existeMasImpares || num > mayorMasImpares) {
                mayorMasImpares = num;
                existeMasImpares = true;
            }
        }
    }
    cout << "\nMaximo: " << max << endl;
    cout << "Minimo: " << min << endl;
    cout << "Cantidad de primos: ";
    if (cantPrimos > 0) cout << cantPrimos << endl;
    else cout << "NO EXISTE" << endl;
    cout << "Promedio de pares positivos: ";
    if (cantParesPos > 0) cout << (sumaParesPos / cantParesPos) << endl;
    else cout << "NO EXISTE" << endl;
    cout << "Mayor con más dígitos impares que pares: ";
    if (existeMasImpares) cout << mayorMasImpares << endl;
    else cout << "NO EXISTE" << endl;
    return 0;
}