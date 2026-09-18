#include <iostream>
using namespace std;
int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int B[] = {4, 5, 6, 7, 8, 9, 10};
    int C[] = {2, 4, 6, 8, 10};
    // =========================
    // ЗАВДАННЯ 1
    // =========================
    cout << "===== Завдання 1 =====" << endl;
    // (A n B) U C
    cout << "a) (A n B) U C = { ";
    for (int x = 1; x <= 10; x++) {
        bool a = false;
        bool b = false;
        bool c = false;
        for (int i = 0; i < 7; i++) {
            if (A[i] == x)
                a = true;
            if (B[i] == x)
                b = true;
        }
        for (int i = 0; i < 5; i++) {
            if (C[i] == x)
                c = true;
        }
        if ((a && b) || c)
            cout << x << " ";
    }
    cout << "}" << endl;
    // (B U C) \ A'
    cout << "b) (B U C) \\ A' = { ";
    for (int x = 1; x <= 10; x++) {
        bool a = false;
        bool b = false;
        bool c = false;
        for (int i = 0; i < 7; i++) {
            if (A[i] == x)
                a = true;

            if (B[i] == x)
                b = true;
        }
        for (int i = 0; i < 5; i++) {
            if (C[i] == x)
                c = true;
        }
        if ((b || c) && a)
            cout << x << " ";
    }
    cout << "}" << endl;
    // =========================
    // ЗАВДАННЯ 2
    // =========================
    cout << endl;
    cout << "===== Завдання 2 =====" << endl;
    int X[10];
    int n = 0;
    // (A U C)'
    for (int x = 1; x <= 10; x++) {
        bool a = false;
        bool c = false;
        for (int i = 0; i < 7; i++) {
            if (A[i] == x)
                a = true;
        }
        for (int i = 0; i < 5; i++) {
            if (C[i] == x)
                c = true;
        }
        if (!a && !c) {
            X[n] = x;
            n++;
        }
    }
    // (A U C)' \ B'
    int result[10];
    int nr = 0;
    for (int i = 0; i < n; i++) {
        bool b = false;
        for (int j = 0; j < 7; j++) {
            if (B[j] == X[i])
                b = true;
        }
        if (b) {
            result[nr] = X[i];
            nr++;
        }
    }
    cout << "X = { ";
    for (int i = 0; i < nr; i++)
        cout << result[i] << " ";
    cout << "}" << endl;
    // Булеан
    cout << "P(X) = { ";
    int amount = 1;
    for (int i = 0; i < nr; i++)
        amount = amount * 2;
    for (int mask = 0; mask < amount; mask++) {
        cout << "{ ";
        for (int i = 0; i < nr; i++) {
            if (mask & (1 << i))
                cout << result[i] << " ";
        }
        cout << "} ";
    }
    cout << "}" << endl;
    cout << "Потужність P(X) = " << amount << endl;
    // =========================
    // ЗАВДАННЯ 4
    // =========================
    cout << endl;
    cout << "===== Завдання 4 =====" << endl;
    int left[10];
    int right[10];
    int nLeft = 0;
    int nRight = 0;
    // Ліва частина:
    // (A U B) n (A \ C)
    for (int x = 1; x <= 10; x++) {
        bool a = false;
        bool b = false;
        bool c = false;
        for (int i = 0; i < 7; i++) {
            if (A[i] == x)
                a = true;
            if (B[i] == x)
                b = true;
        }
        for (int i = 0; i < 5; i++) {
            if (C[i] == x)
                c = true;
        }
        if ((a || b) && a && !c) {
            left[nLeft] = x;
            nLeft++;
        }
    }
    // Права частина:
    // (A n C) \ B
    for (int x = 1; x <= 10; x++) {
        bool a = false;
        bool b = false;
        bool c = false;
        for (int i = 0; i < 7; i++) {
            if (A[i] == x)
                a = true;
            if (B[i] == x)
                b = true;
        }
        for (int i = 0; i < 5; i++) {
            if (C[i] == x)
                c = true;
        }
        if (a && c && !b) {
            right[nRight] = x;
            nRight++;
        }
    }
    // Виведення результатів
    cout << "L = { ";
    for (int i = 0; i < nLeft; i++)
        cout << left[i] << " ";
    cout << "}" << endl;
    cout << "R = { ";
    for (int i = 0; i < nRight; i++)
        cout << right[i] << " ";
    cout << "}" << endl;
    // Перевірка рівності
    bool equal = true;
    if (nLeft != nRight) {
        equal = false;
    } else {
        for (int i = 0; i < nLeft; i++) {
            if (left[i] != right[i])
                equal = false;
        }
    }
    if (equal)
        cout << "Рівність правильна." << endl;
    else
        cout << "Рівність не правильна." << endl;
    return 0;
}