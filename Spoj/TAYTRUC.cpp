#include <iostream>
#include <cstdio>

using namespace std;

const int maxN = 10001;

int N, M, sum[maxN];
int dp[maxN];

int main() {
   //freopen("TAYTRUC.INP", "r", stdin);
   //freopen("TAYTRUC.OUT", "w", stdout);

   cin >> N >> M;
   for (int i = 1; i <= N; i++) cin >> sum[i], sum[i] += sum[i-1];

   for (int i = N; i >= 1; i--) {
      dp[i] = dp[i+1];
      for (int j =  1; j <= M; j++)
         if (i + 2*j <= N + 1) dp[i] = max(dp[i], sum[i+j-1] - sum[i-1] + dp[i+2*j]);
   }

   cout << dp[1] << endl;

   return 0;
}
