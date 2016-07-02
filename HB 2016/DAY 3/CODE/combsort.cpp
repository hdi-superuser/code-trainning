#include <bits/stdc++.h>

using namespace std;

int n, a[10000001];

int main() {
    //freopen("in.txt", "r", stdin);
    int x;
    while (cin >> x) a[++n] = x;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}
