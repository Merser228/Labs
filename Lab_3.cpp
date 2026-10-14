#include <iostream>
#include <string>
using namespace std;
bool f1(bool x, bool y, bool z) {
    return (x && y) || ((!x && !z) || y);
}
bool f2(bool x, bool y, bool z) {
    return (x && y) ^ (x && z) ^ (y && z);
}
void rozrahuvaty(bool (*f)(bool, bool, bool), string nazva) {
    int vektor[8];
    int nomer = 0;
    cout << "=== " << nazva << " ===" << endl;
    cout << "x y z | f" << endl;
    cout << "------+--" << endl;
    for (int i = 0; i < 8; i++) {
        int x = i / 4;        
        int y = (i / 2) % 2;
        int z = i % 2;      
        vektor[i] = f(x, y, z);
        cout << x << " " << y << " " << z << " | " << vektor[i] << endl;
        nomer = nomer * 2 + vektor[i];
    }
    cout << endl << "Вектор значень: ";
    for (int i = 0; i < 8; i++) {
        cout << vektor[i];
    }
    cout << endl;
    cout << "Порядковий номер: " << nomer << endl;
    cout << "Набори, на яких f = 1: ";
    for (int i = 0; i < 8; i++) {
        if (vektor[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl << endl;
}
int main() {
    rozrahuvaty(f1, "f = (x & y) v ((!x & !z) v y)");
    rozrahuvaty(f2, "f = (x & y) xor (x & z) xor (y & z)");
    return 0;
}