#include <iostream> 
#include <math.h>
using namespace std;
int main() {
    int base;
    int altura;
    int area;
    int perimetro;
    float diagonal;
    cout << "Ingresa la base: ";
    cin >> base;
    cout << "Ingresa la altura: ";
    cin >> altura;
    area = base * altura;
    cout << "El área es: " << area << endl;
    perimetro = 2 * (base + altura);
    cout << "El perímetro es: " << perimetro  << endl;
    diagonal = sqrt((base * base) + (altura * altura));
    cout << "La diagonal es: " << diagonal << endl;
}