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

int n, s, a[505], sum;

int main() {
    scanf("%d%d", &n,&s);
    sum = n*(n+1)/2;
    FOD(i,n,1) 
        if (sum-2*i >= s) 
            a[i] = 1, sum -= 2*i;
    if (sum == s) {
        if (a[1]) {
            FOR(i,4,n) {
                if (a[1] == 0) break;
                if (a[i])
                    FOR(j,2,i/2)
                        if (a[j] == 0 && a[i+1-j] == 0) {
                            a[j] = a[i+1-j] = 1;
                            a[1] = a[i] = 0;
                            break;
                        }
            }
            if (a[1]) {
                puts("Impossible");
                return 0;
            }
        }
        printf("1");
        FOR(i,2,n)
            printf("%c%d", (a[i] == 1) ? '-' : '+', i);
    }
    else puts("Impossible");
    return 0;
}