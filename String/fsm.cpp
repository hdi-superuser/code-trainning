// finite state machine implementation

#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;

int f[N], m;

void fsm(string p) {
    m = p.size() - 1;
    memset(f, -1, sizeof f);
    for (int i = 1; i < m; i++) {
        int j = f[i-1];
        while (p[j+1] != p[i] && j >= 0) j = f[j];
        f[i] = j + 1;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    string str;
    cin >> str;
    str  = " " + str;
    fsm(str);
    for (int i = 1; i < m; i++) printf("%d ", f[i]);
    return 0;
}
