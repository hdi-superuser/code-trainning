#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxM = 4;
const int maxN = 4;
const ll M = 111539786;

int n;

class Matrix {
public:
    ll val[maxM][maxN];
public:
    Matrix() { memset(val, 0, sizeof val); }

    void identity_mat(Matrix &x) {
        for (int i = 1; i <= 2; i++) x.val[i][i] = 1;
    }

    Matrix operator * (const Matrix x) {
        Matrix res;

        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 2; j++)
                for (int k = 1; k <= 2; k++)
                    res.val[i][j] = ((res.val[i][j] % M) + ((val[i][k] % M) * (x.val[k][j] % M)) % M) % M;
                    //res.val[i][j] += val[i][k] * x.val[k][j];
        return res;
    }

    Matrix operator ^ (int k) {
        Matrix res, x;
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 2; j++) x.val[i][j] = val[i][j];

        identity_mat(res);
        for (; k; k >>= 1, x = x*x) if (k & 1) res = res*x;
        return res;
    }
};

void solve() {
    cin >> n;
    Matrix a;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++) a.val[i][j] = 1;
    a.val[1][1] = 0;
    a = a ^ (n + 1);
    cout << a.val[2][1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("fib.inp", "r", stdin);
    freopen("fib.out", "w", stdout);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
