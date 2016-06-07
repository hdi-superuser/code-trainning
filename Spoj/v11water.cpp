#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1000001;

int a[N], n, L[N], R[N];

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], L[i] = max(L[i-1], a[i-1]);
	for (int i = n; i >= 1; i--) R[i] = max(R[i+1], a[i+1]);
	long long ans = 0;
	for (int i = 1; i <= n; i++) 
		ans += min(L[i], R[i]) > a[i] ? min(L[i], R[i]) - a[i] : 0;
	cout << ans << endl;
}
