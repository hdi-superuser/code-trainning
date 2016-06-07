#include <iostream>
#include <cstdio>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

ii extended_gcd(ll a, ll b) {
    ii qr, st;
    if (!b) return ii(1, 0);
    else {
        qr = ii(a/b, a%b);
        st = extended_gcd(b, qr.y);
        return ii(st.y, st.x-qr.x*st.y);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ll a, m;
    cin >> a >> m;
    /* formula:
            a^-1 mod m = y;
            m*x + a*y = 1;
     */

    ll g = __gcd(a, m);
    ii st = extended_gcd(a, m);
    cout << 1/g*st.y << endl;

    return 0;
}
