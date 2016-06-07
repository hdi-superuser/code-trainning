#include <iostream>

using namespace std;

int main() {
    int T, N, K, P, cnt = 0;
    cin >> T;
    while (++cnt <= T) {
        cin >> N >> K >> P;
        cout << "Case " << cnt << ": ";
        int t = (K + P) % N;
        if (!t) t = N;
        cout << t << endl;
    }
    return 0;
}
