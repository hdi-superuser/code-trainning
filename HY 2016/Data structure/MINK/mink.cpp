#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
int n, k, a[N];

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("mink.inp", "r", stdin);
    freopen("mink.out", "w", stdout);

    int T;  cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        deque <int> q;

        for (int i = 0; i < k; i++) {
            while (!q.empty() && a[q.back()] > a[i]) q.pop_back();
            q.push_back(i);
        }

        cout << a[q.front()] << " ";
        for (int i = k; i < n; i++) {
            while (!q.empty() && q.front() <= i - k) q.pop_front();
            while (!q.empty() && a[q.back()] > a[i]) q.pop_back();
            q.push_back(i);
            cout << a[q.front()] << " ";
        }
        cout << endl;
    }

    return 0;
}
