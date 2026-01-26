#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a;
    int c;
    int b;
    int h;
    int area;
    int perimetro;
    cout << "Ingresa lado 1: ";
    cin >> a;
    cout << "Ingresa lado 2: ";
    cin >> c;
    cout << "Ingresa la base: ";
    cin >> b;
    cout << "Ingresa la altura: ";
    cin >> h;
    area = ((b * h) / 2);
    cout << "el area es: " << area << endl;
    perimetro = a + b + c;
    cout << "el perimetro es: " << perimetro << endl;
}