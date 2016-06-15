#include <bits/stdc++.h>

using namespace std; 

typedef pair<int,int> ii;
typedef long long ll; 
typedef long double ld;
typedef unsigned long long llu;

#define X  first
#define Y  second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)
#define EL printf("\n")
#define debug 1

const double pi = acos(-1.0);



const int N = 3e5+5;
int n, c, a[N], q, l, r;
vector<int> f[N];

int main() {
    srand(time(NULL));
    cin >> n >> c;
    FOR(i,1,n) scanf("%d", &a[i]), f[a[i]].pb(i);

    cin >> q;
    while (q--) {
        scanf("%d%d", &l,&r);
        int ok = 0;
        FOR(i,1,25) {
            c = a[l+rand()%(r-l+1)];
            int L = lower_bound(f[c].begin(),f[c].end(),l)-f[c].begin();
            int R = upper_bound(f[c].begin(),f[c].end(),r)-f[c].begin();
            if (R-L > (r-l+1)/2) {ok = 1; break;}
        }
        if (ok) printf("yes %d\n", c); else puts("no");
    }

    return 0;
}