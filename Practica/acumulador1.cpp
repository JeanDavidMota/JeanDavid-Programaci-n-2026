#include <iostream>
using namespace std;
int main (){
    float precio;
    float total;
    cout << "un menu de blucle que se acumula la suma y tendras que salir con 0: ";
    do {
        cout << "Ingrese el precio del producto: ";
        cin >> precio;
        total = total + precio; 
    }while (precio!=0);
    cout << "TOTAL A PAGAR: S/" << total << endl;
}