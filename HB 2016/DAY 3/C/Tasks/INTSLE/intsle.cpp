#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a1, b1, c1, a2, b2, c2;
ll d, dx, dy;

int main() {
    freopen("INTSLE.inp", "r", stdin);
    freopen("INTSLE.out", "w", stdout);

    while (cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2) {
        d = a1*b2 - a2*b1;
        dx = c1*b2 - c2*b1;
        dy = a1*c2 - a2*c1;
        if (d) {
            if (dx & d == 0 && dy % d == 0)
                cout << dx/d << " " << dy/d << endl;
            else cout << "NO SOLUTION" << endl;
        } else {
            if (dx || dy) cout << "NO SOLUTION" << endl;
            else {
                bool sol1, sol2;
                if (a1 == 0 && b1 == 0) sol1 = (c1 == 0);
                else sol1 = (c1 % __gcd(a1, b1) == 0);
                if (a2 == 0 && b2 == 0) sol2 = (c2 == 0);
                else sol2 = (c2 % __gcd(a2, b2) == 0);
                if (sol1 && sol2) cout << "INFINITE" << endl;
                else cout << "NO SOLUTION";
            }
        }
    }
}
