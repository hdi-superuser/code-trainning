#include <iostream>
#include <cstdio>

using namespace std;

int N;
int f[801][501];

int main() {
    freopen("in.txt", "r", stdin);

    f[1][0] = 1;    f[2][0] = 1;
    for (int i = 3; i <= 800; i++)
    for (int j = 0; j <= 5; j++) {
        f[i][j] += f[i-1][j] + f[i-2][j];
        if (f[i][j] > 9) f[i][j] -= 10, f[i][j+1]++;
    }

    while (cin >> N) {
        if (N == -1) break;
        int i = 5;
        while (!f[N][--i]);
        for (; i >= 0; i--) cout << f[N][i];
        cout << endl;
    }

    return 0;
}
