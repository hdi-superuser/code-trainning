#include <iostream>
#include <algorithm>

#define maxN 10001

using namespace std;

struct data {
    int u, v, k;
};

data A[maxN];
int N, M, Root[maxN];

inline bool comp(data p, data q) {
    return p.k < q.k;
}

void Enter() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) cin >> A[i].u >> A[i].v >> A[i].k;
}

int getRoot(int x) {
    if (!Root[x]) return x;
    return Root[x] = getRoot(Root[x]);
}

void Kruskal() {
    int ans = 0;
    sort(A+1, A+M+1, comp);
    for (int i = 1; i <= M; i++) {
        int r1 = getRoot(A[i].u);
        int r2 = getRoot(A[i].v);
        if (r1 == r2) continue;
        ans = max(ans, A[i].k);
        Root[r1] = r2;
    }
    cout << ans;
}

int main() {
    Enter();
    Kruskal();
    return 0;
}
