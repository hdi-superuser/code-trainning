#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int N = 500;
int n, f[N], b[N];
vector<int> a[N];

bool cmp(int u, int v) {return u > v;}

void dfs(int u)
{
 int m = a[u].size();
 if (m == 0) {
      f[u] = 1; return ;
 }
 for (int i=0;i<m;i++) dfs(a[u][i]);
 for (int i=0;i<m;i++) b[i] = f[a[u][i]];
 sort(b, b+m, cmp);
 int ans = 0, now = 0;
 for (int i=0;i<m;i++) {
    if (now < b[i]) {
      ans += b[i]-now;
      now = b[i]-1;
    }
 else {
    now--;
 }
 }
 
f[u] = ans;

}

int main()
{

 scanf("%d", &n);
 int m, u, v;
 while (scanf("%d", &u) == 1) {
     scanf("%d", &m);
     for (int i=1;i<=m;i++) scanf("%d", &v), a[u].pb(v);
 }
 dfs(1);
 printf("%d", f[1]);
 
return 0;

}

