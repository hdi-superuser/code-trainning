/*
    Tribonacci: f[i] = f[i-1] + f[i-2] + f[i-3];
    Notes: Matrix multiplication O(log(N)*3);
    May 15 2016
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const ll BASE = 1000000007;

class Matrix {
public:
    ll val[4][4];
    int M, N;
public:
    void assign(int x, int y, int init_value) {
        memset(val, 0, sizeof val);
        M = x;  N = y;
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++) val[i][j] = init_value;
    }
    void identity_matrix(Matrix &x) {
        x.assign(x.M, x.N, 0);
        for (int i = 1; i <= x.M; i++) x.val[i][i] = 1;
    }
    Matrix operator * (const Matrix x) {
        Matrix res;
        res.assign(M, x.N, 0);
        for (int i = 1; i <= res.M; i++)
            for (int j = 1; j <= res.N; j++)
                for (int k = 1; k <= N; k++)
                    res.val[i][j] += (val[i][k]*x.val[k][j] % BASE);
        return res;
    }
    Matrix operator ^ (int k) {
        Matrix res, x;
        x.assign(M, N, 0);  res.assign(M, N, 0);
        identity_matrix(res);
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++) x.val[i][j] = val[i][j];
        for (; k; k >>= 1, x = x*x) if (k & 1) res = res*x;
        return res;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    Matrix a, f, c;
    a.assign(3, 3, 0);  f.assign(3, 1, 0);
    a.val[1][2] = a.val[2][3] = a.val[3][1] = a.val[3][2] = a.val[3][3] = 1;
    int N;
    cin >> N;
    for (int i = 1; i <= 3; i++) cin >> f.val[i][1];
    a = a^(N-1);
    c = a*f;
    cout << c.val[1][1];

    return 0;
}
