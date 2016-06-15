#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 500001;

int N, K, nidx, nA;
int A[maxN], idx[maxN], f[maxN];
long long bit[maxN];

void update(int x) {
	for (x; x <= nA; x += x & (-x)) bit[x]++;
}

long long get(int x) {
		long long sum = 0;
		for (x; x > 0; x -= x & (-x)) sum += bit[x];
		return sum;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif // ONLINE_JUDGE

		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			f[i] = f[i-1] + (A[i] >= K);
			idx[++nidx] = 2*f[i] - i - 1;
			idx[++nidx] = 2*f[i-1] - i;
		}

		sort(idx + 1, idx + nidx + 1);
		idx[++nidx] = N;
		for (int i = 1; i < nidx; i++)
			if (idx[i] <= idx[i+1]) A[++nA] = idx[i];

		long long ans = 0;
		for (int j = 1; j <= N; j++) {
			int x = lower_bound(A + 1, A + nA + 1, 2*f[j-1]-j) - A;
			update(x);
			x = lower_bound(A + 1, A + nA + 1, 2*f[j]-j-1) - A;
			ans += get(x);
		}

		cout << ans << endl;

		return 0;
}