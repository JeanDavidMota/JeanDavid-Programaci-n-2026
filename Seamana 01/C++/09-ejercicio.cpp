#include <iostream>
using namespace std;
float a, b;
int main() {
    cout <<"ingrese el primer numero: ";
    cin >> a;
    cout <<"ingrese el segundo numero: ";
    cin >> b;
    if (a > b) {
        cout << a <<" es mayor que " << b << endl;
    }
    else if (a<b) {
        cout << a <<" es menor que " << b << endl;
    }
    else {
        cout << a <<" es igual a " << b << endl;
    }
    return 0;
}