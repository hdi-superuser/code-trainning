#include<algorithm>
#include<vector>
#include<cstdio>

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
const int MAXN = 110;
const int INF = 1000000001;

int n, k;

int calc(int n){
	if((n+k)%2 || n<=k) return 1;
	int t;
	return calc(t=(n+k)/2)+calc(n-t);
}

int main(){
   if(HOME){
      freopen("spoj.inp", "r", stdin);
      freopen("spoj.out", "w", stdout);
   }

   scanf("%d %d", &n, &k);
   printf("%d\n", calc(n));

	return 0;
}
