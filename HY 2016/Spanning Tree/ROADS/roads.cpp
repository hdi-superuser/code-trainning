#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int M = 200001;
const int N = 100001;

typedef pair <int, int> ii;
typedef pair < pair<int, int>, int > pii;

int n, m, k, p[N], p1[N], X = 0;
vector <pii> t[2], mst;

int getroot(int x)
{
    return p[x] == x ? x : p[x] = getroot(p[x]);
}

int getroot1(int x)
{
    return p1[x] == x ? x : p1[x] = getroot1(p1[x]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("roads.inp", "r", stdin);
    freopen("roads.out", "w", stdout);

    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        scanf("%d %d %d\n", &u, &v, &c);
        t[c].push_back(pii(ii(u, v), i));
    }

    for (int i = 1; i <= n; i++) p[i] = i;
    X = 0;
    for (int i = 0; i < t[0].size(); i++)
    {
        int r1 = getroot(t[0][i].x.x);
        int r2 = getroot(t[0][i].x.y);
        if (r1 == r2) continue;
        X++;
        p[r1] = r2;
    }

    int T1 = n - 1 - X;
    if (T1 > k)
    {
        cout << "-1";
        return 0;
    }
    X = 0;
    for (int i = 1; i <= n; i++) p1[i] = i;

    for (int i = 0; i < t[1].size(); i++)
    {
        int r1 = getroot(t[1][i].x.x);
        int r2 = getroot(t[1][i].x.y);
        if (r1 == r2) continue;
        X++;
        mst.push_back(t[1][i]);
        p[r1] = r2;
        r1 = getroot1(t[1][i].x.x);
        r2 = getroot1(t[1][i].x.y);
        p1[r1] = r2;
    }

    if (X < k)
    {
        for (int i = 0; i < t[1].size(); i++)
        {
            int r1 = getroot1(t[1][i].x.x);
            int r2 = getroot1(t[1][i].x.y);
            if (r1 == r2) continue;
            X++;
            mst.push_back(t[1][i]);
            r1 = getroot1(t[1][i].x.x);
            r2 = getroot1(t[1][i].x.y);
            p1[r1] = r2;
            if (X == k) break;
        }
    }

    if (X < k)
    {
        cout << "-1";
        return 0;
    }

    for (int i = 0; i < t[0].size(); i++)
    {
        int r1 = getroot1(t[0][i].x.x);
        int r2 = getroot1(t[0][i].x.y);
        if (r1 == r2) continue;
        X++;
        mst.push_back(t[0][i]);
        r1 = getroot1(t[0][i].x.x);
        r2 = getroot1(t[0][i].x.y);
        p1[r1] = r2;
        if (X == n-1) break;
    }

    for (int i = 0; i < mst.size(); i++) cout << mst[i].y << " ";

    return 0;
}
