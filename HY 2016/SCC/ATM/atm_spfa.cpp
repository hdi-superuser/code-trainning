#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500001;

struct sides {
    int u,v;
    int next;
} s[N], t[N];

stack<int> h;
queue<int> q;
bool vis[N], ins[N];
int dis[N], w[N], f[N];
int dfn[N], low[N], dep;
int first[N], ind;
int n, m, p, S, T[N], ans;

void tarjan(int x) {
    vis[x] = ins[x] = 1;
    dfn[x] = low[x] = ++dep;
    h.push(x);
    for(int i = first[x]; i != -1 ; i = s[i].next)
        if(!vis[s[i].v]) {
            tarjan(s[i].v);
            low[x] = min(low[x], low[s[i].v]);
        } else if(ins[s[i].v])
            low[x] = min(low[x], low[s[i].v]);
    if(dfn[x] == low[x]) {
        while(h.top() !=x) {
            f[h.top()] = x, ins[h.top()] = 0;
            w[x] += w[h.top()];
            h.pop();
        }
        f[x] = x, ins[x] = 0, h.pop();
    }
}

void rebuild() {
    int id = ind;
    memset(first, -1, sizeof first);
    ind = 0;
    for(int i = 0; i < id; i++)
        if(f[s[i].u] != f[s[i].v])
            t[ind] = (sides) {f[s[i].u], f[s[i].v], first[f[s[i].u]]}, first[f[s[i].u]] = ind++;
    memcpy(s, t, sizeof(t));
}

void spfa() {
    q.push(f[S]);
    while(!q.empty()) {
        int sd = q.front();
        q.pop();
        ins[sd] = 0;
        for(int i = first[sd]; i != -1; i = s[i].next)
            if(dis[s[i].v] < dis[sd] + w[sd]) {
                dis[s[i].v] = dis[sd] + w[sd];
                if(!ins[s[i].v]) {
                    ins[s[i].v] = 1;
                    q.push(s[i].v);
                }
            }
    }
}

int main() {
    freopen("atm.inp:", "r", stdin);
    freopen("atm.out", "w", stdout);

    scanf("%d%d", &n, &m);
    memset(first, -1, sizeof (first));
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        s[ind] = (sides) {u, v, first[u]}, first[u] = ind++;
    }
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    scanf("%d%d", &S, &p);
    for(int i = 1; i <= p; i++) scanf("%d", &T[i]);
    for(int i = 1; i <= n; i++)
        if(!vis[i]) tarjan(i);

    rebuild();
    spfa();

    for(int i = 1; i <= p; i++)
        ans = max(ans, dis[f[T[i]]] + w[f[T[i]]]);
    printf("%d",ans);

    return 0;
}
