#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <set>

#define ll long long 
#define x first
#define y second

using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int maxN = 511;
const int maxK = 30011;
const int inf  = 1000000000;

int N, K, d[maxK][maxN], res;
vector <iii> adj[maxN];

int main(int argc, char **argv) {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif ONLINE_JUDGE 
    
    int T;
    cin >> T;
    while (T--) {
        // enter data
        int R;
        cin >> K >> N >> R;
        for (int u = 1; u <= N; u++) adj[u] = vector<iii>();
        while (R--) {
            int u, v, l, t;
            cin >> u >> v >> l >> t;
            adj[u].push_back(iii(v, ii(l, t)));
        }
        
        // dijkstra
        res = inf;
        priority_queue<iii, vector<iii>, greater<iii> > heap;
        for (int t = 0; t <= K; t++) 
            for (int u = 1; u <= N; u++) 
                d[t][u] = inf;
        d[0][1] = 0;
        heap.push(iii(0, ii(0, 1)));
        while (!heap.empty()) {
            int dtu = heap.top().x, t = heap.top().y.x, u = heap.top().y.y;
            heap.pop();
            if (dtu != d[t][u]) continue;
            if (u == N) {
                res = min(res, dtu);
                goto print;
            }
            for (vector<iii>::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
                int v = it->x, L = it->y.x, T = it->y.y;
                if (t + T <= K && d[t+T][v] > dtu + L) 
                    d[t+T][v] = dtu + L, 
                    heap.push(iii(d[t+T][v], ii(t+T, v)));
            }
        }
        
        // print result
        print: if (res == inf) res = -1;
        cout << res << endl;
    }
    return 0;
}
