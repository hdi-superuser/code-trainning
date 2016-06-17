#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1001;
const int inf = 0x3c3c3c3c;

int n, m, x[N], y[N];
bool f[N][N], visited[N];
ll dist[N];

double prim() {
	for (int i = 1; i <= n; i++) dist[i] = 1LL*inf*inf;
	dist[1]=0;
	double ans = 0;

	while (1) {
        int u = 0;
        for (int i=1; i<=n; i++)
            if (!visited[i])
                if (u==0 || dist[i] < dist[u]) u = i;
        if (u == 0) break;
		ans += sqrt(dist[u]);
		visited[u] = true;
		for (int i = 1; i <= n; i++)
            if (!visited[i]) {
                ll temp = 0LL;
                if (!f[u][i]) temp = 1LL*(x[u]-x[i])*(x[u]-x[i]) + 1LL*(y[u]-y[i])*(y[u]-y[i]);
                dist[i] = min(dist[i], temp);
            }
	}
	return ans;
}

main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d%d", &x[i], &y[i]);
	for (int i=1; i<=m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		f[u][v] = f[v][u] = true;
	}
    (cout << fixed).precision(2);
	cout << prim() << endl;
}
