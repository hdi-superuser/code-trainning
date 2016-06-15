#include<algorithm>
#include<vector>
#include<stdio.h>
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
const int MAXN = 100010;
const int INF = 1000000001;
const int BASE = 14062008;
 
int n, k;
int s[MAXN], f[MAXN];
 
int main(){
   if(HOME){
      freopen("VSTEPS.inp", "r", stdin);
      freopen("VSTEPS.out", "w", stdout);
   }
 
   scanf("%d %d", &n, &k);
   FORE(i, 1, n) s[i] = 1;
 
   FOR(i, 0, k){
      int x;
      scanf("%d", &x); s[x] = 0;
   }
 
   f[0] = 0; f[1] = 1;
   FORE(i, 2, n) f[i] = s[i] ? (f[i-1]+f[i-2])%BASE : 0;
 
   printf("%d\n", f[n]);
 
   return 0;
}

