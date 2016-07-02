#include <bits/stdc++.h>

using namespace std;


main() {
    freopen("guessDST.inp", "r", stdin);
    freopen("guessDST.out", "w", stdout);
    int T;
    scanf("%d\n", &T);
    int n2 = 1, n3 = 1, n4 = 1;
    priority_queue<int> q2;
    queue<int> q3;
    stack<int> q4;

    while (T--) {
        int c, x;
        scanf("%d %d\n", &c, &x);
        if (c == 1) {
            q2.push(x);
            q3.push(x);
            q4.push(x);
        } else {
            int u;
            if (q2.empty()) n2 = 0;
            else {
                u = q2.top();
                q2.pop();
                if (u != x) n2 = 0;
            }
            if (q3.empty()) n3 = 0;
            else {
                u = q3.front();
                if (u != x) n3 = 0;
                q3.pop();
            }
            if (q4.empty()) n4 = 0;
            else {
                u = q4.top();
                if (u != x) n4 = 0;
                q4.pop();
            }
        }
    }
    if (n2 + n3 + n4 > 1) printf("not sure");
    else {
        if (n2 + n3 + n4 == 0) printf("impossible");
        else {
            if (n2) printf("priority queue");
            if (n3) printf("queue");
            if (n4) printf("stack");
        }
    }
    return 0;
}
