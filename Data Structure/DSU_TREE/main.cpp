/*
    problems description:   Given a tree, every vertice has a color.
                            Query is how many vertices in subtree of vertices v
                            are colored with color c ?
 */
#include <bits/stdc++.h>

#define task "main"

using namespace std;

const int N = 100001;

int sz[N];
vector <int> adj[N];

void getsz(int u) {
    sz[u] = 1;
    for (int i = 0; i < adj[u].)
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif // ONLINE_JUDGE

    return 0;
}
