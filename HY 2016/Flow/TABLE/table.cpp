#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int N = 201;
const int inf = 2000000001;

int m, n, flow, r[N], c[N], fr[N], par[N];
int w[N][N], f[N][N];
vi adj[N], sinklist;

void make_edge(int a, int b, int c) {
    adj[a].push_back(b);    adj[b].push_back(a);
    w[a][b] = c;            w[b][a] = 0;
}

bool augment_path(int source, int sink) {
    queue<int> q;
    q.push(source);
    memset(par, -1, sizeof par);
    memset(fr, 0, sizeof fr);
    fr[source] = true;

    while (!q.empty()) {
        int u = q.front();  q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!fr[v] && w[u][v] > 0) {
                fr[v] = true;
                par[v] = u;
                if (v == sink) continue;
                q.push(v);
            }
        }
    }

    return par[sink] != -1;
}

void enlarge(int source, int sink) {
    int u, v = sink;
    flow = inf;

    while (par[v] > -1)
        u = par[v],
        flow = min(flow, w[u][v]),
        v = u;

    v = sink;
    while (par[v] > -1)
        u = par[v],
        w[u][v] -= flow,
        w[v][u] += flow,
        v = u;
}

int maxflow(int source, int sink) {
    int total_flow = 0;
    sinklist = adj[sink];

    while (augment_path(source, sink)) {
        for (int i = 0; i < sinklist.size(); i++) {
            int u = sinklist[i];
            if (!fr[u] || w[u][sink] <= 0) continue;
            par[sink] = u;
            enlarge(source, sink);
            total_flow += flow;
        }
    }

    return total_flow;
}

void solve() {
    cin >> m >> n;

    int sumr = 0, sumc = 0, source = m + n + 2, sink = m + n + 3;

    for (int i = 0; i < m; i++) {
        cin >> r[i];
        sumr += r[i];
        make_edge(source, i, r[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sumc += c[i];
        make_edge(i + m, sink, c[i]);
    }

    if (sumr != sumc) { cout << "-1" << endl; return; }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            make_edge(i, j + m, 1);

    if (maxflow(source, sink) != sumc) { cout << "-1" << endl; return; }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int d = w[j + m][i];
            w[i][j + m] = w[j + m][i] = 0;

            if (d) {
                w[source][i] = w[j + m][sink] = 1;
                if (augment_path(source, sink)) {
                    enlarge(source, sink);
                    d = 0;
                } else w[source][i] = w[j + m][sink] = 0;
            }
            cout << d;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    solve();
    return 0;
}
