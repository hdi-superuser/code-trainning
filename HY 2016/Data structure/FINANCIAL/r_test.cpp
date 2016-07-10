#include <bits/stdc++.h>

using namespace std;

ifstream f1("financial.out");
ifstream f2("out.txt");

int main() {
    int a, b, i = 0;
    freopen("test.txt", "w", stdout);
    while (f1 >> a) {
        f2 >> b;
        i++;
        if (a != b) {
            cout << "WA on " << i << ": " << a << ", " << b << endl;
        }
    }
    cout << "AC";
}
