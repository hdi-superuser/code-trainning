#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 100001;

int n, k, a[N];
ll f[2][N], s[N], F[N], G[N];
priority_queue<ll> h1, h2;

int main() {
    freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &k); k++;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];

	f[0][0] = 0; h1.push(f[0][0]);
	for (int i=1; i<=n+1; i++) {
		if (i-k-1 >= 0) h2.push(f[0][i-k-1]);
		while (h1.size() && h2.size() && h1.top() == h2.top()) { h1.pop(); h2.pop(); }
		f[1][i] = h1.top() + s[i-1];
		f[0][i] = f[1][i] - s[i]; h1.push(f[0][i]);
	}
	cout << f[1][n+1] << endl;
}
