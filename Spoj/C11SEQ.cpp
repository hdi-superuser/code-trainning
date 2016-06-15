#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef int64_t   ll;
typedef pair<int,int> ii;

#define EL printf("\n")
#define pb push_back
#define mp make_pair
#define X  first
#define Y  second

const int   N = 1000000;
int         n, l, r;
ll          f[N], b[N], a[N], t[N], res;

void update(int x)
{
    while (x > 0) {
        t[x]++;
        x -= x&(-x);
    }
}

ll get(int x)
{
    ll ans = 0;
    while (x <= a[0]) {
        ans += t[x];
        x += x&(-x);
    }
    return ans;
}

int main()
{
    //freopen("INP.INP","r",stdin);
    //freopen("OUT.OUT","w",stdout);

    scanf("%d%d%d", &n,&l,&r);
    for (int i=0;i<=n;i++) {
        if (i > 0) {
            int x;
            scanf("%d", &x);
            f[i] = f[i-1]+(ll)x;
        }
        b[++b[0]] = f[i];
        b[++b[0]] = f[i]-(ll)r;
        b[++b[0]] = f[i]-(ll)l+1ll;
    }

    sort(b+1,b+b[0]+1);
    for (int i=1;i<=b[0];i++)
        if (i == 1 or b[i] != b[i-1]) a[++a[0]] = b[i];

    for (int i=1;i<=n;i++) {
        int x;
        x = lower_bound(a+1, a+a[0]+1, f[i-1]) - a;
        update(x);
        x = lower_bound(a+1, a+a[0]+1, f[i]-r) - a;
        res += get(x);
        x = lower_bound(a+1, a+a[0]+1, f[i]-l+1) - a;
        res -= get(x);
    }

    printf("%lld", res);

    return 0;
}

