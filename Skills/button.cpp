#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int get(ll k) {
    if (k == 4) return 3;
    ll len = trunc(sqrt(k));
    for (int i = 3; i <= len; i++)
        if (k % i == 0) return i - 1;
    return k % 2 == 0 ? k / 2 - 1 : k - 1;
}

int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d\n", &T);
    while (T--) {
        int K;
        scanf("%d\n", &K);
        printf("%d\n", get(K));
    }
    return 0;
}
