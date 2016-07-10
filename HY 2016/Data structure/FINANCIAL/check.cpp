#include <bits/stdc++.h>

using namespace std;

int a[100001];

int main() {
    int k;
    freopen("fanancial.inp", "r", stdin);
    cin >> k; cin >> k;
    freopen("fanancial.out", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (abs(a[i] - a[i-1]) < k) cout << "WA " << ": " << i << endl;
    }
}
