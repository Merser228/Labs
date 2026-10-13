#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> Para;
typedef set<Para> Vidnoshennya;
void show(const char* name, const Vidnoshennya& r) {
    cout << name << " (" << r.size() << " пар): ";
    for (auto p : r)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;
}
Vidnoshennya makeP1() {
    Vidnoshennya p1;
    for (int x = -3; x <= 3; x++)          
        for (int y = 1; y <= 6; y++)       
            if (x != 0 && y % x == 0)     
                p1.insert(Para(x, y));
    return p1;
}
Vidnoshennya makeP2() {
    Vidnoshennya p2;
    for (int x = -1; x <= 1; x++)
        for (int y = 0; y <= 3; y++)
            p2.insert(Para(x, y));
    return p2;
}
Vidnoshennya riznytsya(const Vidnoshennya& a, const Vidnoshennya& b) {
    Vidnoshennya res;
    for (auto p : a)
        if (b.count(p) == 0)
            res.insert(p);
    return res;
}
void zavdannya2() {
    cout << "\n--- Завдання 2 ---" << endl;
    show("P1", makeP1());
}
void zavdannya3() {
    cout << "\n--- Завдання 3 ---" << endl;
    Vidnoshennya p1 = makeP1();
    Vidnoshennya p2 = makeP2();
    Vidnoshennya all;
    for (int x = -3; x <= 3; x++)
        for (int y = 1; y <= 6; y++)
            all.insert(Para(x, y));
    Vidnoshennya peretyn;
    for (auto p : p1)
        if (p2.count(p) > 0)
            peretyn.insert(p);
    Vidnoshennya obyednannya = p1;
    for (auto p : p2)
        obyednannya.insert(p);
    Vidnoshennya sym = riznytsya(p1, p2);
    for (auto p : riznytsya(p2, p1))
        sym.insert(p);
    show("P2", p2);
    show("Доповнення P1", riznytsya(all, p1));
    show("P1 U P2", obyednannya);
    show("P1 ∩ P2", peretyn);
    show("P1 \\ P2", riznytsya(p1, p2));
    show("P2 \\ P1", riznytsya(p2, p1));
    show("P1 Δ P2", sym);
}
bool reflexive(const Vidnoshennya& r, int n) {
    for (int i = 1; i <= n; i++)
        if (r.count(Para(i, i)) == 0)
            return false;
    return true;
}
bool symmetric(const Vidnoshennya& r) {
    for (auto p : r)
        if (r.count(Para(p.second, p.first)) == 0)
            return false;
    return true;
}
bool antisymmetric(const Vidnoshennya& r) {
    for (auto p : r)
        if (p.first != p.second && r.count(Para(p.second, p.first)) > 0)
            return false;
    return true;
}
bool transitive(const Vidnoshennya& r) {
    for (auto p : r)
        for (auto q : r)
            if (p.second == q.first && r.count(Para(p.first, q.second)) == 0)
                return false;
    return true;
}
void zavdannya5() {
    cout << "\n--- Завдання 5 ---" << endl;
    int n = 4;
    Vidnoshennya r;
    int pairs[][2] = {{1,1},{2,2},{3,3},{4,4},{1,2},{2,3},{2,1},{3,2},{1,3},{3,1}};
    for (auto p : pairs)
        r.insert(Para(p[0], p[1]));
    show("R", r);
    cout << "Рефлексивність: "   << (reflexive(r, n) ? "так" : "ні") << endl;
    cout << "Симетричність: "    << (symmetric(r) ? "так" : "ні") << endl;
    cout << "Антисиметричність: " << (antisymmetric(r) ? "так" : "ні") << endl;
    cout << "Транзитивність: "   << (transitive(r) ? "так" : "ні") << endl;
}
int main() {
    int choice;
    do {
        cout << "\n1 - Завдання 2\n2 - Завдання 3\n3 - Завдання 5\n0 - Вихід\nВаш вибір: ";
        cin >> choice;
        if (choice == 1) zavdannya2();
        else if (choice == 2) zavdannya3();
        else if (choice == 3) zavdannya5();
    } while (choice != 0);
    return 0;
}
