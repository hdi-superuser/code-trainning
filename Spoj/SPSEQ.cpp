#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 100001;
const int inf  = 2000000001;

int N, A[maxN], s[maxN], f1[maxN], f2[maxN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("SEQUD.INP", "r", stdin);
		freopen("SEQUD.OUT", "w", stdout);
	#endif //ONLINE_JUDGE
	
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
		
	int k = 1;		
	s[1] = A[1];
	f1[1] = 1;
	
	for (int i = 2; i <= N; i++) {
		int j = k;
		while (A[i] <= s[j]) j--;
		if (j == k) s[++k] = inf;
		s[j+1] = min(A[i], s[j+1]);
		f1[i] = k;	
	}

	k = 1;
	s[1] = A[N];
	f2[N] = 1;
	for (int i = N-1; i >= 1; i--) {
		int j = k;
		while (A[i] <= s[j]) j--;
		if (j == k) s[++k] = inf;
		s[j+1] = min(A[i], s[j+1]);
		f2[i] = k;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) ans = max(ans, min(f1[i], f2[i])*2-1);
	cout << ans;
	
	return 0;
}
