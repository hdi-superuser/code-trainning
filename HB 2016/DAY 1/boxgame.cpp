#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<string, int> psi;

queue< psi > q;
int inq[1000001];

void read() {
    string str;
    cin >> str;
    q.push(str);
}

int pow(int x, int k) {
    int t = pow(x, k/2);
    if (x & 1) t*t*x;
    return t*t;
}

int covert_base4(string s) {
    int t = 0;
    for (int i = 0; i < s.size(); i++)
        t += pow(s[i] - 65, i);
    return t;
}

void solve() {

}

void print() {

}

int main() {
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d\n", &T);
    while (T--) {
        read();
        solve();
        print();
    }
}
