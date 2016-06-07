#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int a[100001], n, h, k, ans = 0;
    cin >> n >> h >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int i = 1, remain = 0;
    while (i <= n) {
        int j = i + 1, s = a[i];
        while (j <= n && s + a[j] <= k) s += a[j++];
        ans++;  i = j;
        int nr = s > k ? s - k : 0;
        int nt = k > s ? k - s : 0;
        if (nt >= remain) remain = 0;
        if (remain + nr > k) ans++, remain = nr;
        else remain += nr;
    }
    ans += remain / k;
    if (remain % k) ans++;
    cout << ans;
    return 0;
}
