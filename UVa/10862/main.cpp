#include <iostream>
#include <cstdio>

using namespace std;

int f[4001][1001];

int main() {
    freopen("in.txt", "r", stdin);

    f[1][0] = f[2][0] = 1;
    for (int i = 3; i <= 4000; i++)
    for (int j = 0; j <= 1000; j++) {
        f[i][j] += f[i-1][j] + f[i-2][j];
        if (f[i][j] > 9) f[i][j] -= 10, f[i][j+1]++;
    }

    int N;
    while ((cin >> N) && N) {
        int i = 1000;
        while (!f[2*N][--i]);
        for (; i >= 0; i--) cout << f[2*N][i];
        cout << endl;
    }

    return 0;
}
