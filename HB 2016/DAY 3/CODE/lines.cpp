#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;
const int N = 201;

set<ii> st;
ii a[N];

int main() {
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d\n", &a[i].x, &a[i].y);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            int u = a[j].x - a[i].x, v = a[j].y - a[i].y;
            int k = __gcd(u, v);
            st.insert(ii(u/k, v/k));
        }
    cout << st.size();
    return 0;
}
