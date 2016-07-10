#include <bits/stdc++.h>

using namespace std;

const int N = 300001;
int p[N], n, w;
struct data {
    int u, v, k;
} e[100001];

vector <int> t[N];

bool cmp(data p, data q) {
    return p.k < q.k;
}

int root(int x) {
    return p[x] == x ? x : p[x] = root(p[x]);
}

vector < pair<int, int> > res;
int kruskal(int m) {
    for (int i = 1; i <= n; i++) p[i] = i;
    int sum = 0;
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int r1 = root(e[i].u);
        int r2 = root(e[i].v);
        if (r1 == r2) continue;
        res.push_back(make_pair(e[i].u, e[i].v));
        sum += e[i].k;
        p[r1] = r2;
    }
    return sum;
}


int main() {
    freopen("MINTREE.INP", "r", stdin);
    freopen("MINTREE.OUT", "w", stdout);
    //freopen("in.txt", "r", stdin);
    scanf("%d %d\n", &n, &w);
    for (int i = 1; i <= w; i++) {
        scanf("%d %d %d\n", &e[i].u, &e[i].v, &e[i].k);
    }
    cout << kruskal(w) << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i].first << " " << res[i].second << endl;
}


