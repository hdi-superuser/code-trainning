#include <iostream>
#include <cstdio>

using namespace std;

int f[50], cmp[50];

int main() {
    freopen("in.txt", "r", stdin);

    f[0] = f[1] = 1;
    for (int i = 2; i <= 50; i++) f[i] = f[i-1] + f[i-2];

    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 45; i; i--)
            if (f[i] <= N) N -= f[i], cmp[i] = 1; else cmp[i] = 0;
        int i = 45;
        while (!cmp[--i]);
        for ( ; i; i--) cout << cmp[i];
        cout << endl;
    }

    return 0;
}
