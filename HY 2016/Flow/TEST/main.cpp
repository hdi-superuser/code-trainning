#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("D.in", "r", stdin);

    int m, n, cnt = 0;
    while (1) {
        cnt++;

        string s;
        int t = cnt;
        while (t) {
            s = (char) (t % 10) + s;
            t /= 10;
        }

        string str = "Table/Test" + s + "/table.inp";
        freopen(str.c_str(), "w", stdout);
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        int a;
        cout << m << " " << n << endl;
        for (int i = 1; i <= m; i++) {
            cin >> a;
            cout << a << " ";
        }
    }

    return 0;
}
