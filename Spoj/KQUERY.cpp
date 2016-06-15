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

struct data {
    int i, j, k, type, id;
};
 
const int   N = 500000;
int         n, q, res[N], bit[N];
data        a[N];
 
bool cmp(data u, data v)
{
    return (u.k > v.k or (u.k == v.k and u.type > v.type));
}
 
void update(int x)
{
    for (x;x<=n;x+=x&(-x)) bit[x]++;
}
 
int get(int x)
{
    int ans = 0;
    for (x;x>0;x-=x&(-x)) ans += bit[x];
    return ans;
}
 
int main() {
     scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i].k);
        a[i].i = a[i].j = i;
        a[i].type = -1;
    }
    scanf("%d", &q);
    for (int i=1;i<=q;i++) {
        scanf("%d%d%d", &a[i+n].i, &a[i+n].j, &a[i+n].k);
        a[i+n].id = i;
    }
 
    sort(a+1, a+n+q+1, cmp);
 
    for (int i=1;i<=n+q;i++)
        if (a[i].type == -1) update(a[i].i);
        else res[a[i].id] = get(a[i].j) - get(a[i].i-1);
 
    for (int i=1;i<=q;i++) printf("%d\n", res[i]);
 
    return 0;
}
 
