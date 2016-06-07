#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int N, K, A[33], S[2][18], sum[1 << 18], ans = 0;

int main() {
	freopen("in.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N/2; i++) S[0][++S[0][0]] = A[i];
	for (int i = N/2+1; i <= N; i++) S[1][++S[1][0]] = A[i]; 
	for (int i = 0; i <= (1 << S[1][0]) - 1; i++) 
		for (int j = S[1][0]; j; j--) {
			sum[i] += (i >> (j-1)) & 1 ? S[1][j] : 0;
			if (sum[i] == K) ans++;
		}
	sort(sum, sum + (1 << S[1][0]));
	for (int i = 0; i <= (1 << S[0][0]) - 1; i++) {
		int s = 0;
		for (int j = S[0][0]; j; j--) {
			s += (i >> (j-1)) & 1 ? S[0][j] : 0;
			if (s == K) ans++;
		}
		if (s >= K) continue;
		int x = lower_bound(sum + 1, sum + (1 << S[1][0]), K - s) - sum;
		int y = upper_bound(sum + 1, sum + (1 << S[1][0]), K - s) - sum;
		ans += x == y ? 0 : y - x;
	}
	cout << ans << endl;
	return 0;
}
