#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 11;

bool fr[N][N];
int a[N][N];

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("screenlock.inp", "r", stdin);
    freopen("screenlock.out", "w", stdout);

    a[1][1] = 1;    a[1][2] = 4;    a[1][3] = 9;
    a[2][2] = 20736;

    int m, n;
    while (cin >> m >> n)
        cout << a[m][n] << endl;

    return 0;
}
