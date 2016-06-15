#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 100001;

int N, M, ne, p[maxN], rank[maxN];
struct Edge {
	int u, v, k;
} E[maxN];

bool cmp(Edge p, Edge q) {
	return p.k > q.k;
}

void make_set(int x) {
	p[x] = x;
	rank[x] = 0;
}

void link(int x, int y) {
	if (rank[x] > rank[y]) p[y] = x;
	else {
		rank[x] = y;
		if (rank[x] == rank[y]) rank[y]++;
	}
}

int find_set(int x) {
	if (x != p[x]) p[x] = find_set(p[x]);
	return p[x];
}

void union_set(int x, int y) {
	link(find_set(x), find_set(y));
}

int main() {
	//freopen("spoj.inp", "r", stdin);
   //     freopen("spoj.out", "w", stdout);

	int sum = 0;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int u, v, k;
		cin >> u >> v >> k;
		E[i].u = u;	E[i].v = v;	E[i].k = k;
		sum += k;
	}

        for (int i = 1; i <= N; i++) make_set(i);

	int mst = 0;
	sort(E + 1, E + M + 1, cmp);
	for (int i = 1; i <= M; i++) {
		int r1 = find_set(E[i].u);
		int r2 = find_set(E[i].v);
		if (r1 == r2) continue;
		mst += E[i].k;
		p[r1] = r2;
	}

	cout << sum -  mst << endl;
}
