/*
    Fibonacci matrix power
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int N, M, a, b;

struct matrix {
    int val[2][2];
} I = {1, 0, 0, 1}, A = {1, 1, 1, 0}, inf = {0, 0, 0, 0};

void MatrixMul(matrix &a, matrix &b, int m) {
    matrix t = inf;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                t.val[i][j] += a.val[i][k]*b.val[k][j],
                t.val[i][j] %= m;
    a = t;
}

matrix Calc(int n, int m) {
    matrix x = I, y = A;
    while (n) {
        if (n & 1) MatrixMul(x, y, m);
        MatrixMul(y, y, m);
        n /= 2;
    }
    return x;
}

int main() {
    freopen("in.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> N >> M;
        M = (int) pow(10, M);
        matrix ans = Calc(N, M);
        int res = ans.val[1][0]*b + ans.val[1][1]*a;
        cout << res % M << endl;
    }
    return 0;
}
