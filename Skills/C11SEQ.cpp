#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

int N, L, R;
int A[MAX+1], idx[MAX+1];
int s[MAX+1], p[2][MAX+1], bit[MAX+1];

int get(int x) {
    int sum = 0;
    for ( ; x; x -= x & (-x)) sum += bit[x];
    return sum;
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d %d", &N, &L, &R);
    for (int i = 1; i <= N; i++) scanf("%d ", &A[i]);

    for (int i = 1; i <= N; i++) s[i] = s[i-1] + A[i];
    for (int i = 1; i <= N; i++)
        p[0][i] = s[i] - L,
        p[1][i] = s[i] - R;

    for (int i = 1; i <= N; i++) idx[i] = s[i];
    sort(idx + 1, idx + N + 1);
    for (int i = 1; i <= N; i++)
        s[i] = lower_bound(idx + 1, idx + N + 1, s[i]) - idx;
    for (int i = 1; i <= N; i++) idx[i] = p[0][i];
    sort(idx + 1, idx + N + 1);
    for (int i = 1; i <= N; i++)
        p[0][i] = lower_bound(idx + 1, idx + N + 1, p[0][i]) - idx;
    for (int i = 1; i <= N; i++) idx[i] = p[1][i];
    sort(idx + 1, idx + N + 1);
    for (int i = 1; i <= N; i++)
        p[1][i] = lower_bound(idx + 1, idx + N + 1, p[1][i]) - idx;

    for (int i = 1; i <= N; i++) bit[s[i]] = 1;
    int res = 0;
    for (int i = 1; i <= N; i++)
        res += get(p[0][i])*get(p[1][i]);
    printf("%d ", res);
    return 0;
}
