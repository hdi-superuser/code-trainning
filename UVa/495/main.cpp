#include <iostream>
#include <cstdio>

using namespace std;

const int maxN = 5001;

int N;
string F1, F2, F3;

string add(string a, string b) {
    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;
    string c = "";
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int t = carry + a[i] + b[i] - 96;
        c = (char)(t % 10 + 48) + c;
        carry = t / 10;
    }
    if (carry) c = (char)(carry + 48) + c;
    while (c[0] == '0') c.erase(c.begin(), c.begin() + 1);
    return c;
}

int main() {

    while (cin >> N) {
        F1 = '0';   F2 = '1';
        for (int i = 2; i <= N; i++) F3 = add(F1, F2), F1 = F2, F2 = F3;
        cout << "The Fibonacci number for " << N << " is " << F3 << endl;
    }

    return 0;
}
