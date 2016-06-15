#include<cstdio>
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
typedef long long LL;

const int DBG = 0;
const int HOME = 1;
const int MAXN = 10010;
const int INF = 1000000001;
const int NS = 55;

int n;
int state[NS] = {  0,    1,    2,    4,    5,    8,    9,   10,   16,   17,   18,
                  20,   21,   32,   33,   34,   36,   37,   40,   41,   42,   64,
                  65,   66,   68,   69,   72,   73,   74,   80,   81,   82,   84,
                  85,  128,  129,  130,  132,  133,  136,  137,  138,  144,  145,
                 146,  148,  149,  160,  161,  162,  164,  165,  168,  169,  170
                };

VVI rel(NS);
int a[8][MAXN];
LL f[MAXN][NS];

inline int sum(int col, int s){
   int t = 0;
   FOR(i, 0, 8){
      if(s&1) t += a[i][col];
      s >>= 1;
   }
   return t;
}

int main(){
      //freopen("debug.txt", "r", stdin);
      //freopen("out.txt", "w", stdout);

   FOR(i, 0, NS){
      FOR(j, i, NS) if(!(state[i] & state[j])){
         rel[i].PB(j); rel[j].PB(i);
      }
   }

   LL res = LL(-INF);

   if(DBG) printf("%I64d\n", res);

   scanf("%d", &n);
   FOR(i, 0, 8) FOR(j, 0, n){
      scanf("%d", &a[i][j]);
      res = max(res, LL(a[i][j]));
   }

   if(DBG) printf("%I64d\n", res);

   if(res < 0ll){
      if(HOME) printf("%I64d\n", res);
      else printf("%lld\n", res);
      return 0;
   }

   FOR(is, 0, NS) f[0][is] = LL(sum(0, state[is]));

   FOR(col, 1, n) FOR(is, 0, NS){
      LL hi = 0ll;
      TR(rel[is], it) hi = max(hi, f[col-1][*it]);
      f[col][is] = hi+LL(sum(col, state[is]));
   }

   FOR(s, 0, NS) res = max(res, f[n-1][s]);

   printf("%lld\n", res);

   return 0;
}
