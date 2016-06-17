#include <bits/stdc++.h>

using namespace std;

const int N = 20001;
int n, a[6][N], res[N];
map <int, int> pos[6];

bool comp(int x, int y) {
    int co = 0;
    for (int i = 1; i <= 5; i++) co += pos[i][x] < pos[i][y];
    return co >= 3;
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d\n", &n);
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d\n", &a[i][j]);
            pos[i][a[i][j]] = i;
        }
    for (int i = 1; i <= n; i++) res[i] = a[1][i];
    sort(res + 1, res + n + 1, comp);
    for (int i = 1; i <= n; i++) printf("%d\n", res[i]);
    return 0;
}
