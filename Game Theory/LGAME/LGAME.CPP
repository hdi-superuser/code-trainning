// [May 18 2016] LGAME - Game theory O((3^10)*10*2)
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

#define task "LGAME"

using namespace std;

const int MAX = 60000;
typedef vector<int> vi;

vi a, c;
int f[MAX], cnt = 0;

void pre_process(bool op) {
    if (!op) return;
    #ifndef ONLINE_JUDGE
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL);    cin.tie(NULL);
}

int pow(int n, int k) {
    int res = 1;
    for (; k; k >>= 1, n *= n) if (k & 1) res *= n;
    return res;
}

vi toBase_3(int val) {
    vi res;
    while (val) {
        res.push_back(val % 3);
        val /= 3;
    }
    for (int i = 1; i <= res.size()-cnt; i++) res.push_back(0);
    res.push_back(res.size());
    reverse(res.begin(), res.end());
    return res;
}

int toBase_10(vi val) {
    int res = 0;
    for (int i = val[0]; i; i--) res += val[i]*pow(3, val[0]-i);
    return res;
}

void go(int pos, int k, vi f1, vi &f2) {
    for (int j = 0; j < f1.size(); j++) f2[j] = f1[j];
    if (pos == f1[0]) { f2[pos] -= k; return; }
    f2[pos] -= k;   f2[pos+1] += k;
}

void excute(int x) {
    if (!x) { f[x] = 1; return; }
    if (f[x] != -1) return;
    vi b = toBase_3(x);
    int ans = 0;
    for (int i = 1; i <= b[0]; i++)
        for (int ci = 1; ci <= 2; ci++)
            if (b[i] >= ci) {
                vi d;   d.assign(cnt+1, 0);
                go(i, ci, b, d);
                for (int j = 1; j <= d[0]; j++) d[i] %= 3;
                int y = toBase_10(d);
                excute(y);
                if (!f[y]) f[x] = 1; else f[x] = 0;
            }
}

int main() {
    pre_process(true);
    string s;   cin >> s;
    a.assign(11, 0);
    for (int i = s.size()-1; i >= 0; i--)
        if (s[i] == '.') a[cnt]++;
        else cnt++;
    a[0] = cnt;
    for (int i = 1; i <= a[0]; i++) a[i] %= 3;
    c.push_back(cnt);
    for (int i = a[0]; i; i--) c.push_back(a[i]);
    memset(f, -1, sizeof f);
    excute(toBase_10(c));
    int ans = 0;
    for (int i = 1; i <= c[0]; i++)
    for (int ci = 1; ci <= 2; ci++) {
        if (c[i] >= ci) {
            vi d;   d.assign(cnt+1, 0);
            go(i, ci, c, d);
            for (int j = 1; j <= d[0]; j++) d[i] %= 3;
            int y = toBase_10(d);
            if (!f[y]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
