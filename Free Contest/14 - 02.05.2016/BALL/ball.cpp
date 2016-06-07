#include <iostream>

using namespace std;

const int maxN = 2001;
const int BASE = 1000000007;

int N;
long long ans, C[maxN][maxN], dp[maxN];

int main() {
    for (int i = 0; i < maxN; i++) C[i][0] = C[i][i] = 1;
    for (int i = 1; i < maxN; i++)
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % BASE;
    dp[0] = 1;
    for (int i = 1; i < maxN; i++)
        dp[i] = dp[i-1] * (2*i-1)*2 % BASE;

    int Case;
    cin >> Case;
    while (Case--) {
        cin >> N;
        ans = 0;
		for (int i = 1; i <= N; i++)
            ans += (dp[i-1] * dp[N-i] % BASE * (2*N-1)*2 % BASE * C[2*N-2][2*i-2] % BASE);
		cout << ans % BASE << endl;

    }

    return 0;
}
