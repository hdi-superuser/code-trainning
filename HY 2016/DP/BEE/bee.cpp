#include <bits/stdc++.h>

using namespace std;

const int N = 52;
const long long M = 1000000000;
const int dx[6] = {0, 0, 1, -1, 1, -1};
const int dy[6] = {1, -1, 0, 0, -1, 1};

long long a[N][N][N];
int n;

int main() {
    freopen("bee.inp", "r", stdin);
    freopen("bee.out", "w", stdout);

    cin >> n;
    a[0][50][50] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                for (int t = 0; t < 6; t++)
                    a[k][i][j] = (a[k][i][j] % M + a[k-1][i + dx[t]][j + dy[t]] % M) % M;

    cout << a[n][50][50];

    return 0;
}
