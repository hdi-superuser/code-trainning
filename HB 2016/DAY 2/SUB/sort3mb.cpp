#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sort3mb.inp", "r", stdin);
    freopen("sort3mb.out", "w", stdout);

    priority_queue<float, vector<float>, greater<float> > q;
    int n;
    scanf("%d\n", &n);
    while (n--) {
        float x;
        scanf("%f ", &x);
        q.push(x);
    }
    while (!q.empty()) {
        printf("%.2f ", q.top());
        q.pop();
    }
    return 0;
}
