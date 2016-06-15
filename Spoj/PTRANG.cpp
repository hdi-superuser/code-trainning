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
const int N = 6005;
int n, L, a[N], F[N];

int main() {
    cin >> n >> L;
    FOR(i,1,n) scanf("%d", &a[i]);

    F[1] = L-a[1];
    FOR(i,2,n) {
        F[i] = max(L-a[i], F[i-1]);
        int S = a[i];
        FOD(j,i-1,1) {
            S += a[j];
            if (S > L) break;
            F[i] = min(F[i], max(L-S, F[j-1]));
        }
    }

    printf("%d\n", F[n]);

    return 0;
}