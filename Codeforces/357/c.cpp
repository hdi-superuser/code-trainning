#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    priority_queue <int, vector<int> greater<int> > q;
    int n;
    cin >> n;
    while (n--) {
        string str;
        int x;
        cin >> str;
        if (str == "insert") {
            cin >> x;
            q.push(x);
            cout << "insert " << x << endl;
        }
        if (str == "getMin") {
            cin >> x;
        }
}
