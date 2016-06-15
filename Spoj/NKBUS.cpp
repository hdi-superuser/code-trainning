#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

#define maxN 200001

using namespace std;

long n, m, k, t, f[maxN], a[maxN], p, x, res;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("BUS.DAT", "r", stdin);
        freopen("BUS.OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    scanf("%li%li",&n,&m);
    f[1] = 0;
    p = 0;
    for (long i=1;i<=n;i++) {
        scanf("%li%li",&t,&k);
        f[i+1] = f[i] + t;
        for (long j = p + 1; j <= p + k; j++) {
            scanf("%li",&x);
            a[j] = max(0*1L, x - f[i]);
        }
        p += k;
    }
    sort(a+1,a+p+1);
    res = f[n+1]+a[m];
    printf("%li",res);
    return 0;
}
