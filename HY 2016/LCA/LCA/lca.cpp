/*
 * Author: Huynh Duy Idol
 * Lang:
 * Problem:
 * Solution:
 * Date:
 NCC - No Copyright Code
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

#define maxN 100001

using namespace std;

vector <int> A[maxN];
int D[maxN], Dad[maxN], Par[maxN][100];
int N, K, Q;

void Enter() {
    cin >> N >> Q;
    K = trunc(log(N)/log(2));
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void BFS() {
    int Q[maxN], fr[maxN] = {0}, first, last;
    first = last = 1;
    Q[1] = 1;
    D[1] = 1;
    fr[1] = 1;
    while (first <= last) {
        int u = Q[first++];
        for (int i = 0; i < A[u].size(); i++) {
            int v = A[u][i];
            if (!fr[v]) {
                fr[v] = 1;
                D[v] = D[u] + 1;
                Dad[v] = u;
                Q[++last] = v;
            }
        }
    }
}

void RMQ() {
    for (int i = 1; i <= N; i++) Par[i][0] = Dad[i];
    for (int j = 1; j <= K; j++)
        for (int i = 1; i <= N; i++) Par[i][j] = Par[Par[i][j-1]][j-1];
}

int LCA(int u, int v) {
    if (D[v] > D[u]) return LCA(v, u);
    int Delta = D[u] - D[v];
    for (int i = K; i >= 0; i--)
        if ((Delta >> i) & 1) u = Par[u][i];
    if (u == v) return u;
    for (int i = K; i >= 0; i--)
        if (Par[u][i] != Par[v][i]) u = Par[u][i], v = Par[v][i];
    return Par[u][0];
}

void Process() {
    while (Q--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        int a = LCA(u, v), b = LCA(x, y);
        if (D[a] < D[b]) {
            if (LCA(u, b) == b || LCA(v, b) == b) cout << "war again" << endl;
            else cout << "peace" << endl;
        } else {
            if (LCA(x, a) == a || LCA(y, a) == a) cout << "war again" << endl;
            else cout << "peace" << endl;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("NUMBERLAND.INP", "r", stdin);
        freopen("NUMBERLAND.OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    Enter();
    BFS();
    RMQ();
    Process();
    return 0;
}
