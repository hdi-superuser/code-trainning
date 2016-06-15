#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
#define task "lis"

using namespace std;

const int maxN = 100001;

int N, A[maxN], x[maxN], cmp[maxN], dp[maxN];
int tree[4*maxN], d[4*maxN];

void lazy(int x) {
        if (!d[x]) return;
        tree[2*x] += d[x];
        d[2*x] += d[x];
        tree[2*x+1] += d[x];
        d[2*x+1] += d[x];
        d[x] = 0;
}

void update(int x, int L, int R, int u, int v, int val) {
        if (L > v || R < u) return;
        if (u <= L && R <= v) {
                d[x] = val;
                tree[x] = val;
                return;
        }
        lazy(x);
        int mid = (L + R) >> 1;
        update(2*x, L, mid, u, v, val);
        update(2*x+1, mid+1, R, u, v, val);
        tree[x] = max(tree[2*x], tree[2*x+1]);
}

int get(int x, int L, int R, int u, int v) {
        if (L > v || R < u) return 0;
        if (u <= L && R <= v) return tree[x];
        int mid = (L + R) >> 1;
        lazy(x);
        int left = get(2*x, L, mid, u, v);
        int right = get(2*x+1, mid+1, R, u, v);
        return max(left, right);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen(task".inp", "r", stdin);
    		freopen(task".out", "w", stdout);
    	#endif // ONLINE_JUDGE

        cin >> N;
        for (int i = 1; i <= N; i++) cin >> A[i];

        for (int i = 1; i <= N; i++) x[i] = A[i];
        sort(x + 1, x + N + 1);
        for (int i = 1; i <= N; i++) cmp[i] = lower_bound(x + 1, x + N + 1, A[i]) - x;

        for (int i = 1; i <= N; i++) {
                dp[i] = get(1, 1, N, 1, cmp[i] - 1) + 1;
                update(1, 1, N, cmp[i], cmp[i], dp[i]);
        }

        cout << *max_element(dp + 1, dp + N + 1);

    	return 0;
}

