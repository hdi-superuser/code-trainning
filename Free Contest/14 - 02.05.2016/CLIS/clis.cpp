#include <iostream>
#include <algorithm>

using namespace std;

string s;
int f[201];

int main() {
    cin >> s;

    for (int i = 0; i < s.size(); i++) f[i] = 1;
    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < i; j++)
            if (s[i] >= s[j]) f[i] = max(f[i], f[j] + 1);
    }

    cout << *max_element(f, f + s.size());
    return 0;
}
