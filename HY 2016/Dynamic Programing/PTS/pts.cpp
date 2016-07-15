#include <bits/stdc++.h>

using namespace std;

const int N = 101;
typedef long long ll;

int m, n, k;
int a[N][N], fr[N];
ll b[N][N], f[N][N];
bool d[N];
vector <int> p;

int prime(int x) {
    if (x < 2) return 0;
    for (int t = 2; t <= trunc(sqrt(x)); t++)
        if (x % t == 0) return 0;
    return 1;
}

int main() {
    freopen("pts.inp", "r", stdin);
    freopen("pts.out", "w", stdout);

    cin >> m >> n >> k;

    p.push_back(0);
    int cnt = 0;
    for (int i = 2; i <= N; i++)
        if (prime(i)) p.push_back(i);

    f[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < p.size(); j++) {
            for (int t = 0; t <= k; t++) {
                if (i - t*p[j] >= 0) f[i][j] += f[i-t*p[j]][j-1];
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int a;
        for (int j = 1; j <= n; j++)
            cin >> a, cout << f[a][p.size() - 1] << " ";
        cout << endl;
    }

    return 0;
}
