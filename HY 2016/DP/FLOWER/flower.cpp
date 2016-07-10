#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int tr[N][N], a[N][N], s[N];
int n, m;

void trace(int i, int j) {
    int prev;
    if (i == 0) cout << j + 1 << " ";
    else {
        prev = tr[i][j];
        trace(i-1, prev);
        cout << j + 1 << " ";
    }
}

int main() {
    freopen("flower.inp", "r", stdin);
    freopen("flower.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    for (int i = 1; i < n; i++) {
        int pos_i = i-1;
        int pos_w = a[i-1][pos_i];
        for (int j = i; j <= m - n + i; j++) {
            if (a[i-1][j-1] > pos_w) {
                pos_w = a[i-1][j-1];
                pos_i = j-1;
            }
            a[i][j] += pos_w;
            tr[i][j] = pos_i;
        }
    }

    int pos_i = n - 1;
    int pos_w = a[n-1][pos_i];

    for (int j = n - 1; j < m; j++)
        if (a[n-1][j] > pos_w) {
            pos_w = a[n-1][j];
            pos_i = j;
        }

    cout << a[n-1][pos_i] << endl;
    trace(n-1, pos_i);

    return 0;
}
