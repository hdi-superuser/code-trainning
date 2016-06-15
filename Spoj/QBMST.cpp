#include <stdio.h>
#include <algorithm>

#define file "QBMST"
#define maxN 15001

using namespace std;

struct data {
    int u, v, c;
};

int root[maxN];
int ans = 0;
data E[maxN];
int N, M;

inline bool comp(data p, data q) {
    return p.c < q.c;
}

void Enter() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++) scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].c);
}

int GetRoot(int x) {
    if (root[x] == 0) return x;
    return root[x] = GetRoot(root[x]);
}

void Kruskal() {
    sort(E+1, E+M+1, comp);
    for (int i = 1; i <= M; i++) {
        int r1 = GetRoot(E[i].u);
        int r2 = GetRoot(E[i].v);
        if (r1 != r2) {
            ans += E[i].c;
            root[r1] = r2;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    Enter();
    Kruskal();
    printf("%d", ans);
    return 0;
}

