#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define x first
#define y second
#define PI acos(-1.0)

using namespace std;

typedef pair<int, int> ii;
vector < ii > v;
int N;

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

void process(int n) {
    if (n == 1) return;
    if (n == 2) {
        if (angle(v[1], v[2]) <= 90.0) change(v[2]);

    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int xx, yy;
        cin >> xx >> yy;
        v.push_back(ii(xx, yy));
    }

    return 0;
}
