#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a;
    int b;
    int c;
    int r;
    int perimetro;
    int area;
    cout << "Ingresa lado 1: ";
    cin >> a;
    cout << "Ingresa lado 2: ";
    cin >> b;
    cout << "Ingresa lado 3: ";
    cin >> c;
    cout << "Ingresa radio: ";
    cin >> r;
    perimetro = ((a + b +c)/2);
    cout << "el permetro es: " << perimetro << endl;
    area = r * perimetro;
    cout <<"el area es; " << area;
}