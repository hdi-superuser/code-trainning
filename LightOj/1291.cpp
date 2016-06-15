#include <bits/stdc++.h>

using namespace std;

#define MAX 10005

struct info {
    int v, isBridge, idinu;
    info() {}
    info( int vv, int ii, int idd ) {
        v = vv, isBridge = ii, idinu = idd;
    }
};

int n, m, vis[MAX], assignedVal, K, cases, caseno;
vector <info> adj[MAX];
set <int> adjComp[MAX];

int bridge( int u, int parent ) {
    vis[u] = ++assignedVal;
    int mn = vis[u];
    for( int i = 0; i < adj[u].size(); i++ ) if( adj[u][i].v != parent ) {
        int v = adj[u][i].v;
        if( !vis[v] ) {
            int k = bridge( v, u );
            if( k > vis[u] ) {
                adj[u][i].isBridge = 1;
                adj[v][ adj[u][i].idinu ].isBridge = 1;
                //printf("%d %d\n", u, v);
            }
        }
        mn = min( mn, vis[v] );
    }
    return vis[u] = mn;
}
void processBridge() {
    assignedVal = 0;
    memset( vis, 0, sizeof( vis ) );
    for( int i = 0; i < n; i++ ) if( !vis[i] ) bridge( i, -1 );
}

void dfs( int u, int comp ) {
    if( vis[u] >= 0 ) return;
    vis[u] = comp;
    for( int i = 0; i < adj[u].size(); i++ ) if( !adj[u][i].isBridge ) {
        int v = adj[u][i].v;
        dfs(v, comp);
    }
}

int findComponents() {
    K = 0;
    memset( vis, -1, sizeof(vis) );
    for( int i = 0; i < n; i++ ) if( vis[i] == -1 ) {
        dfs(i, K);
        K++;
    }
    for( int i = 0; i < n; i++ ) for( int j = 0; j < adj[i].size(); j++ ) if( adj[i][j].isBridge ) {
        int u = i, v = adj[i][j].v;
        adjComp[ vis[u] ].insert( vis[v] );
        adjComp[ vis[v] ].insert( vis[u] );
    }

    if( K == 1 ) return 0; // only one biconnected component

    // otherwise a component must be found who has degree 1

    int cnt = 0;
    for( int u = 0; u < K; u++ ) if( adjComp[u].size() == 1 ) cnt++;
    return ( cnt + 1 ) / 2;
}

int main() {
    freopen( "in.txt", "r", stdin );

    double cl = clock();

    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d", &n, &m);
        assert( n >= 3 );
        for( int i = 0; i < m; i++ ) {
            int u, v;
            scanf("%d %d", &u, &v);
            assert( u < n && v < n && u != v );
            adj[u].push_back( info( v, 0, adj[v].size() ) );
            adj[v].push_back( info( u, 0, adj[u].size() - 1 ) );
        }
        processBridge();
        int res = findComponents();

        printf("Case %d: %d\n", ++caseno, res);

        for( int i = 0; i < n; i++ ) {
            adj[i].clear();
            adjComp[i].clear();
        }
    }
    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);
    return 0;
}

