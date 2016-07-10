#include <bits/stdc++.h>

using namespace std;

int xa, ya, xb, yb, xc, yc;
double s;

double p(int x, int y, int x1, int y1, int x2, int y2) {
    int pp = (x + x1)*(y - y1) + (x1 + x2)*(y1 - y2) + (x2 + x)*(y2 - y);
    return fabs((double) pp/2);
}

bool ok(int x, int y) {
    double a = p(x, y, xa, ya, xb, yb);
    double b = p(x, y, xa, ya, xc, yc);
    double c = p(x, y, xb, yb, xc, yc);
    if (a == 0.0 || b == 0.0 || c == 0.0) return false;
    if (a + b + c == s) return true;
}

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    //scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
    //cout << xc << " " << yc << endl;
    //xa = 2; ya = 1; xb =1; yb = 6; xc = -5; yc = -2;
    int minx = min(xa, min(xb, xc));
    int maxx = max(xa, max(xb, xc));
    int miny = min(ya, min(yb, yc));
    int maxy = max(ya, max(yb, yc));
    s = p(xa, ya, xb, yb, xc, yc);

    vector < pair<int, int> > res;

    int ans = 0;
    for (int i = minx; i <= maxx; i++)
        for (int j = miny; j <= maxy; j++) {
            if (ok(i, j)) res.push_back(make_pair(i, j));
        }

    ans = unique(res.begin(), res.end()) - res.begin();

    cout << ans;
}

