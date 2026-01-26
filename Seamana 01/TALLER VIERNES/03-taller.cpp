#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int D;
    int d;
    int area;
    int lado;
    float perimetro;
    cout << "Ingresa la diagonal mayor: ";
    cin >> D;
    cout << "Ingresa la diagonal menor: ";
    cin >> d;
    area = (D*d)/2;
    cout << "El área es: " << area << endl;
    lado = sqrt(((D/2) * (D/2)) + ((d/2) * (d/2)));
    cout << "El lado es: " << lado << endl;
    perimetro = 4 * lado;
    cout << "El perímetro es: " << perimetro << endl;
    }