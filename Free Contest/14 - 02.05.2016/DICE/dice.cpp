#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxM = 21;
const int maxN = 51;

int M, N;
long long K, f[maxM][maxN];
vector <int> ans;

void dp(int pos, int low) {
    if (pos > M) return;
    long long cur = 0;
    for (int i = low; i <= N; i++) {
        cur += f[pos][i];
        if (cur > K) {
            cur -= f[pos][i];   K -= cur;
            ans.push_back(i);
            dp(pos+1, i);
            return;
        }
    }
    K -= cur;
    ans.push_back(N);
    dp(pos+1, N);
}

int main() {
    cin >> M >> N >> K;
    K--;

    for (int i = 1; i <= N; i++) f[M][i] = 1;
    for (int i = M-1; i; i--)
        for (int j = 1; j <= N; j++)
            for (int k = j; k <= N; k++)
                f[i][j] += f[i+1][k];

    dp(1, 1);
    for (int i = 0; i < ans.size(); i++) {
	cout << ans[i];
    	if (i == ans.size() - 1) cout << endl; else cout << " ";
    }

    return 0;
}
