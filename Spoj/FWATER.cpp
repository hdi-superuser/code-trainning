#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 301;

int N, ne, root[maxN+1];
struct Edge {
        int u, v, k;
} E[maxN*maxN];

inline bool cmp(Edge p, Edge q) {
        return p.k < q.k;
}

int findSet(int x) {
        if (root[x] == x) return root[x];
        return root[x] = findSet(root[x]);
}

int main() {
        //freopen("spoj.in", "r", stdin);

        cin >> N;
        for (int i = 1; i <= N; i++) {
                int w;
                cin >> w;
                E[++ne].u = 0;  E[ne].v = i;    E[ne].k = w;
        }
        for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++) {
                        int w;
                        cin >> w;
                        E[++ne].u = i;  E[ne].v = j;    E[ne].k = w;
                }

        sort(E + 1, E + ne + 1, cmp);
        for (int i = 0; i <= N; i++) root[i] = i;

        int ans = 0;
        for (int i = 1; i <= ne; i++) {
                int r1 = findSet(E[i].u);
                int r2 = findSet(E[i].v);
                if (r1 == r2) continue;
                ans += E[i].k;
                root[r1] = r2;
        }

        cout << ans;
        return 0;
}
                  
