#include <iostream>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    int res = 1;
    while (k) {
        if (k & 1) res = (res * n) % m;
        n = (n*n) % m;  k /= 2;
    }
    cout << res;

    return 0;
}
