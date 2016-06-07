#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 100005
typedef long long LL;
using namespace std;
LL dp[5500];
int main()
{
    ios_base::sync_with_stdio(0);
    LL n, sum;
    while(cin >> n && n != 0) {
        memset(dp, 0, sizeof(dp));
        dp[0] = dp[1] = 1; dp[2] = 2; dp[3] = 4;
        sum = 0;
        for(int i = 4; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        for(int i = 0; n - i >= 0 && i <= 2 ; ++i) sum += dp[n - i];
        cout << (1LL << n) - sum<< endl;
    }
    return 0;
}
