#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, a, f[101] = {0};
    scanf("%d %d\n", &n, &a);
    for (int i = 1; i <= n; i++) scanf("%d ", &f[i]);
    int ans = f[a];
    for (int i = 1; i <= min(a - 1, n - a); i++)
        ans = max(ans, f[i-a] + f[a] + f[i+a]);
    printf("%d\n", ans);
    return 0;
}
