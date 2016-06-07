#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 100001;

int A[maxN], x[maxN], pre[maxN], idx[maxN], dp[maxN], N;
int it[4*maxN], lazy[4*maxN], id[4*maxN];

void lazy_up(int x) {
    if (!lazy[x]) return;
    lazy[2*x] += lazy[x];
    it[x] += lazy[x];
    lazy[2*x+1] += lazy[x];
    it[2*x+1] += lazy[x];
    lazy[x] = 0;
}

void update(int x, int L, int R, int u, int v, int val) {
    if (L > v || R < u) return;
    if (L >= u && R <= v) {
        it[x] = val, lazy[x] = val;
        if (L == R) id[x] = L;
        return;
    }
    lazy_up(x);
    int mid = (L + R) >> 1;
    update(2*x, L, mid, u, v, val);
    update(2*x+1, mid+1, R, u, v, val);
    if (it[2*x] > it[2*x+1]) it[x] = it[2*x], id[x] = id[2*x];
    else it[x] = it[2*x+1], id[x] = id[2*x+1];
}

pair<int, int> getMax(int x, int L, int R, int u, int v) {
    if (L > v || R < u) return pair<int, int>(0, 0);
    if (L >= u && R <= v) return pair<int, int>(it[x], id[x]);
    lazy_up(x);
    int mid = (L + R) >> 1;
    pair<int, int> left = getMax(2*x, L, mid, u, v);
    pair<int, int> right = getMax(2*x+1, mid+1, R, u, v);
    return max(left, right);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) x[i] = A[i], pre[i] = 0;
    sort(x + 1, x + N + 1);
    for (int i = 1; i <= N; i++) idx[i] = lower_bound(x + 1, x + N + 1, A[i]) - x;
    for (int i = 1; i <= N; i++) {
        int p;
        pair<int, int> ii = getMax(1, 1, N, 1, idx[i] - 1);
        dp[i] = ii.first + 1;
        pre[i] = ii.second;
        update(1, 1, N, idx[i], idx[i], dp[i]);
    }
    cout << *max_element(dp + 1, dp + N + 1) << endl;
    int pos = max_element(dp + 1, dp + N + 1) - dp;
    vector <int> res;
    for (; pos; pos = pre[pos]) res.push_back(A[pos]);
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";

    return 0;
}
