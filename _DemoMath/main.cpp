#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

int countDigits(int n, int b) {
    return static_cast <int> (floor(log(n)/log(b)) + 1);
}

vector <int> toBase(int val, int base) {
    vector <int> res;
    while (val) {
        res.push_back(val % base);
        val /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

int doubleCmp(double a, double b) {
    #define greater_than 1
    #define equal 0
    #define less_than -1

    if (abs(a - b) < EPS) return equal;
    else    if (a < b - EPS) return less_than;
            else return greater_than;
}

void modulus() {
    /***
    (a mod n) + (b mod n) = (a + b mod n);
    (a mod n) - (b mod n) = (a - b mod n);

    (a mod n)*(b mod n) = (a*b mod n);
    (a mod n)^b = (a^b mod n);
    ***/
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a*b/gcd(a, b);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cout << countDigits(12344500, 10) << endl;
    cout << doubleCmp(1.23232, 1.23233) << endl;

    vector <int> base = toBase(10, 2);
    for (int i = 0; i < base.size(); i++) cout << base[i] << " ";
    cout << endl;

    cout << gcd(2, 3) << endl;
    cout << lcm(10, 10) << endl;

    return 0;
}
