#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
typedef long long ll;

int R, L;
ll a[N], s[N], B;

bool ok(int L, int R) {
    int M = (L+R) >> 1;
    ll sum = (s[R]-s[M-1]) - 1LL*a[M]*(R-M+1) + 1LL*a[M]*(M-L+1) - (s[M]-s[L-1]);
    return sum <= B;
}

int main() {
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> R >> L >> B;
    for (int i = 1; i <= R; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    int ans = 0, t = 1;
    for (int i = 1; i <= R; i++) {
        while (t + 1 <= R && ok(i, t + 1)) t++;
        ans = max(ans, t - i + 1);
    }
    cout << ans;
    return 0;
}

