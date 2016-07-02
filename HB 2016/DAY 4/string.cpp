#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int base = 1000000007;
const int N = 1000001;

ll M[N], H[N];
string str;
int n, k, idx_a[N], idx_b[N], res[N];
vector <ll> a, b;

ll hash(int x, int y) {
    ll sum = 0;
    for (int j = x; j <= y; j++)
        sum += (sum*2309 + str[j+x-1] - 48) % base;
    return sum;
}

bool cmp_a(ll x, ll y) {
    return a[x] < a[y];
}

bool cmp_b(ll x, ll y) {
    return b[x] < b[y];
}

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> k;
    M[0] = 1;
    cin >> str;
    int i = 0;
    while (i < n) {
        a.push_back(hash(i, i + n/k - 1));
        i += k;
    }
    i = 0;
    while (i <= n/k) {
        cin >> str;
        b.push_back(hash(0, k));
        i++;
    }
    for (int i = 1; i <= k; i++) idx_a[i] = i, idx_b[i] = i;
    sort(idx_a + 1, idx_a + k + 1, cmp_a);
    sort(idx_b + 1, idx_b + k + 1, cmp_b);
    for (int i = 1; i <= n; i++) res[idx_a[i]] = idx_b[i];
    for (int i = 1; i <= k; i++) cout << res[i] << " ";
    return 0;
}
