#include <bits/stdc++.h>

using namespace std;

int a[2002], h, n;
int f[2002][1024];

int change(int h, int k) {
    if (k > 9) return 0;
    return h << k;
}

int getbit(int k) {
    return (h >> k) & 1;
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) scanf("%d ", &a[i]);
    sort(a + 1, a + n + 1);
    memset(f, -1, sizeof f);
    f[1][1] = 1;    f[1][0] = 0;
    int select = 0, x = 0;
    for (int i = 2; i <= n; i++) f[i][1] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < 1024; j++)
            if (f[i][j] != -1) {
                h = change(j, (a[i+1] - a[i]));
                if (f[i+1][h & 1023] < f[i][j])
                    f[i+1][h & 1023] = f[i][j];
                if (getbit(1) + getbit(8) + getbit(9) == 0)
                    if (f[i+1][h & 1023 | 1] < f[i][j] + 1)
                        f[i+1][h & 1023 | 1] = f[i][j] + 1;
            }
    for (int i = 1; i < 1024; i++)
        if (getbit(1) + getbit(8) + getbit(9) == 0 || getbit(0) == 0)
            if (select < f[n][i]) select = f[n][i];
    printf("%d", n - select);
    return 0;
}

