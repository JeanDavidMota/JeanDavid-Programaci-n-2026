#include <iostream>
using namespace std;
int main() {
    int N, numero;
    int maxVal, minVal;
    int cantPrimos = 0;
    double sumaParesPos = 0;
    int cantParesPos = 0;
    int mayorMasImpares;
    bool existeMasImpares = false;
    cout << "Ingrese la cantidad de numeros (N): ";
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << "Ingrese el numero " << i << ": ";
        cin >> numero;
        if (i == 1) {
            maxVal = numero;
            minVal = numero;
        } else {
            if (numero > maxVal) maxVal = numero;
            if (numero < minVal) minVal = numero;
        }
        if (numero > 1) {
            bool esPrimo = true;
            for (int d = 2; d * d <= numero; d++) {
                if (numero % d == 0) {
                    esPrimo = false;
                    break;
                }
            }
            if (esPrimo) cantPrimos++;
        }
        if (numero > 0 && numero % 2 == 0) {
            sumaParesPos += numero;
            cantParesPos++;
        }
        int temp = numero;
        if (temp < 0) temp = -temp;
        int cuentaImpares = 0, cuentaPares = 0;
        
        if (temp == 0) cuentaPares++;
        while (temp > 0) {
            int digito = temp % 10;
            if (digito % 2 == 0) cuentaPares++;
            else cuentaImpares++;
            temp /= 10;
        }
        
        if (cuentaImpares > cuentaPares) {
            if (!existeMasImpares || numero > mayorMasImpares) {
                mayorMasImpares = numero;
                existeMasImpares = true;
            }
        }
    }
    cout << "1. Maximo: " << maxVal << endl;
    cout << "   Minimo: " << minVal << endl;
    cout << "2. Cantidad de primos: ";
    if (cantPrimos > 0) cout << cantPrimos << endl;
    else cout << "NO EXISTE" << endl;
    cout << "3. Promedio de pares positivos: ";
    if (cantParesPos > 0) cout << (sumaParesPos / cantParesPos) << endl;
    else cout << "NO EXISTE" << endl;
    cout << "4. Mayor con mas digitos impares que pares: ";
    if (existeMasImpares) cout << mayorMasImpares << endl;
    else cout << "NO EXISTE" << endl;
    return 0;
}