#include <bits/stdc++.h>

using namespace std;

const int BASE = 100000007;
typedef long long ll;

ll POW[1000001], HT[1000001], HP[1000001];

ll getHT(int L, int R) {
    return (HT[R] - HT[L-1]*POW[R-L+1] + BASE*BASE) % BASE;
}

ll getHP(int L, int R) {
    return (HP[R] - HP[L-1]*POW[R-L+1] + BASE*BASE) % BASE;
}

int main() {
    freopen("in.txt", "r", stdin);
    string T, P;
    cin >> T >> P;
    T = " " + T; P = " " + P;
    int N = T.size() - 1, M = P.size() - 1;
    POW[0] = 1;
    for (int i = 1; i <= N; i++) POW[i] = (POW[i-1]*26) % BASE;
    HT[0] = HP[0] = 0;
    for (int i = 1; i <= N; i++)
        HT[i] = (HT[i-1]*26 + T[i] - 'a') % BASE;
    for (int i = 1; i <= M; i++)
        HP[i] = (HP[i-1]*26 + P[i] - 'a') % BASE;
    ll x = getHP(1, M);
    for (int i = 1; i <= N - M + 1; i++) {
        int y = getHT(i, i + M - 1);
        if (x == y) printf("%d ", i);
    }
    return 0;
}
