#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    long long N;
    cin >> T;
    while (T--) {
        cin >> N;
        N *= 2;
        long long m = (long long) sqrt(N);
        if (m*(m+1) <= N) cout << m << endl; else cout << m - 1 << endl;
    }
    return 0;
}
