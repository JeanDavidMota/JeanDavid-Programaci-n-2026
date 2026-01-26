#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a;
    int b;
    int c;
    int R;
    int area;
    cout << "Ingresa el lado 1: ";
    cin >> a;
    cout << "Ingresa el lado 2: ";
    cin >> b;
    cout << "Ingresa el lado 3: ";
    cin >> c;
    cout << "Ingresa el radio: ";
    cin >> R;
    area = ((a*b*c)/(4*R));
    cout << "El área es: " << area << endl;
}