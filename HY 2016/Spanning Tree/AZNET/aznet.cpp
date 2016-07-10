#include <bits/stdc++.h>

using namespace std;

const int M = 100001;
const int N = 10001;

struct pack
{
    int u, v, t;
} c[M];

int a[N], b[N], fr[M];
int root[N], rank[N];
int m, n;

void reset()
{
    for (int i = 1; i <= n; i++) root[i] = i, rank[i] = 0;
}

int findset(int u)
{
    return root[u] == u ? u : root[u] = findset(root[u]);
}

bool Union(int u, int v)
{
    u = findset(u);
    v = findset(v);
    if (u == v) return false;
    if (rank[u] > rank[v]) root[v] = u;
    else if (rank[v] > rank[u]) root[u] = v;
    else
    {
        root[v] = u;
        rank[u]++;
    }
    return true;
}

void divide(int &x, int &y)
{
    reset();
    for (int i = 1; i <= m; i++) fr[i] = 0;

    y = 0;
    for (int i = 1; i <= m; i++)
        if (c[i].t == 1 && Union(c[i].u, c[i].v)) y++;
    for (int i = 1; i <= m; i++)
        if (c[i].t == 2 && Union(c[i].u, c[i].v)) fr[i] = 1;

    reset();
    x = 0;
    for (int i = 1; i <= m; i++)
        if (fr[i])
        {
            Union(c[i].u, c[i].v);
            x++;
        }
    for (int i = 1; i <= m; i++)
        if (c[i].t == 2 && Union(c[i].u, c[i].v)) x++;
    x = n - 1 - x;
}

void make(int x, int y)
{
    reset();
    for (int i = 1; i <= m; i++) fr[i] = 0;

    for (int i = 1; i <= m; i++)
        if (c[i].t == 1) Union(c[i].u, c[i].v);

    for (int i = 1; i <= m; i++)
        if (c[i].t == 2 && Union(c[i].u, c[i].v)) fr[i] = 1;

    reset();
    int cnt = 0;
    for (int i = 1; i <= m; i++)
        if (fr[i])
        {
            Union(c[i].u, c[i].v);
            cnt++;
        }
    if (cnt < y)
        for (int i = 1; i <= m; i++)
            if (c[i].t == 2 && Union(c[i].u, c[i].v))
            {
                fr[i] = 1, cnt++;
                if (cnt == y) break;
            }
    for (int i = 1; i <= m; i++)
        if (c[i].t == 1 && Union(c[i].u, c[i].v)) fr[i] = 1;
}

void solve()
{
    int x, y;
    divide(x, y);

    int k = x;
    for (int i = x + 1; i <= y; i++)
        if (a[k] + b[n-1-k] > a[i] + b[n-1-i]) k = i;

    make(k, n-1-k);
    for (int i = 1; i <= m; i++)
        if (fr[i]) printf("%d ", i);
    printf("\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("aznet.inp", "r", stdin);
    freopen("aznet.out", "w", stdout);

    int T;
    scanf("%d\n", &T);
    while (T--)
    {
        scanf("%d %d\n", &n, &m);
        a[0] = b[0] = 0;
        for (int i = 1; i < n; i++) scanf("%d ", &a[i]);
        scanf("\n");
        for (int i = 1; i < n; i++) scanf("%d ", &b[i]);
        scanf("\n");
        for (int i = 1; i <= m; i++) scanf("%d %d %d\n", &c[i].u, &c[i].v, &c[i].t);
        solve();
    }

    return 0;
}

