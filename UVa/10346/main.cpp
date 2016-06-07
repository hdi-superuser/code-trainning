#include <iostream>
#include <cstdio>

using namespace std;

long long get(long long x, long long k) {
    if (x >= k) return x/k + get(x/k + x%k, k);
    else return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    long long n, k;
    while (cin >> n >> k) cout << n + get(n, k) << endl;

    return 0;
}
