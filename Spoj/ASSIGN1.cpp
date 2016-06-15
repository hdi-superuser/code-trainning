#include<algorithm>
#include<cstdio>
#include<cstring>
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

int m, lim, res, ret;
int a[MAXN][MAXN];
int mx[MAXN], my[MAXN], q[MAXN], tr[MAXN], x[MAXN];

bool aug(int u){
   int front = 0, back = 0;
   memset(x, 0, sizeof x);
   q[back++] = u;
   while(front<back){
      u = q[front++];
      FORE(v, 1, m) if(a[u][v] <= lim && !x[v]){
         tr[v] = u;
         if(!my[v]){ ret = v; return true; }
         q[back++] = my[v]; x[v] = 1;
      }
   }
   return false;
}

void enlarge(int s){
   int u, v = ret, t;
   while(!mx[s]){
      u = tr[v];
      t = mx[u];
      my[v] = u;
      mx[u] = v;
      v = t;
   }
}

int main(){
   if(HOME){
      freopen("ASSIGN1.inp", "r", stdin);
      freopen("ASSIGN1.out", "w", stdout);
   }

   scanf("%d", &m);

   FORE(i, 1, m) FORE(j, 1, m) scanf("%d", &a[i][j]);

   int l = 1, r = 32767;
   while(l < r){
      lim = (l+r)/2;
      res = 0;
      memset(mx, 0, sizeof mx);
      memset(my, 0, sizeof my);
      FORE(i, 1, m)
         if(aug(i)){ res++; enlarge(i); }
         else break;
      if(res==m) r = lim; else  l = lim+1;
   }

   printf("%d\n", l);
   if(DBG){
      lim = l;
      memset(mx, 0, sizeof mx);
      memset(my, 0, sizeof my);
      FORE(i, 1, m)
         if(aug(i)){ res++; enlarge(i); }
         else break;
      FORE(i, 1, m) printf("%d %d\n", i, mx[i]);
   }

   return 0;
}