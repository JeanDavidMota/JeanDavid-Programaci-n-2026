#include <iostream>
using namespace std;
string a;
int main(){
    cout << "ingrese su usuario: ";
    getline(cin, a);
    string usuario = a;
    cout << "su usuario es " << usuario << endl;
    return 0;
}