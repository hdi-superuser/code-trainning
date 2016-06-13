#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int a[101], s = 0;
    for (int i = 1; i <= 5; i++) {
        int x;
        scanf("%d ", &x);
        a[x]++;
        s += x;
    }
    int ans = 501;
    for (int i = 100; i >= 1; i--)
        if (a[i] >= 2) ans = min(ans, s - i*2);
    printf("%d\n", ans);
    return 0;
}
