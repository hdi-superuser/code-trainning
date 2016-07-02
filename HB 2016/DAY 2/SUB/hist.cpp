#include <bits/stdc++.h>

#define x first
#define y second
#define ll long long

using namespace std;

typedef pair<ll, ll> ii;
const int N = 1000001;

ll a[N], L[N], R[N];
int n;

int main() {
    	ios_base::sync_with_stdio(NULL);
	freopen("hist.inp", "r", stdin);
	freopen("hist.out", "w", stdout);
	n = 1;
	while (n) {
        cin >> n;
        if (n == 0) return 0;
        for (int i = 1; i <= n; i++) cin >> a[i], L[i] = R[i] = i;
        stack<ii> st;	st.push(ii(-1, 0));
        for (int i = 1; i <= n; i++) {
            while (st.size() && st.top().x >= a[i]) st.pop();
            L[i] = st.top().y + 1;	st.push(ii(a[i], i));
        }
        while (st.size()) st.pop();
        st.push(ii(-1, n+1));
        for (int i = n; i >= 1; i--) {
            while (st.size() && st.top().x >= a[i]) st.pop();
            R[i] = st.top().y - 1;	st.push(ii(a[i], i));
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, (R[i] - L[i] + 1)*a[i]);
        cout << ans << endl;
	}
}

