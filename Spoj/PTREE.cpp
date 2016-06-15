#include<algorithm>
#include<vector>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i < _b; ++i)
#define FORE(i, a, b) for(int i=(a), _b=(b); i <= _b; ++i)
#define FORD(i, a, b) for(int i=(a), _b=(b); i >= _b; --i)
#define PB(a) push_back(a)
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> II;
typedef pair<int, II> III;
typedef vector<II> VII;
typedef vector<VII> VVII;
 
const int DBG = 0;
const int HOME = 0;
const int MAXN = 10+200;
const int INF = 1000000001;
 
int n, p;
int c[MAXN];
int g[MAXN][MAXN], dp[MAXN][MAXN], tr[MAXN][MAXN];
 
void dfs(int u){
   dp[u][1] = c[u];
   FOR(v, 0, n) if(g[u][v]){
      g[v][u] = 0; dfs(v);
      FORD(i, p, 1) FORE(j, 1, i-1)
         if(dp[u][i] < dp[v][j]+dp[u][i-j]){
            dp[u][i] = dp[v][j]+dp[u][i-j];
            tr[v][i] = j; // vao cay con goc v de dat dc i dinh (cho u)
                          // cay con goc v can dat j dinh
         }
   }
}
 
void trace(int u, int p){
   FORD(v, n-1, 0) if(g[u][v] && tr[v][p]){
      trace(v, tr[v][p]);
      p -= tr[v][p];
   }
   printf("%d ", u+1);
}
 
int main(){
   if(HOME){
      freopen("PTREE.inp", "r", stdin);
      freopen("PTREE.out", "w", stdout);
   }
 
   scanf("%d %d", &n, &p);
   FOR(i, 0, n) scanf("%d", &c[i]);
   FOR(i, 0, n-1){
      int u, v;
      scanf("%d %d", &u, &v); u--; v--;
      g[u][v] = g[v][u] = 1;
   }
 
   FOR(i, 0, n) FORE(j, 1, p) dp[i][j] = -INF;
   dfs(0);
   int u = 0;
   FOR(i, 1, n) if(dp[i][p] > dp[u][p]) u = i;
   if(DBG) printf("%d\n", dp[u][p]);
   trace(u, p);
 
   return 0;
}