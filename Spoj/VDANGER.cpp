#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 101;

int N, M, C[maxN][maxN], A[maxN*maxN];

int main() {
        //freopen("spoj.inp", "r", stdin);
        //freopen("spoj.out", "w", stdout);

        cin >> N >> M;
        for (int i = 1; i <= M; i++) cin >> A[i];

        for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                        cin >> C[i][j];

        for (int k = 1; k <= N; k++)
                for (int i = 1; i <= N; i++)
                        for (int j = 1; j <= N; j++)
                                if (C[i][j] > C[i][k] + C[k][j])
                                        C[i][j] = C[i][k] + C[k][j];

        int ans = 0;
        for (int i = 2; i <= M; i++)
                ans += C[A[i-1]][A[i]];

        cout << ans;
}
