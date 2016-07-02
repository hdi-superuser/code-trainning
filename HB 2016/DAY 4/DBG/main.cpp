#include <bits/stdc++.h>

using namespace std;

int n, p[2000001];

long long get(int x) {
    if (x < 3) return 0;
    if (x == 3) return 1;
    return (x*(x-1)*(x-2))/6;
}

int main() {
    freopen("in.txt", "r", stdin);
    int T;
    p[0] = p[1] = 1;
    for (int i = 2; i*i < 2000001; i++)
        if (!p[i])
            for (int j = i*i; j < 2000001; j += i)
                p[i] = 1;

    cin >> T;
    while (T--) {
        cin >> n;
        int NT = 0, NF = 0;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                if (p[i+j]) NT++;
                else NF++;
        cout << get(NT) + (NF) << " " << NT << " " << NF << endl;
    }
}
