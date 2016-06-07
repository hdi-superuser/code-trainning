#include <iostream>
#include <cstdio>

using namespace std;

int N, Tcase, cnt;
long long f[52];

int main() {
    freopen("in.txt", "r", stdin);

    f[0] = 1;   f[1] = 2;
    for (int i = 2; i <= 51; i++) f[i] = f[i-1] + f[i-2];

    cin >> Tcase;
    while (Tcase--) {
        cin >> N;
        cout << "Scenario #" << ++cnt << ":" << endl << f[N] << endl << endl;
    }

    return 0;
}
