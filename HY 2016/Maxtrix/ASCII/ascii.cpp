#include <bits/stdc++.h>

using namespace std;

int m, n;
char a[1003];

int main() {
    freopen("ascii.inp", "r", stdin);

	cin >> m >> n;
    int ans = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%s", a + 1);
		int b = 0;
		for (int j = 1; j <= n; j++)
			if (a[j]=='.') ans += b;
			else b^=2, ans++;
	}
	cout << ans/2 << endl;
}
