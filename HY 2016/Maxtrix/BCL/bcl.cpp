#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> pipi;

const int N = 2001;

pipi make_pipi(int x, int y, int u, int v) {
    return pipi(ii(x, y), ii(u, v));
}

int n;
char a[N], res[N];
bool fr[N][N];

int main() {
    //freopen("in.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res[i]= 'z';
    }

    queue< pipi > q;
    q.push(make_pipi(1, n, '\0', 0));

    while (q.size()) {
        pipi top = q.front();   q.pop();

        int x = top.X.X, y = top.X.Y;
        int u = top.Y.X, v = top.Y.Y;

        if (res[v] != u || x > y) continue;
        if (fr[x][y]++) continue;

        res[v+1] = min(res[v+1], min(a[x], a[y]));
        q.push(make_pipi(x+1, y, a[x], v+1));
        q.push(make_pipi(x, y-1, a[y], v+1));
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i];
        if (i % 80 == 0) cout << endl;
    }
}
