#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;

int n, k;
int sett[205];
vector <pii> edge;

int get(int u) {
    if (sett[u] == u) return u;
    return sett[u] = get(sett[u]);
}

int main() {
    ios_base::sync_with_stdio(NULL);    cin.tie();
    freopen("in.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (i < j) edge.push_back(pii(x, ii(i, j)));
        }
    for (int i = 1; i <= n; i++) sett[i] = i;
    sort(edge.begin(), edge.end());

    int last = 0, cnt = n, res = 0;
    for (int i = 0; i < edge.size(); i++)
        if (i == edge.size()-1 || edge[i].x != edge[i+1].x) {
            while (edge[last].x < edge[i].x) {
                int x = get(edge[last].y.x), y = get(edge[last].y.y);
                if (x != y) {
                    cnt--;
                    sett[x] = y;
                }
                last++;
            }
            if (cnt >= k) res = edge[i].x; else break;
        }
    cout << res << endl;
    return 0;
}
