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


int main() {
    int T; cin >> T;
    while (T--) {
        priority_queue<ll> st;
        int n; scanf("%d", &n);
        FOR(i,1,n) {
            int x; scanf("%d", &x);
            st.push(-x);
        }
        ll ans = 0ll;
        FOR(i,1,n-1) {
            ll x = st.top(); st.pop();
            ll y = st.top(); st.pop();
            ans += x+y; st.push(x+y);
        }
        printf("%lld\n", -ans);
    }

    return 0;
}