#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    string s;   int f[201];

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (s[i] >= s[j])
                f[i] = max(f[i], f[j] + 1);
    }

    cout << *max_element(f, f + s.size());

    return 0;
}
