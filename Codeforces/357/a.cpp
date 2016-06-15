#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        int b, a;
        cin >> b >> a;
        if (b >= 2400 && b - a > 0) { cout << "YES";  return 0; }
    }
    cout << "NO";
    return 0;
}
