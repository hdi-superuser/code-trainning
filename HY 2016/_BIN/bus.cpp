//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x,y) if (x > y) x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "bus"
#define maxn 100000
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define ll long long
#define pii pair<ll, ll>

using namespace std;


//ax + t1 = by + t2
long long a, b, l, r, c, t1, t2;

void tinh()
{
    c = t2-t1;
    long long pa = 1, qa = 0;
    long long pb = 0, qb = 1, pr, qr;
    long long m = a, n = b;
    while (n)
    {
        long long t = m/n;
        r = m - t*n;
        m = n;
        n = r;
        pr = pa - t*pb;
        qr = qa - t*qb;
        pa = pb; qa = qb; pb = pr; qb = qr;
    }
    //cout << pa << " " << qa << endl;
    if (c % m) {
        cout << -1 << endl; return;
    }
    pa *= c/m;
    qa *= c/m;
    long long diffa = b/m, diffb = a/m;
    qa += (pa/diffa)*diffb;
    pa %= diffa;
    if (pa < 0) {pa += diffa; qa -= diffb;}
    if (qa > 0) {
        int mul = (qa-1)/diffb + 1;
        qa -= diffb * mul;
        pa += diffa * mul;
    }
    cout << pa*a + t1 << endl;
}

void trau()
{
    if ((t2 - t1) % __gcd(a,b))
    {
        cout << -1 << endl;
        return;
    }
    long long x = t1;
    while (1)
    {
        if (x >=t2 && (x-t2) % b == 0)
        {
            cout << x << endl;
            return;
        }
        x += a;
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    int T;
    cin >> T;
    while( cin >> a >> b >> t1 >> t2) tinh();
    return 0;
}
