/*
    Fibonacci: f[i] = f[i-1] + f[i-2];
    Notes: Matrix multiplication O(log(N)*2);
    May 15 2016
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxM = 101;
const int maxN = 101;
const int BASE = 1000000007;

class Matrix {
public:
    int M, N;
    int val[maxM][maxN];
public:
    void assign(int x, int y, int init_value) {
        M = x; N = y;
        memset(val, 0, sizeof val);
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++) val[i][j] = init_value;
    }
    void identity_mat(Matrix &x) {
        x.assign(M, N, 0);
        for (int i = 1; i <= x.M; i++) x.val[i][i] = 1;
    }
    Matrix operator * (const Matrix x) {
        Matrix resmul;
        resmul.assign(N, x.N, 0);
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= x.N; j++)
                for (int k = 1; k <= N; k++) resmul.val[i][j] += (val[i][k]*x.val[k][j] % BASE);
        return resmul;
    }
    Matrix operator ^ (int k) {
        Matrix res, x;
        x.assign(M, N, 0);
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++) x.val[i][j] = val[i][j];
        identity_mat(res);
        for (; k; k >>= 1, x = x*x) if (k & 1) res = res*x;
        return res;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    Matrix a;
    int n;
    cin >> n;
    a.assign(2, 2, 1);
    a.val[1][1] = 0;
    a = a ^ n;
    cout << a.val[2][1];

    return 0;
}
