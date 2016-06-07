#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 30;

int X, Y, K, B;
long long C[MAX+1][21];

long long power(int n, int k) {
    if (k == 1) return n;
    long long t = power(n, k/2);
    if (k % 2) return t*t*n;
    return t*t;
}

long long Calc(int a, int k, int b) {
    int n = floor(log(a)/log(b));
    if (k == 1) return n;
    if (n == k) return 1;
    return C[n][k] + Calc(a - power(b, n), k-1, b);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> X >> Y >> K >> B;
    for (int i = 0; i <= MAX; i++) C[i][0] = 1;
    for (int i = 1; i <= MAX; i++)
        for (int j = 1; j <= 20; j++)
            if (i == j) C[i][j] = 1;
            else C[i][j] = C[i-1][j-1] + C[i-1][j];

    //formula: C[n][k] + Calc(A - B^n, k-1, B);
    cout << Calc(Y, K, B) - Calc(X, K, B);

    return 0;
}
