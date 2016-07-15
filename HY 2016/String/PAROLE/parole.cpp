#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 300001;
const ll M = 1000000007;

ll POW[N], H[N], T[N];

string s;

ll get_hash_s(int L, int R) {
    return (H[R] - H[L-1] * POW[R-L+1] + M*M) % M;
}

ll get_hash_t(int L, int R) {
    return (T[R] - T[L-1] * POW[R-L+1] + M*M) % M;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("parole.inp", "r", stdin);
    freopen("parole.out", "w", stdout);

    cin >> s;
    string t = s;
    string ans1 = s, ans2 = s;      s = " " + s;
    reverse(t.begin(), t.end());    t = " " + t;

    int n = s.size() - 1;

    POW[0] = 1;
    H[0] = T[0] = 0;
    for (int i = 1; i <= n; i++)
        H[i] = (H[i-1] * 2039 + s[i] - 'a') % M,
        T[i] = (T[i-1] * 2039 + t[i] - 'a') % M,
        POW[i] = (POW[i-1] * 2039) % M;

    int len = 0;
    for (int i = n; i >= 0; i--) {
        ll h1 = get_hash_s(1, i);
        ll h2 = get_hash_t(n - i + 1, n);
        if (h1 == h2) { len = i;    break;  }
    }

    for (int i = len + 1; i <= n; i++) ans1 = s[i] + ans1;

    len = n + 1;
    for (int i = 1; i <= n; i++) {
        ll h1 = get_hash_s(i, n);
        ll h2 = get_hash_t(1, n - i + 1);
        if (h1 == h2) { len = i;    break;  }
    }

    for (int i = len - 1; i >= 1; i--) ans2 = ans2 + s[i];

    string ans;
    if (ans1.size() < ans2.size()) ans = ans1;
    else ans = ans2;

    cout << ans << endl;

    return 0;
}
