#include <iostream>
#include <cstdio>

using namespace std;

int f[1501][351];

int main() {
    freopen("in.txt", "r", stdin);

    f[1][0] = f[2][0] = 1;
    for (int i = 3; i <= 1500; i++)
    for (int j = 0; j <= 350; j++) {
        f[i][j] += f[i-1][j] + f[i-2][j];
        if (f[i][j] > 9) f[i][j] -= 10, f[i][j+1]++;
    }
    for (int i = 1; i <= 10; i++) {
        int j = 5;
        while (!f[i][--j]);
        for ( ; j >= 0; j--) cout << f[i][j];
        cout << " ";
    }
    int N, cnt = 0;
    while ((cin >> N) && N) {
        cout << "Set " << ++cnt << ":" << endl;
        int t = N/2, i = 350;
        if (N % 2) t = (N + 1)/2;
        while (!f[t][--i]);
        for ( ; i >= 0; i--) cout << f[t][i];
        cout << endl;
    }
    return 0;
}
