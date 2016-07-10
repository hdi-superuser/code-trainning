#include <bits/stdc++.h>

using namespace std;

long long a[100001];

int main() {
    //freopen("in.txt", "r", stdin);
    queue <long long> q;
    int n;	long long k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        q.push(a);
    }

    while (k--) {
        long long a = q.front();
        q.pop();
        if (a <= 1) continue;
        q.push(a - 1);
    }

    if (q.empty()) { cout << "-1"; return 0; }

    while (!q.empty()) {
        long long a = q.front();
        q.pop();
        cout << a << " ";
    }
}

