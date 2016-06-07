#include <iostream>
#include <cstdio>

using namespace std;

int ans = 0, OK;

void backtrack(int rw, int ld, int rd) {
    if (rw == OK) { ans++; return; }
    int pos = OK & (~(rw | ld | rd));
    while (pos) {
        int p = pos & -pos;
        pos -= p;
        backtrack(rw | p, (ld | p) << 1, (rd | p) >> 1);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    cin >> N;
    OK = (1 << N) - 1;
    backtrack(0, 0, 0);
    cout << ans;

    return 0;
}
