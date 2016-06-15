#include <iostream>
#include <algorithm>

#define maxN 50001

using namespace std;

//ifstream fi("");
//ofstream fo("");

int N, M;
long long A[maxN], Tree[4*maxN], Lazy[4*maxN];

void Build(int node, int low, int high) {
    if (low == high) {
        Tree[node] = A[low];
    } else {
        int mid = (low + high) >> 1;
        Build(2*node, low, mid);
        Build(2*node+1, mid+1, high);
        Tree[node] = max(Tree[2*node], Tree[2*node+1]);
    }
}

void Lazy_Update(int node) {
    Lazy[2*node] += Lazy[node];
    Tree[2*node] += Lazy[node];
    Lazy[2*node+1] += Lazy[node];
    Tree[2*node+1] += Lazy[node];
    Lazy[node] = 0;
}

void Update(int node, int l, int r, int u, int v, int val) {
    if (l > v || u > r) return;
    if (l >= u && r <= v) {
        Lazy[node] += val;
        Tree[node] += val;
        return;
    }
    if (Lazy[node]) Lazy_Update(node);
    int mid = (l + r) >> 1;
    Update(2*node, l, mid, u, v, val);
    Update(2*node+1, mid+1, r, u, v, val);
    Tree[node] = max(Tree[2*node], Tree[2*node+1]);
}

long long get_MinQuery(int node, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && v >= r) return Tree[node];
    if (Lazy[node]) Lazy_Update(node);
    int mid = (l + r) >> 1;
    return max(get_MinQuery(2*node, l, mid, u, v), get_MinQuery(2*node+1, mid+1, r, u, v));
}

int main() {
    cin >> N >> M;
    Build(1, 1, N);
    while (M--) {
        int u, v, k;
        cin >> u >> v >> k;
        Update(1, 1, N, u, v, k);
    }
    cin >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        cout << get_MinQuery(1, 1, N, u, v) << endl;
    }
    return 0;
}
