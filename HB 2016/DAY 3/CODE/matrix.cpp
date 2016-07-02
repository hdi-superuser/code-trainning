#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int m, n, fr[9], x[9];
vector <int> a[9];
vector < vi > ans;

bool cmp(vi a, vi b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] < b[i]) return true;
    return false;
}

void excute() {
    vector< vector<int> > t;
    for (int k = 1; k <= n; k++) t.push_back(a[x[k]]);
    for (int k = 0; k < t.size() - 1; k++)
        for (int k2 = k + 1; k2 < t.size(); k2++)
            if (cmp(t[k2], t[k])) swap(t[k], t[k2]);
    for (int k = 1; k <= m; k++) {
        for (int k2 = 1; k2 <= n; k2++) {
            if (t[k2-1][k-1] < ans[k2-1][k-1]) {
                ans = t;
                return;
            }
        }
    }
}

void permu(int i) {
    for (int j = 1; j <= n; j++)
        if (!fr[j]) {
            x[i] = j;
            if (i == n) excute();
            else {
                fr[j] = 1;
                permu(i+1);
                fr[j] = 0;
            }
        }
}

int main() {
    freopen("in.txt", "r", stdin);
    //ios_base::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < s.size(); j++)
                a[i].push_back(s[j] - '0');
    }
    vector<int> t;
    for (int i = 0; i <= m; i++) t.push_back(1);
    for (int i = 0; i <= n; i++) ans.push_back(t);
    permu(1);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cout << ans[j-1][i];
        cout << endl;
    }
    return 0;
}

