#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
} p[800];

struct data {
    int x, y;
    double z;
} e[300001];

int a[800][800], root[800];
int n, m, ne, np;

bool cmp(data a, data b) {
    return a.z < b.z;
}

int getroot(int x) {
    return root[x] == x ? x : root[x] = getroot(root[x]);
}

int main() {
    //freopen("in.txt", "r", stdin);
    freopen("HIGHWAY.INP", "r", stdin);
    freopen("HIGHWAY.OUT", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        p[i].x = x; p[i].y = y;
    }
    scanf("%d\n", &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d\n", &u, &v);
        a[u][v] = a[v][u] = 1;
        e[++ne].x = u;
        e[ne].y = v;
        e[ne].z = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] || a[j][i]) continue;
            e[++ne].x = i;   e[ne].y = j;
            e[ne].z = sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y));
        }
    }
    double ans = 0.0;
    for (int i = 1; i <= n; i++) root[i] = i;
    sort(e + 1, e + ne + 1, cmp);
    vector < pair<int, int> > res;
    for (int i = 1; i <= ne; i++) {
        int r1 = getroot(e[i].x);
        int r2 = getroot(e[i].y);
        if (r1 == r2) continue;
        ans += e[i].z;
        if (e[i].z != 0.0) res.push_back(make_pair(e[i].x, e[i].y));
        root[r1] = r2;
    }
    printf("%.2lf\n", ans);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i].first << " " << res[i].second << endl;
}

