#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const ll BASE = 1000000007;
const int MAX = 101;

ll b[MAX];
int N, K;

class Matrix {
public:
    ll val[4][4];
    int M, N;
public:
    void assign(int x, int y, int init_value) {
        memset(val, 0, sizeof val);
        M = x;  N = y;
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                val[i][j] = init_value;
    }
    void identity_matrix(Matrix &x) {
        x.assign(x.M, x.N, 0);
        for (int i = 1; i <= M; i++) x.val[i][i] = 1;
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
} mat;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N >> K;
    Matrix temp;    temp.assign(N, 1, 0);
    for (int i = 1; i <= N; i++) cin >> temp.val[i][1];
    for (int i = 1; i <= N; i++) cin >> b[i];
    mat.assign(N, N, 0);
    for (int i = 1; i < N; i++) mat.val[i][i+1] = 1;
    for (int i = 1; i <= N; i++) mat.val[N][i] = b[N-i+1];
    mat = mat ^ (K - 1);
    mat = mat * temp;
    cout << mat.val[1][1];

    return 0;
}
