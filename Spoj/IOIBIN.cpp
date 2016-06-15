#include<algorithm>
#include <cstdio>
#define FOR(i, a, b) for(int i=(a), _b=(b); i < _b; ++i)
#define FORE(i, a, b) for(int i=(a), _b=(b); i <= _b; ++i)
#define FORD(i, a, b) for(int i=(a), _b=(b); i >= _b; --i)
#define MP(a, b) make_pair(a, b)
using namespace std;
const int DBG = 0;
const int HOME = 0;
const int MAXN = 10010;
const int INF = 1000000001;

int n = 10000, p;
int root[MAXN];

int getroot(int u){
   if(u==root[u]) return u;
   return root[u] = getroot(root[u]);
}

int main(){
 
   FOR(i, 0, n) root[i] = i;
   scanf("%d", &p);
   int u, v, c;
   FOR(i, 0, p){
      scanf("%d %d %d", &u, &v, &c);
      u--; v--;
      if(c==1) root[getroot(u)] = getroot(v);
      else printf("%d\n", getroot(u)==getroot(v));
   }

   return 0;
}