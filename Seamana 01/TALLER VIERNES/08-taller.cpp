#include <iostream>
#include <math.h>
using namespace std;
int main() {
    float a;
    float b;
    float c;
    float perimetro;
    float area;
    cout << "Ingresa lado 1: ";
    cin >> a;
    cout << "Ingresa lado 2: ";
    cin >> b;
    cout << "Ingresa lado 3: ";
    cin >> c;
    perimetro = (a+b+c)/2;
    cout << "el semi perimetro es: " << perimetro << endl;
    area = sqrt(perimetro * (perimetro - a) * (perimetro - b) * (perimetro - c));
    cout << "el area es: " << area;
}
