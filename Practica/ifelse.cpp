#include <iostream>
using namespace std;
int main (){
    int a;
    cout<<"Ingresa su clave \n";
    cin >> a;
    if (a==1234){
        cout<<"Acceso Concedido";
    }
    else{
        cout<<"¡ALERTA! Intruso detectado";
    }
}