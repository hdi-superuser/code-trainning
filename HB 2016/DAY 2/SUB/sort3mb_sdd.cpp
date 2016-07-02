#include <bits/stdc++.h>

using namespace std;

const float eps = 0.00001;
int n;

ifstream f1("sort3mb.inp");
ofstream f2("out.txt");

int main() {
    f1 >> n;
    float a[n/2 + 2];
    for (int i = 1; i <= n/2; i++) f1 >> a[i];
    sort(a + 1, a + n/2 + 1);
    for (int i = 1; i <= n/2; i++) f2 << a[i] << " ";
    memset(a, 0, sizeof a);
    int na = 0;
    for (int i = n/2 + 1; i <= n; i++) f1 >> a[++na];
    sort(a + 1, a + na + 1);
    int i = 1, j = 0;
    float x;
    f2.close();
    ifstream f3("out.txt");
    ofstream f4("sort3mb.out");

    f3 >> x;
    for (int k = 1; k <= n; k++) {
        if (x < a[i] && (j < n/2 || i > n - n/2)) {
            f4 << x << " ";
            j++;
            f3 >> x;
        } else {
            f4 << a[i] << " ";
            i++;
        }
    }

    f1.close();
    f3.close();
    f4.close();
    return 0;
}
