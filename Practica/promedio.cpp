#include <iostream>
using namespace std;
int main () {
    float a, b, c;
    char respuesta;
    do
    {    
    cout<< "INGRESA UN NUMERO\n";
    cin>> a;
    cout<<"nota 2\n";
    cin>>b;
    cout<<"nota 3 \n";
    cin>>c;
    float promedio=((a+b+c)/3);
    cout<<"su promedio es: " <<promedio << endl;
    if (promedio>=11){
        cout<<"aprobo"<< endl;
    }
    else {
        cout <<"usted desaprobo";
    }
    cout<< "¿Quieres calcular otro promedio? (S/N)";
    cin>>respuesta;
    } while (respuesta == 's' || respuesta == 'S');
} 