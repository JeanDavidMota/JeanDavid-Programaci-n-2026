#include <iostream>
using namespace std;
int main () {
    int a;
    cout << "----Binevenido---- \n"
        <<"eligie una opcion \n"
        <<"1.-Saber su Edad \n"
        <<"2.-calculadora \n"
        <<"3.-Saber si Aprobo el curso \n";
    cin >> a;
    switch (a){
    case 1:{
        int a, b;
        cout <<"Usted eligio la Opcion 1 \n"
            <<"Ingresa su Fecha de Nacimiento \n";
            cin >> a;
        cout <<"Ingresa el año actual \n";
            cin >> b;
            int resta = b - a;
        cout <<"Usted tiene " << resta << " años";
        break;
        }
    case 2:{
        int a;
        cout <<"Usted eligio la opcion 2 \n"
            <<"Que opereacion matematica desea realizar elija su opcion \n"
            "1.-Suma \n"
            "2.-Resta \n"
            "3.-Multiplicaion \n"
            "4.-Divicion \n";
        cin >> a;
        switch (a){
        case 1:{
            int a, b;
            cout <<"Su primer numero: \n";
                cin >> a;
            cout <<"Ingresa su segundo numero \n";
                cin >> b;
            int suma = a + b;
            cout <<"la suma de " << a <<"+"<< b << " es " << suma;
            break;}
        case 2:{
        int a, b;
            cout <<"Su primer numero: \n";
                cin >> a;
            cout <<"Ingresa su segundo numero \n";
                cin >> b;
            int resta = a - b;
            cout <<"la resta de "<<a<<" menos "<<b<<" es igual a "<< resta;
        break;
        }
        case 3:{
        int a, b;
            cout <<"Su primer numero: \n";
                cin >> a;
            cout <<"Ingresa su segundo numero \n";
                cin >> b;
            int multiplicar = a * b;
            cout <<"la multiplicaion de "<<a<<"*"<<b<<" es igual a "<< multiplicar;
        break;
        }
        case 4:{
        float a, b;
            cout <<"Su primer numero: \n";
                cin >> a;
            cout <<"Ingresa su segundo numero \n";
                cin >> b;
            float diviccion = a / b;
            cout <<"la divicion de "<<a<<"/"<<b<<" es igual a "<< diviccion;
        break;
        }
        break;}
    break;}
    case 3:{
        float a, b;
        cout <<"Usted eligio la opcion1212 3 \n"
            << "Nota 1 \n";
        cin >> a;
        cout <<"Nota 2 \n";
        cin >> b;
        float suma = a + b, promedio = suma/2;
        if (promedio>=10.5){
            cout <<"Aprobo";
        }
        else{
            cout <<"Desaprobo";        
        }
    break;}
    }
}