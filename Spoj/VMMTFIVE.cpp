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

int d[6], c[6], a[6][6];

void output() {
    FOR(i,1,5) {
        FOR(j,1,5) printf("%d ", a[i][j]); EL;
    }
    exit(0);
}

void dq(int i, int j) {
    if (i == 6) {
        if (c[5] == 0) output();
        return ;
    }
    int l = max(1, max(d[i]-25*(5-j), c[j]-25*(5-i)));
    int r = min(25, min(d[i]-5+j, c[j]-5+i));
    if (l > 25 || r < 1 || l > r) return ;
    if (j == 5) l = r = d[i];
    FOR(x,l,r) {
        a[i][j] = x;
        d[i] -= x;
        c[j] -= x;
        if (j < 5) dq(i, j+1); else dq(i+1, 1);
        d[i] += x;
        c[j] += x;
        a[i][j] = 0;
    }
}

int main() {
    FOR(i,1,5) scanf("%d", &d[i]);
    FOR(i,1,5) scanf("%d", &c[i]);
    dq(1,1);

    return 0;
}