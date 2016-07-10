#include <bits/stdc++.h>

using namespace std;

const int M = 10001;
const int N = 1001;
const int inf = 2000000001;

struct data {
    int a, b, c;
} e[M];

struct ST {
    int w;
    vector <data> List;
} MST;

int n, m, p[N], fr[N][N];
int ans = inf;

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

ST kruskal() {
    for (int i = 1; i <= n; i++) p[i] = i;
    ST mst; mst.w = 0; mst.List.clear();

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (fr[e[i].a][e[i].b]) continue;
        int r1 = getroot(e[i].a);
        int r2 = getroot(e[i].b);
        if (r1 == r2) continue;
        mst.w += e[i].c;    cnt++;  mst.List.push_back(e[i]);
	if (cnt == n - 1) return mst;
        if (mst.w > ans) return mst;
        p[r1] = r2;
    }

    if (cnt < n - 1) {
        mst.w = -1;
        return mst;
    }

    return mst;
}

int main() {
    freopen("olymnet.inp", "r", stdin);
    freopen("olymnet.out", "w", stdout);

    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, k;
        scanf("%d %d %d\n", &u, &v, &k);
        e[i] = make_data(u, v, k);
    }

    sort(e + 1, e + m + 1, cmp);
    MST = kruskal();
    for (int i = 0; i < MST.List.size(); i++) {
        fr[MST.List[i].a][MST.List[i].b] = 1;
        ST second_MST = kruskal();
        if (second_MST.w != -1) ans = min(ans, second_MST.w);
        fr[MST.List[i].a][MST.List[i].b] = 0;
    }

    if (ans == inf) ans = MST.w;
    cout << MST.w << " " << ans;

    return 0;
}
