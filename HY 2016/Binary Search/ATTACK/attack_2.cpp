//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "attack"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>


using namespace std;

typedef long long ll;

ll k;
int n, a[maxn], b[maxn];

ll Calc(ll x)
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] <= x)
        {
            res += (x-a[i])/b[i] + 1;
            if (res > k) break;
        }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    long long l = 0, r = 6e18;
    while (l < r - 1)
    {
        ll mid = l + (r-l)/2;
        if (Calc(mid) > k) r = mid;
            else l = mid;
    }
    cout << r;
    return 0;
}

