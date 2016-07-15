#include <bits/stdc++.h>

using namespace std;

const int K = 27;
const int N = 501;
const int inf = 2000000001;

long long a[K][K];
int b[K][K], c[K];

int k, n;

struct Q {
    vector <int> arr;
    long long w;
} q[N];
int first, last;

long long calc(string s) {

    first = last = 0;

    for (int i = 0; i < s.size() - 1; i++) {
        ++last;
        for (int j = 0; j < i; j++) q[last].arr.push_back(s[j] - 'a');
        q[last].w += a[s[i] - 'a'][s[i+1] - 'a'];
        q[last].arr.push_back(b[s[i] - 'a'][s[i+1] - 'a']);
        for (int j = i + 2; j < s.size(); j++) q[last].arr.push_back(s[i] - 'a');
    }

    first = 1;
    long long cost = inf;
    while (first <= last) {
        Q u = q[first++];
        if (u.arr.size() == 1) cost = min(cost, u.w);

        for (int i = 0; i < u.arr.size() - 1; i++) {
            ++last;
            for (int j = 0; j < i; j++)
                q[last].arr.push_back(u.arr[j]);
            q[last].w += u.w + a[u.arr[i]][u.arr[i+1]];
            q[last].arr.push_back(b[u.arr[i]][u.arr[i+1]]);
            for (int j = i + 2; j < u.arr.size(); j++)
                q[last].arr.push_back(u.arr[j]);
        }
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(0);   cin.tie(NULL);
    freopen("assemble.inp", "r", stdin);
    freopen("assemble.out", "w", stdout);

    cin >> k;
    char ss;
    for (int i = 1; i <= k; i++) cin >> ss, c[i] = ss - 'a';
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++) {
            string s;
            cin >> s;
            int t1 = 0;
            for (int t = 0; t < s.size(); t++) {
                if (s[t] >= 48 && s[t] <= 57) t1 = t1*10 + (s[t] - 48);
                else break;
            }
            a[c[i]][c[j]] = t1;
            b[c[i]][c[j]] = s[s.size() - 1] - 'a';
        }

    cin >> n;
    while (n--) {
        string str; cin >> str;
        cout << calc(str) << endl;
    }

    return 0;
}
