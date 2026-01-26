#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int B;
    int b;
    int h;
    float area;
    cout << "Ingresa la Base mayor: ";
    cin >> B;
    cout << "Ingresa la Diagonal menor: ";
    cin >> b;
    cout << "Ingresa la Diagonal altura: ";
    cin >> h;
    area = ((B+b) * h)/2;
    cout << "el area es: " << area << endl;
}