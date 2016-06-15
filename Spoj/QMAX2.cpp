#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

using namespace std;

const int maxN = 50001;
const ll inf = 0;

ll tree[maxN*4], lazy[maxN*4];

int N, M;

void lazy_up(int x) {
	if (!lazy[x]) return;
	tree[2*x] += lazy[x];
	lazy[2*x] += lazy[x];
	tree[2*x+1] += lazy[x];
	lazy[2*x+1] += lazy[x];
	lazy[x] = 0;
}

void update(int x, int L, int R, int u, int v, ll val) {
	if (L > v || R < u) return;
	if (L >= u && R <= v) {
		tree[x] += val; 
		lazy[x] += val;
		return;
	}
	lazy_up(x);
	int mid = (L + R) >> 1;
	update(2*x, L, mid, u, v, val);
	update(2*x+1, mid+1, R, u, v, val);
	tree[x] = max(tree[2*x], tree[2*x+1]);
}

ll get(int x, int L, int R, int u, int v) {
	if (L > v || R < u) return inf;
	if (L >= u && R <= v) return tree[x];
	lazy_up(x);
	int mid = (L + R) >> 1;
	int left = get(2*x, L, mid, u, v);
	int right = get(2*x+1, mid+1, R, u, v);
	return max(left, right);	
}

int main() {
	//freopen("in.txt", "r", stdin);
	try {	
		cin >> N >> M;
		while (M--) {
			int c, x, y;
			cin >> c >> x >> y;
			if (!c) {
				int k;
				cin >> k;
				update(1, 1, N, x, y, k);
			} else cout << get(1, 1, N, x, y) << endl;
		}
	} catch (const overflow_error& e) {
		cout << e.what();
	}
	return 0;
}
