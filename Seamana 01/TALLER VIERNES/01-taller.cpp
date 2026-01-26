#include <iostream> 
#include <math.h>
using namespace std;
int main() {
    int lado;
    int area;
    int perimetro;
    float diagonal;
    cout << "Ingresa el lado: " << endl;
    cin >> lado;
    area = lado * lado;
    cout << "El área es: " << area << endl;
    perimetro = 4 * lado;
    cout << "El perímetro es: " << perimetro << endl;
    diagonal = lado * 1.41421356;
    cout << "La diagonal es: " << diagonal << endl;
}