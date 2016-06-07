// May 18 2016
#include <iostream>
#include <cstdio>
#include <vector>

#define task "GAME"

using namespace std;

const int MAX = 1001;
typedef vector<int> vi;

vi adj[MAX], add[MAX];
int f[MAX], deg[MAX];
int N, M, start;

void pre_process(bool op) {
    if (!op) return;
    #ifndef ONLINE_JUDGE
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
}

bool _lose(int x) {
    for (int j = 0, y; y = adj[x][j]; j++)
        if (f[y] == 2) return true;
    return false;
}

bool _win(int x) {
    for (int j = 0, y; y = adj[x][j]; j++)
        if (f[y] != 1) return false;
    return true;
}

void generate_f(int u) {
    int td = 0;
    if (_lose(u)) td = 1;
    else if (!deg[u] || _win(u)) td = 2;
    f[u] = td;
    if (td) {
        for (int i = 0, v; v = add[u][i]; i++)
            if (!f[v]) generate_f(v);
    }
}

int main() {
    pre_process(true);
    cin >> N >> M >> start;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        add[v].push_back(u);
        deg[u]++;
    }
    for (int i = 1; i <= N; i++) { adj[i].push_back(0); add[i].push_back(0); }
    for (int i = 1; i <= N; i++)
        if (!deg[i]) generate_f(i);
    for (int i = 1; i <= N; i++) cout << f[i] << " ";

    return 0;
}
