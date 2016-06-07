#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int MAX = 101;
const ll BASE = 1000000007;

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
    void identity_cover(Matrix &x) {
        x.assign(x.M, x.N, 0);
        for (int i = 1; i <= x.M; i++) x.val[i][i] = 1;
    }
    Matrix operator * (const Matrix x) {
        Matrix res;
        res.assign(M, x.N, 0);
        for (int i = 1; i <= res.M; i++)
            for (int j = 1; j <= res.N; j++)
                for (int k = 1; k <= N; k++)
                    res.val[i][j] += (val[i][j]*x.val[i][j] % BASE);
        return res;
    }
    Matrix operator ^ (int k) {
        Matrix res, x;
        res.assign(M, N, 0);    x.assign(M, N, 0);
        identity_cover(res);
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                x.val[i][j] = val[i][j];
        for (; k; k >>= 1, x = x*x) if (k & 1) res = res*x;
        return res;
    }
} X[MAX], S;
int N, M, T;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N >> M >> T;
    S.assign(N, 1, 1);
    for (int i = 1; i <= M; i++) {
        X[i].assign(N, N, 0);
        X[i].identity_cover(X[i]);
    }
    for (int i = 1; i <= M; i++) {
        char c;
        int u, v;
        cin >> c >> u >> v;
        if (c == 'A') memset(X[i].val[u], 0, sizeof X[i].val[u]);
        if (c == 'B') X[i].val[u][u] = v;
        if (c == 'C') X[i].val[u][v] = 1;
        if (c == 'D') {
            memset(X[i].val[v], 0, sizeof X[i].val[v]);
            X[i].val[u][v] = 1;
        }
        if (c == 'E')   X[i].val[u][u] = X[i].val[v][v] = 0,
                        X[i].val[u][v] = X[i].val[v][u] = 1;
    }

    Matrix matX = X[1], matY = X[1];
    for (int i = 2; i <= M; i++) matX = matX * X[i];
    int k = T / M, r = T % M;
    matX = matX ^ k;
    for (int i = 2; i <= r; i++) matY = matY * X[i];
    S = matX * matY * S;
    for (int i = 1; i <= S.M; i++) {
        for (int j = 1; j <= S.N; j++) cout << S.val[i][j] << " ";
        cout << endl;
    }

    return 0;
}
