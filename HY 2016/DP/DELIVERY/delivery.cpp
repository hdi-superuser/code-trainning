#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 1001;

typedef pair<int, int> ii;
typedef vector<ii> vi;

vector <int> a, b, c;
int T, n, m, f[2][N][N*100];

void Greedy() {
    sort(a.begin(), a.end());
    int i, s = 0, cnt = 0;
    for (i = 1; i <= n; i++)
        if (s + a[i] > T) break;
        else cnt++, s += a[i];

    for ( i; i < a.size(); i++) b.push_back(a[i]);
    sort(b.begin(), b.end());
    s = 0;
    for (i = 1; i <= m; i++)
        if (s + b[i] > T) break;
        else cnt++, s += b[i];

    cout << cnt;
}

void dp() {
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 2*T; j++) {
            f[0][i][j] = f[0][i-1][j];
            if (j - a[i] >= 0) f[0][i][j] = max(f[0][i][j], f[0][i-1][j-a[i]] + 1);
        }

    for (int i = n+1; i <= n+m; i++)
        for (int j = 0; j <= 2*T; j++) {
            f[1][i][j] = max(f[1][i-1][j], f[0][i-1][j]);
            if (j - c[i] >= 0)
                f[1][i][j] = max(f[1][i][j], max(f[0][i-1][j-c[i]], f[1][i-1][j-c[i]]) + 1);
        }

    cout << f[1][n+m][2*T] << endl;
}

int main() {
    freopen("delivery.inp", "r", stdin);
    freopen("delivery.out", "w", stdout);

    cin >> T >> n;
    a.push_back(0);
    b.push_back(0);
    c.push_back(0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        c.push_back(x);
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b.push_back(x);
        c.push_back(x);
    }

    dp();

    return 0;
}
