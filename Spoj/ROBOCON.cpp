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
const int N = 505;
int n, k, a[N][N], InQueue[2][N][N], ans;
int dx[2][3] = {{1,0,1},{1,0,1}};
int dy[2][3] = {{0,1,1},{0,-1,-1}};
queue<ii> st[2];

int main() {
    cin >> n >> k;
    while (k--) {
        int i, j; scanf("%d%d", &i,&j);
        a[i][j] = 1;
    }

    st[0].push({1,1}); InQueue[0][1][1] = 1;
    st[1].push({1,n}); InQueue[1][1][n] = 1;

    int robot = 0, ans = 0;
    for (;;) {
        if (robot == 1) ans++;
        int sz = st[robot].size();
        while (sz--) {
            int i = st[robot].front().X, j = st[robot].front().Y; st[robot].pop();
            InQueue[robot][i][j] = 0;
            FOR(k,0,2) {
                int u = i + dx[robot][k], v = j + dy[robot][k];
                if (u < 1 || u > n || v < 1 || v > n || a[u][v]) continue;
                if (robot == 1 && InQueue[0][u][v]) {
                    printf("%d\n", ans);
                    return 0;
                }
                st[robot].push({u,v});
            }
        }
        sz = st[robot].size();
        while (sz--) {
            ii f = st[robot].front(); st[robot].pop();
            if (! InQueue[robot][f.X][f.Y])
                st[robot].push(f), InQueue[robot][f.X][f.Y] = 1;
        }
        robot ^= 1;
    }

    return 0;
}
