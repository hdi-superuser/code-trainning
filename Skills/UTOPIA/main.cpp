#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> dx, dy, x, y;
int N;

void process(vector <int> a, vector <int> s, vector <int> &q, int n, int l, int r) {
    if (n <= 1) return;
    if (s[n-1] == s[n]) {
        q[n] = a[l];
        process(a, s, q, n-1, l+1, r);
    } else {
        q[n] = a[r];
        process(a, s, q, n-1, l, r-1);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N;
    for (int i = 1; i <= 2*N; i++) {
        int xx, yy;
        cin >> xx >> yy;
        x.push_back(xx);    y.push_back(yy);
    }

    dx.assign(N, 0);    dy.assign(N, 0);
    for (int i = 1; i <= N; i++) {
        int code;
        cin >> code;
        switch (code) {
            case 1: dx[i] = 1, dy[i] = 1;
            case 2: dx[i] = -1, dy[i] = 1;
            case 3: dx[i] = -1, dy[i] = -1;
            case 4: dx[i] = 1, dy[i] = -1;
        }
    }

    vector <int> ansx(N, 0), ansy(N, 0);
    process(x, dx, ansx, N, 1, N);
    process(y, dy, ansy, N, 1, N);

    for (int i = 0; i < ansx.size(); i++) cout << ansx[i] << " ";
    for (int i = 0; i < ansy.size(); i++) cout << ansy[i] << " ";

    return 0;
}
