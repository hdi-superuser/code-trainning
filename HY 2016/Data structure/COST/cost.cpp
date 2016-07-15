#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const int N = 1000002;
const ll inf = 1000000001;

int n;
ll a[N];

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("cost.inp", "r", stdin);
    freopen("cost.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    a[0] = a[n + 1] = inf;
    ll ans = 0;
    vi stack;
    stack.push_back(a[0]);

    for (int i = 1; i <= n + 1; i++) {
        while (a[i] >= stack.back()) {
            ll reduce = min(stack[stack.size() - 2], a[i]);
            if (reduce == inf) break;
            ans += reduce;
            stack.pop_back();
        }
        stack.push_back(a[i]);
    }

    cout << ans;

    return 0;
}
