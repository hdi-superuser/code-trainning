#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    string a, b;
    while (cin >> a >> b) {
        if (a == "0" && b == "0") return 0;
        while (a.size() < b.size()) a = "0" + a;
        while (a.size() > b.size()) b = "0" + b;
        int carry = 0, ans = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            int c = a[i] + b[i] - 96 + carry;
            carry = c / 10;
            ans += c / 10;
        }
        if (!ans) cout << "No carry operation." << endl;
        else if (ans == 1) cout << "1 carry operation." << endl;
            else cout << ans << " carry operations." << endl;
    }
    return 0;
}
