#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
const int MAX = 1001;

int backA[MAX], backB[MAX], fa[MAX], fb[MAX];
int f[MAX][MAX], M, N;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        fa[i] = backA[x];
        backA[x] = i;
    }
    for (int i = 1; i <= M; i++) {
        int x;
        cin >> x;
        fb[i] = backB[x];
        backB[x] = i;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (i - fa[i] == j - fb[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = min(i-fa[i], min(j-fb[j], f[i-1][j-1]+1));
    cout << f[N][M];

    return 0;
}
