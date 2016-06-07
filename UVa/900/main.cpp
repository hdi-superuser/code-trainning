#include <iostream>

using namespace std;

int N;
long long f[51];

int main() {
    f[1] = 1;   f[2] = 2;   f[3] = 3;
    for (int i = 4; i <= 50; i++) f[i] = f[i-1] + f[i-2];

    while (cin >> N && N > 0) cout << f[N] << endl;

    return 0;
}
