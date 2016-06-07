// [May 20 2016] QTREE spoj - Heavy light decomposition, Least common ancestor, Segment tree.
#include <iostream>
#include <cstdio>
#include <cstring>

#define task "QTREE"

using namespace std;

const int MAX = 10001;

void pre_process(bool op) {
    if (!op) return;
    #ifndef ONLINE_JUDGE
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
}

int main() {
    pre_process(true);
    /*
	Do something.
    */
    return 0;
}
