#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int cnt = 0, T, N;
    cin >> T;
    while (++cnt <= T) {
        int a, ans;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a;
            if (i == (N + 1) / 2) ans = a;
        }
        cout << "Case " << cnt << ": " << ans << endl;
    }
    return 0;
}
