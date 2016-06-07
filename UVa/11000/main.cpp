#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

const long long inf = 4294967296;

long long f[2001], m[2001], t[2001];
int main() {
    freopen("in.txt", "r", stdin);

    f[0] = t[0] = 1;    m[0] = 0;
    f[1] = m[1] = 1;    t[1] = 2;
    f[2] = m[2] = 2;    t[2] = 4;
    for (int i = 3; i <= 2000; i++) {
        f[i] = m[i-1] + 1;
        m[i] = m[i-1] + f[i-1];
        t[i] = t[i-1] + m[i-1] + 1;
        if (m[i] > inf || t[i] > inf) break;
    }

    int N;
    while ((cin >> N) && N >= 0) cout << m[N] << " " << t[N] << endl;

    return 0;
}
