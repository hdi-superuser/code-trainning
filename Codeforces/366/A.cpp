#include <bits/stdc++.h>

#define task "main"

using namespace std;

const int N = 300001;

set<int> app[N];
queue< pair<int, int> > Q;

int n, q;
bool mark[N];

int readint() {
	int c = getchar(), ret = 0;
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		ret = ret*10+(c^48);
		c = getchar();
	}
	return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif // ONLINE_JUDGE

    n = readint();  q = readint();
    int cnt = 0, ans = 0;
    while (q--) {
        int x, y;
        x = readint();  y = readint();
        if (x == 1) {
            Q.push(make_pair(++cnt, y));
            app[y].insert(cnt);
            ans++;
        }
        if (x == 2) {
            for (set<int>::iterator it = app[y].begin(); it != app[y].end(); it++) {
                mark[*it] = true;
            }
            ans -= app[y].size();
            app[y].clear();
        }
        if (x == 3) {
            while (!Q.empty() && Q.front().first <= y) {
                int idx = Q.front().first;
                int nts = Q.front().second;
                Q.pop();
                if (!mark[idx]) {
                    mark[idx] = true;
                    app[nts].erase(idx);
                    ans--;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
