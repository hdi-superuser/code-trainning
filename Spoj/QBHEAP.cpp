#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

priority_queue <long long> heap;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("spoj.inp", "r", stdin);
        freopen("spoj.out", "w", stdout);
    #endif // ONLINE_JUDGE

    char c;
    while (scanf("%c", &c) == 1) {
        if (c == '+') {
            long long v;
            cin >> v;
            if (heap.size() < 15000) heap.push(v);
        } else if (c == '-') {
            scanf("\n");
            if (heap.size()) {
                long long k = heap.top();
                while (heap.top() == k && !heap.empty()) heap.pop();
            }
        }
    }

    vector <long long> res;
    while (!heap.empty()) {
        long long k = heap.top();
        res.push_back(k);
        while (heap.top() == k && !heap.empty()) heap.pop();
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << endl;

}
