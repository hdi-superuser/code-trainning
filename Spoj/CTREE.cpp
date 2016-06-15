using namespace std;
#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cassert>
#define FOR(i, a, b) for(int i=(a), _b=(b); i < _b; ++i)
#define FORE(i, a, b) for(int i=(a), _b=(b); i <= _b; ++i)
#define FORD(i, a, b) for(int i=(a), _b=(b); i >= _b; --i)
#define MP make_pair
#define PB push_back
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

const int DBG = 0;
const int HOME = 0;
const int MAXN = 10+10000;
const int INF = 1000000001;

int n;
int dad[MAXN], a[MAXN];
int f[MAXN][3];
VVI tree;

void DFS(int u){
   int v;
   f[u][0] = 1; f[u][1] = 2; f[u][2] = 3;
   TR(tree[u], iv) if((v = *iv) != dad[u]){
      dad[v] = u; DFS(v);
      f[u][0] += min(f[v][1], f[v][2]);
      f[u][1] += min(f[v][2], f[v][0]);
      f[u][2] += min(f[v][0], f[v][1]);
   }
}

void trace(int u, int c){
   a[u] = c+1;
   int v, vc, res;
   TR(tree[u], iv) if((v = *iv) != dad[u]){
      res = INF;
      FOR(i, 0, 3) if(i!=c && f[v][i]<res) res = f[v][i], vc=i;
      trace(v, vc);
   }
}

int main(){
   if(HOME){
      freopen("spoj.inp", "r", stdin);
      freopen("spoj.out", "w", stdout);
   }

   scanf("%d", &n); tree.resize(n+1);
   FOR(i, 0, n-1){
      int u, v;
      scanf("%d %d", &u, &v); u--; v--;
      tree[u].PB(v); tree[v].PB(u);
   }

   DFS(0);
   int res=INF, c;
   FOR(i, 0, 3) if(f[0][i] < res) res = f[0][i], c = i;
   printf("%d\n", res);
   trace(0, c);
   FOR(i, 0, n) printf("%d\n", a[i]);

   return 0;
}
