#include <iostream>
using namespace std;
float a;
float b;
float c;
int main(){
    cout <<"ingrese el numero ";
    cin >> a;
    cout <<"ingrese el numero ";
    cin >> b;
    cout <<"ingrese el numero ";
    cin >> c;
    float suma = a + b + c;
    float dividir = suma/3;
    cout << "el promedio es " << dividir << endl;
    return 0;
}