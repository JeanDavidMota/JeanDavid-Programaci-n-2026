#include <iostream>
using namespace std;
int main() {
int x = 5, y = 2;
for (int i = 1; i <= 5; i++) {
    if ((x + i) % 2 == 0)
        y += i;
    else
        y -= i;
    if (y > 3)
        cout << y << " ";
}
    return 0;
}