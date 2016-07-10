#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 100001;
typedef pair<ll, int> li;

int n, a[N], s;
int f[N], pre[N], fr[N];

int main() {
    freopen("pthuong.inp", "r", stdin);
    freopen("pthuong.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s += a[i];

    f[1] = a[1];    f[2] = a[2];    f[3] = a[3];
    for (int i = 4; i <= n + 1; i++) {
	int temp = 2000000000;
        for (int j = i - 3; j < i; j++) temp = min(temp, f[j]);
	f[i] = temp + a[i];
    }

    cout << s - f[n + 1] << endl;
    int temp = f[n + 1];
    for (int i = n; i >= 1; i--)
        if (f[i] == temp)
            temp -= a[i],
            a[i] = -1;

    vector<int> ans;    ans.push_back(0);
    for (int i = 1; i <= n; i++)
        if (a[i] != -1) ans.push_back(i);

    for (int i = 1; i < ans.size(); i++)
        if (i % 10) cout << ans[i] << " ";
        else cout << ans[i] << endl;
}
