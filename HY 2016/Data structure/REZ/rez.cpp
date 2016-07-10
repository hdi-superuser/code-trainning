#include <bits/stdc++.h>

using namespace std;

struct ss {
  int f, t;
  bool operator< (const ss& a) const {
    return t < a.t;
  }
} a[100001];

int dp[100001];

int main() {
  freopen("rez.inp", "r", stdin);
  freopen("rez.out", "w", stdout);

  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d %d", &a[i].f, &a[i].t);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    int lo = 1;
    int hi = i - 1;
    int p = -1;
    while (lo <= hi) {
      int mi = (lo + hi) >> 1;
      if (a[mi].t <= a[i].f) {
        p = mi;
        lo = mi + 1;
      } else {
        hi = mi - 1;
      }
    }
    dp[i] = a[i].t - a[i].f;
    if (p != -1)
      dp[i] += dp[p];
    if (dp[i - 1] > dp[i])
      dp[i] = dp[i - 1];
  }
  printf("%d", dp[n]);
}
