#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<li> vli;

const int N = 201;
const int W = 60001;
const ll inf = 7000001;

ll dist[2][N];
int n, pos[N][N], tr[2][N], color[N];
vli adj[N];

void dijkstra(int s, int op) {
    priority_queue<li, vli, greater<li> > q;
    q.push(ii(0LL, s));
    for (int i = 1; i <= N; i++) dist[op][i] = inf;
    memset(tr[op], -1, sizeof tr[op]);
    dist[op][s] = 0LL;

    int cnt = 0;
    while (!q.empty()) {
        int u = q.top().y, w = q.top().x;
        q.pop();
        if (w > dist[op][u]) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].x;
            if (dist[op][v] > dist[op][u] + 1LL*adj[u][i].y && color[v] != color[u]) {
                dist[op][v] = dist[op][u] + 1LL*adj[u][i].y;
                tr[op][v] = u;
                q.push(ii(dist[op][v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    freopen("dart.inp", "r", stdin);
    freopen("dart.out", "w", stdout);

    cin >> n;
    int u, v;
    ll wuv, wvu;
    char c;
    int i = 0;

    while (cin >> u >> v >> wuv >> wvu >> c) {
        if (u == 0) break;
        i++;
        if (c == 'M') {
            adj[u + 'M'].push_back(ii(v, wuv));
            adj[v].push_back(ii(u + 'M', wvu));
            pos[u + 'M'][v] = pos[v][u + 'M'] = i;
        } else {
            adj[u].push_back(ii(v + 'M', wuv));
            adj[v + 'M'].push_back(ii(u, wvu));
            pos[u][v + 'M'] = pos[v + 'M'][u] = i;
        }
        color[v] = color[u] = 1;
        color[v + 'M'] = color[u + 'M'] = 0;
    }

    dijkstra(n, 0);
    dijkstra(n + 'M', 1);

    ll ans = inf;
    int ans_op = 0, ans_pos = 0;
    for (int i = 0; i <= 1; i++) {
        if (ans > dist[i][1 + 'M'])
            ans = dist[i][1 + 'M'],
            ans_op = i,
            ans_pos = 1 + 'M';
        if (ans > dist[i][1])
            ans = dist[i][1],
            ans_op = i,
            ans_pos = 1;
    }

    vector <int> res, t;
    cout << ans << endl;

    while (tr[ans_op][ans_pos] != -1) {
        t.push_back(ans_pos);
        if (ans_pos > 'M') res.push_back(ans_pos - 'M');
        else res.push_back(ans_pos);
        ans_pos = tr[ans_op][ans_pos];
    }

    if (ans_pos > 'M') res.push_back(ans_pos - 'M');
    else res.push_back(ans_pos);

    t.push_back(ans_pos);
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
    cout << endl;
    for (int i = t.size() - 1; i; i--) cout << pos[t[i]][t[i-1]] << " ";

    return 0;
}
