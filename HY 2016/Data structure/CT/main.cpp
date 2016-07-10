#include <bits/stdc++.h>

using namespace std;

int a[3][3];
bool f1[3], f2[3], f3[3];

void solve() {
    for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 2; j++)
                for (int k = 0; k <= 2; k++) {
                    int d = a[0][i] + a[1][j] + a[2][k];
                    int h = a[0][i] + a[1][j] + a[2][k];
                    int r = a[0][i] + a[1][j] + a[2][k];
                    cout << "YES" << endl;
                    return;
                }
    cout << "NO" << endl;
}
int main() {
    //freopen("in.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 2; j++)
                cin >> a[i][j];
        solve();
    }
}
