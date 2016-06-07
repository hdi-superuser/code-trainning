#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const ll BASE = 1000000007;
const ll inf = 200000007;
const int MAX = 101;

int N, K;
class Matrix {
public:
    ll val[MAX][MAX];
    int M, N;
public:
    void assign(int x, int y, int init_value) {
        memset(val, 0, sizeof val);
        M = x, N = y;
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                val[i][j] = init_value;
    }
    void identity_matrix(Matrix &x) {
        x.assign(x.M, x.N, 0);
        for (int i = 1; i <= x.M; i++) x.val[i][i] = 1;
    }
    Matrix operator * (const Matrix x) {
        Matrix res;
        res.assign(M, x.N, inf);
        for (int i = 1; i <= res.M; i++)
            for (int j = 1; j <= res.N; j++)
                for (int k = 1; k <= N; k++)
                    res.val[i][j] = min(res.val[i][j], val[i][k] + x.val[k][j]) % BASE;
        return res;
    }
} mat;

Matrix pow(Matrix x, int k) {
    if (k == 1) return x;
    Matrix t = pow(x, k >> 1);
    if (k & 1) return t*t*x;
    return t*t;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N >> K;
    mat.assign(N, N, inf);
    int u, v, k;
    while ((cin >> u >> v >> k)) mat.val[u][v] = k;
    mat = pow(mat, K);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (mat.val[i][j] != inf) cout << i << " -> " << j << " = " << mat.val[i][j] << endl;

    return 0;
}
