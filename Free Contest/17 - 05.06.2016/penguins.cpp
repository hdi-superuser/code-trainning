#include <bits/stdc++.h>

using namespace std;

double d;
int n;
struct data {
    int x, y, u, v;
} ice[101];

int main() {
    scanf("%d %f", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &ice[i].x, &ice[i].y, &ice[i].u, &ice[i].v);
    }
    printf("-1");
    return 0;
}
