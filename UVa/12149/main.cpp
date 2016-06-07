#include <iostream>
#include <cstdio>

using namespace std;

long long f[101];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    for (int i = 1; i <= 100; i++) f[i] = f[i-1] + (i*i);
    int N;
    for ( ; (cin >> N) && N; ) cout << f[N] << endl;

    return 0;
}
