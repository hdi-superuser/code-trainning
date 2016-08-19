/*
    HLD templates, solution for spoj/QTREE
 */

#include <bits/stdc++.h>

#define task "main"
#define root 0
#define N 100001
#define LN 14

using namespace std;

vector <int> adj[N], _cost[N], index[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], par[N][LN + 1], otherEnd[N], subsize[N];
int IT[6*N], Q_IT[6*N];

void make_tree(int id, int l, int r) {
    if (l == r - 1) {
        IT[id] = baseArray[l];
        return;
    }
    int mid = (l + r) >> 1;
    make_tree(2*id, l, mid);
    make_tree(2*id + 1, mid + 1, r);
}

void update_tree(int id, int l, int r, int pos, int val) {
    if (l > pos || r <= pos) return;
    if (l == pos &&  r - 1 == pos) {
        IT[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update_tree(2*id, l, mid, pos, val);
    update_tree(2*id + 1, mid + 1, r, pos, val);
    IT[id] = max(IT[2*id], IT[2*id + 1]);
}

void query_tree(int id, int l, int r, int u, int v) {
    if (l >= v || r <= u) {
        Q_IT[id] = -1;
        return;
    }
    if (l >= u && r <= v) {
        Q_IT[id] = IT[id];
        return;
    }
    int mid = (l + r) >> 1;
    query_tree(2*id, l, mid, u, v);
    query_tree(2*id + 1, mid + 1, r, u, v);
    Q_IT[id] = max(Q_IT[2*id], Q_IT[2*id + 1]);
}

int query_up(int u, int v) {
    if (u == v) return 0;
    int uchain, vchain = chainInd[v], ans = -1; // uchain, vchain are chain number of u, v

    while (true) {
        uchain = chainInd[u];
        if (uchain == vchain) {
            // both u and v are in the same chain, so we need to query from u to v, update answer and break
            if (u == v) break;
            query_tree(1, 0, ptr, posInBase[v] + 1, posInBase[u] + 1);
            ans = max(ans, Q_IT[1]);    // update answer
            break;
        }
        query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u] + 1);
        // above is call to segment tree query function.
        // we do from chainHead of u till u.
        ans = max(ans, Q_IT[1]);
        u = chainHead[uchain];
        u = par[u][0];
    }
    return ans;
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int delta = depth[u] - depth[v];
    for (int i = LN; i >= 0; i--)
        if ((delta >> i) & 1) u = par[u][i];
    if (u == v) return u;
    for (int i = LN; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i],
            v = par[v][i];
    return par[u][0];
}

void query(int u, int v) {
    int lca = LCA(u, v);
    int ans = query_up(u, lca);
    ans = max(ans, query_up(v, lca));
    cout << ans << endl;
}

void change(int pos, int val) {
    int u = otherEnd[pos];
    update_tree(1, 0, ptr, posInBase[u], val);
}


/*
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 */

void HLD(int curNode, int _cost, int prev) {
    if (chainHead[chainNo] == -1) chainHead[chainNo] = curNode; // assigned chainHead
    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr;
    baseArray[ptr++] = _cost;

    int sc = -1, n_cost; // find special child
    for (int i = 0; i < adj[curNode].size(); i++)
        if (adj[curNode][i] != prev) {
            if (sc == -1 || subsize[sc] < subsize[adj[curNode][i]])
                sc = adj[curNode][i],
                n_cost = _cost[curNode][i];
        }

    if (sc != -1) HLD(sc, n_cost, curNode);

    for (int i = 0; i < adj[curNode].size(); i++)
        if (adj[curNode][i] != sc) {
            chainNo++;
            HLD(adj[curNode][i], _cost[curNode][i], curNode);
        }
}

void Solve() {
    int Case;   cin >> Case;
    while (Case--) {
        ptr = 0;
        int n;  cin >> n;

        // reset for new test case
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            _cost[i].clear();
            index[i].clear();
            chainHead[i] = -1;
            for (int j = 0; j < LN; j++)
                par[j][i] = -1;
        }

        // enter several data
        for (int i = 1; i < n; i++) {
            int u, v, c;    cin >> u >> v >> c;
            u--;    v--;
            adj[u].push_back(v);    _cost[u].push_back(c);
            index[u].push_back(i-1);
            adj[v].push_back(u);
            _cost[v].push_back(c);
            index[v].push_back(i-1);
        }

        chainNo = 0;
        dfs(root, -1);       // set up subsize, depth and parent for each node
        HLD(root, -1, -1);   // decomposed the tree and created baseArray
        make_tree(1, 0, ptr);// We use baseArray and construct the needed segment tree

        // RMQ
        for (int j = 1; j < LN; j++)
            for (int i = 1; i <= n; i++)
                par[i][j] = par[par[i][j-1]][j-1];

        // main execute
        while (true) {
            string s;   cin >> s;
            if (s[0] == 'D') break;
            int a, b; cin >> a >> b;
            if (s[0] == 'Q') query(a - 1, b - 1);
            else change(a - 1, b);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif // ONLINE_JUDGE
    Solve();
    return 0;
}
