#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100001;
const int M = 10000007;

ll POW[N], H[3][N];
int fr[3], x[3], best;
string s[3], s_best;

ll get_hash(int op, int L, int R) {
    return (H[op][R] - H[op][L-1]*POW[R-L+1] + M*M) % M;
}

bool is_substr(string a, string b) {

}

string gen(string X, string Y) {
    if (is_substr(X, Y)) return Y;
    else if (is_substr(Y, X)) return X;

    memset(H[0], 0, sizeof H[0]);
    string ans = X;

    reverse(X.begin(), X.end());
    H[0][0] = X[0] - 'a';
    for (int i = 1; i < X.size(); i++)
        H[0][i] = (H[0][i-1] * 26 + X[i] - 'a') % M;

    int n = min(X.size(), Y.size()) - 1, len = -1;
    for (int i = 0; i <= n; i++) {
        ll h1 = get_hash(0, 0, i);
        ll h2 = get_hash(1, 0, i);
        if (h1 == h2) len = i;
        else break;
    }

    for (int i = len + 1; i < Y.size(); i++) ans += Y[i];
    return ans;
}

void excute() {
    string res = gen(s[x[0]], s[x[1]]);
    res = gen(res, s[x[2]]);
    if (best > (int) res.size()) s_best = res;
    best = min(best, (int) res.size());
}

void permu(int i) {
    for (int j = 0; j < 3; j++) {
        if (!fr[j]) {
            x[i] = j;
            if (i == 2) excute();
            else {
                fr[j] = true;
                permu(i+1);
                fr[j] = false;
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);

    for (int i = 0; i < 3; i++) cin >> s[i];

    int k = max(s[0].size(), max(s[1].size(), s[2].size()));
    POW[0] = 1;
    for (int i = 1; i <= k; i++) POW[i] = (POW[i-1] * 26) % M;
    H[0][0] = H[1][0] = H[2][0] = 0;

    best = N;
    permu(0);
    cout << best << " " << s_best << endl;

    return 0;
}
