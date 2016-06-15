#include <stdio.h>
#include <iostream>

#define file "KGSS"

using namespace std;

const int maxN = 100001;
const int inf  = 200000001;

struct node {
    int val, id;
} it[4*maxN], inf_node;

int M, N, A[maxN];

node max(node a, node b) {
    if (a.val > b.val) return a;
    return b;
}

void Build(int x, int L, int R, int u, int v) {
    if (L == R) {
        it[x].val = A[L];
        it[x].id = L;
    } else {
        int mid = (L + R) >> 1;
        Build(2*x, L, mid, u, v);
        Build(2*x + 1, mid + 1, R, u, v);
        it[x] = max(it[2*x], it[2*x+1]);
    }
}

void update(int x, int L, int R, int pos, int k) {
    if (L > pos || R < pos) return;
    if (L == pos && R == pos) {
        it[x].val = k;
        return;
    }
    int mid = (L + R) >> 1;
    update(2*x, L, mid, pos, k);
    update(2*x+1, mid+1, R, pos, k);
    it[x] = max(it[2*x], it[2*x+1]);
}

node get(int x, int L, int R, int u, int v) {
    if (L > v || R < u) return inf_node;
    if (L >= u && R <= v) return it[x];
    int mid = (L + R) >> 1;
    node left = get(2*x, L, mid, u, v);
    node right = get(2*x+1, mid+1, R, u, v);
    return max(left, right);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    #endif // ONLINE_JUDGE

    inf_node.val = -inf;    inf_node.id = 0;
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    Build(1, 1, N, 1, N);
    cin >> M;
    while (M--) {
        char t;
        int u, v;
        cin >> t >> u >> v;
        if (t == 'U') update(1, 1, N, u, v);
        else {
            node max1 = get(1, 1, N, u, v);
            node max2 = get(1, 1, N, u, max1.id-1);
            node max3 = get(1, 1, N, max1.id+1, v);
            node max4 = max(max2, max3);
            cout << max1.val + max4.val << endl;
        }
    }

    return 0;
}
