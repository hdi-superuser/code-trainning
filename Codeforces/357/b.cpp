#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int a = 1; a <= 811; a++)
        for (int b = 1; b <= (n - a*1234567)/123456 + 1; b++) {
            int c = (n - a*1234567 - b*123456)/1234;
            if (a*1234567 + b*123456 + c*1234 == n) {
                printf("YES");
                return 0;
            }
        }
    printf("NO");
    return 0;
}
