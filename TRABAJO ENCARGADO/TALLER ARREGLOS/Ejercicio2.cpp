#include <iostream>
using namespace std;
int main() {
    float temperaturas[7];
    int diasCalurosos = 0;
    for (int i = 0; i < 7; i++) {
        cout << "DIA " << i + 1 << ": ";
        cin >> temperaturas[i];
        if (temperaturas[i] > 30) {
            diasCalurosos++;
        }
    }
    float max = temperaturas[0];
    float min = temperaturas[0];
    int diaMax = 1;
    int diaMin = 1;
    for (int i = 1; i < 7; i++) {
        if (temperaturas[i] > max) {
            max = temperaturas[i];
            diaMax = i + 1;
        }
        if (temperaturas[i] < min) {
            min = temperaturas[i];
            diaMin = i + 1;
        }
    }
    cout << "Maxima: " << max << " (dia " << diaMax << ")" << endl;
    cout << "Minima: " << min << " (dia " << diaMin << ")" << endl;
    cout << "Dias mayores a 30: " << diasCalurosos << endl;
    return 0;
}