#include <cstdio>
#include <iostream>
#include <algorithm>

#define task "wealthy"

using namespace std;

const int maxN = 30001;

int M, N, D[maxN], H[maxN], dp[3][maxN];

inline bool cmp(int p, int q)  {
    if (H[p] != H[q]) return H[p] > H[q];
    return D[p] > D[q];
}

int main(int argc, char **argv) {
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> D[i] >> H[i], dp[0][i] = i;
    
    sort(dp[0] + 1, dp[0] + N + 1, cmp);
    for (int i = 1; i <= N; i++) {
        int x = dp[0][i];
        dp[1][x] = lower_bound(dp[2] + 1, dp[2] + M + 1, D[x]) - dp[2];
        dp[2][dp[1][x]] = D[x];     M = max(M, dp[1][x]);
    }
    
    for (int i = 1; i <= N; i++) cout << dp[1][i] << endl;
    
	return 0;
}
