#include <iostream>
using namespace std;
int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int B[] = {4, 5, 6, 7, 8, 9, 10};
    int C[] = {2, 4, 6, 8, 10};
    cout << "a) (A ^ B) U C = {";
    for (int i = 1; i <= 10; i++) {
        bool inA = false, inB = false, inC = false;
        for (int j = 0; j < 7; j++) {
            if (A[j] == i) inA = true;
        }
        for (int j = 0; j < 7; j++) {
            if (B[j] == i) inB = true;
        }
        for (int j = 0; j < 5; j++) {
            if (C[j] == i) inC = true;
        }
        if ((inA && inB) || inC) {
            cout << i << " ";
        }
    }
    cout << "}" << endl;
    cout << "b) (B U C) \\ A' = {";
    for (int i = 1; i <= 10; i++) {
        bool inA = false, inB = false, inC = false;
        for (int j = 0; j < 7; j++) {
            if (A[j] == i) inA = true;
        }
        for (int j = 0; j < 7; j++) {
            if (B[j] == i) inB = true;
        }
        for (int j = 0; j < 5; j++) {
            if (C[j] == i) inC = true;
        }

        if ((inB || inC) && inA) {
            cout << i << " ";
        }
    }
    cout << "}" << endl;
    return 0;
}