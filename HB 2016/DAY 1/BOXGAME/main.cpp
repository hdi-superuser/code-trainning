#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
typedef vector<int> vi;
typedef pair<string, int> psi;

queue< psi > q;
int start;
int POW[11], inq[N], d[N];
pair<int, int> tr[N];

void read() {
    string str;
    cin >> str;
    str = "#  " + str;
    q.push(make_pair(str, 1));
}

int pow(int x, int k) {
    if (k == 0) return 1;
    if (k == 1) return x;
    int t = pow(x, k/2);
    if (k & 1) return x*t*t;
    return t*t;
}

int extract(string s) {
    int t = 0;
    for (int i = 1; i < s.size(); i++)
        if (s[i] != ' ') t += pow(s[i] - 65, i - 1);
        else t += pow(4, i-1);
    return t;
}


bool ok(string s) {
    if (s[1] != s[2] || s[1] != ' ' || s[2] != ' ') return false;
    int c[4] = {0};
    for (int i = 3; i < s.size(); i++)
        if (s[i] != s[i-1]) c[s[i] - 65]++;
    for (int i = 0; i < 3; i++)
        if (c[i] > 1) return false;
    return true;
}

void print(int t) {
    printf("%d ", tr[t].first);
    while (t != start) {
        printf("%d ", tr[t].second);
        t = tr[t].first;
    }
    printf("\n");
}

void solve() {
    memset(inq, 0, sizeof inq);
    memset(tr, 0, sizeof tr);
    memset(d, 0, sizeof d);
    start = extract(q.front().first);
    while (!q.empty()) {
        string p = q.front().first;
        int pos = q.front().second;
        q.pop();
        for (int i = 1; i < p.size() - 1; i++) {
            int t = extract(p);
            if (p[i] != ' ' && p[i+1] != ' ') {
                string y = p;
                y[pos] = p[i];
                y[pos+1] = p[i+1];
                y[i] = y[i+1] = ' ';
                int k = extract(y);
                if (ok(y)) { print(k); return; }
                if (inq[k]) continue;
                inq[k] = 1;
                tr[k].first = t;
                tr[k].second = i;
                d[k] = d[t] + 1;
                q.push(make_pair(y, i));
            }
        }
    }
    printf("-1\n");
}


int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d\n", &T);
    while (T--) {
        read();
        solve();
    }
    return 0;
}
