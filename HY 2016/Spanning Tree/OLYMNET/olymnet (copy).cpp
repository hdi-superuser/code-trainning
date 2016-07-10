#include <bits/stdc++.h>

#define task "olymnet"

using namespace std;

const int M = 10001;
const int N = 1001;
const int inf = 2000000001;

struct data {
    int a, b, c;
    bool mark = false;
} e[M];


vector < int > adj[N];
int n, m, w[N][N], p[N], pos;
int ans = inf, mst;
int d[N], fr[N], tr[N], par[N][11];

data make_data(int x, int y, int z) {
    data mydata;
    mydata.a = x; mydata.b = y; mydata.c = z;
    return mydata;
}

int getroot(int x) {
    return p[x] == x ? x : p[x] = getroot(p[x]);
}

bool cmp(data p, data q) {
    return p.c < q.c;
}

int kruskal() {
    for (int i = 1; i <= n; i++) p[i] = i;
    int mst = 0;

    int cnt = n-1;
    for (int i = 1; i <= m; i++) {
        int r1 = getroot(e[i].a);
        int r2 = getroot(e[i].b);
        if (r1 == r2) continue;
        mst += e[i].c;    cnt--;
        adj[e[i].a].push_back(e[i].b);
        adj[e[i].b].push_back(e[i].a);
        e[i].mark = true;
        p[r1] = r2;
    }

    if (cnt > 0) return 0;

    return mst;
}

int bfs(int s, int f) {
    memset(fr, 0, sizeof fr);  memset(tr, -1, sizeof tr);
    fr[s] = 1; tr[s];  queue <int> q;  q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (fr[v]) continue;
            tr[v] = u;
            fr[v] = 1;
            q.push(v);
        }
    }

    if (tr[f] == -1) return 0;

    int Max = 0;
    while (f != s && tr[f] != -1) {
        int nf = tr[f];
        Max = max(Max, w[nf][f]);
        f = nf;
    }

    return Max;
}

/*
void dfs(int u) {
    fr[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (fr[v]) continue;
        par[v][0] = u;
        d[v] = d[u] + 1;
        dfs(v);
    }
}
*/
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, k;
        scanf("%d %d %d\n", &u, &v, &k);
        e[i] = make_data(u, v, k);
        w[u][v] = w[v][u] = k;
    }

    sort(e + 1, e + m + 1, cmp);
    printf("%d ", mst = kruskal());

    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < adj[i].size(); j++) cerr << adj[i][j] << " ";
        cerr << endl;
    }
    */
    for (int i = 1; i <= m; i++) {
        if (e[i].mark) continue;
        int temp = bfs(e[i].a, e[i].b);
        if (temp) ans = min(ans, abs(e[i].c - temp));
        cerr << e[i].c << " " << bfs(e[i].a, e[i].b) << endl;
        break;
    }
    /*
    dfs(1);
    k = floor(log(N)/log(10));
    for (int j = 1; j <= k; j++)

    */
    if (ans == inf) ans = 0;
    printf("%d", mst + ans);

    return 0;
}
