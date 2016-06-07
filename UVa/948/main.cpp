#include <iostream>
#include <cstdio>

using namespace std;

int f[45], cmp[45];
int N;

int main() {
    freopen("in.txt", "r", stdin);

    f[1] = f[2] = 1;
    for (int i = 3; i <= 45; i++) f[i] = f[i-1] + f[i-2];

    int Case, cnt = 0;
    cin >> Case;
    while (Case--) {
        cin >> N;
        cout << N << " = ";
        for (int i = 40; i; i--)
            if (f[i] <= N) N -= f[i], cmp[i] = 1;
            else cmp[i] = 0;
        int last = 40;
        while (!cmp[last] && last) last--;
        while (last > 1) cout << cmp[last--];
        cout << " (fib)" << endl;
    }

    return 0;
}
