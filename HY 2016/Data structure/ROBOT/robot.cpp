#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

struct robot {
    int x, y;
    char z;

    bool operator < (const robot &p) {
        return x < p.x || (x == p.x && y < p.y);
    }
} rb[N];

int n, m, k, sum;

class pre_process {
private:
    int x[N], y[N], idx[N];

public:
    void init() {
        cin >> n >> m >> k;
        for (int i = 1; i <= k; i++) {
            cin >> x[i] >> y[i] >> rb[i].z;

            switch (rb[i].z) {
                case 'N': sum += n - x[i];
            }
        }
    }

    void zip() {
        for (int i = 1; i <= k; i++) idx[i] = x[i];
        sort(idx + 1, idx + k + 1);
        int m = unique(idx + 1, idx + k + 1) - idx;
        for (int i = 1; i <= k; i++)
            rb[i].x = lower_bound(idx + 1, idx + m + 1, x[i]) - idx;

        for (int i = 1; i <= k; i++) idx[i] = y[i];
        sort(idx + 1, idx + k + 1);
        m = unique(idx + 1, idx + k + 1) - idx;
        for (int i = 1; i <= k; i++)
            rb[i].y = lower_bound(idx + 1, idx + m + 1, y[i]) - idx;
    }

    void excute() {
        init();
        zip();
    }
} pre_process;

int main() {
    ios_base::sync_with_stdio(0);
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);

    pre_process.excute();
    for (int i = 1; i <= k; i++)
        cout << rb[i].x << " " << rb[i].y << " " << rb[i].z << endl;

    return 0;
}
