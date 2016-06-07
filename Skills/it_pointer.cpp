#include <iostream>
#include <cstdio>

using namespace std;

struct node {
    int ll, rr, id;
    node(int L, int R, int X) {
        ll = L, rr = R, id = X;
        lazy_update();
    }
    node left() 
        { return node(ll, (ll + rr) >> 1, id*2); }
    node right() 
        { return node((ll + rr) >> 1, rr, id*2+1); }
    void lazy_update() {
        if (lazy[id] == -1) return;
        if (ll != rr) lazy[id*2]
    }
};

int main() {
    freopen("in.txt", "r", stdin);
}
