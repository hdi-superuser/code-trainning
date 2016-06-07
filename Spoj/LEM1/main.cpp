#include <iostream>
#include <cmath>
#include <cstdio>

#define PI 3.14159265

using namespace std;

const int N = 10001;

int n;
double R[N];

double angel(double a, double b, double c) {
    return acos((a*a + b*b - c*c) / (2*a*b));
}

double check(double k) {
    double cnr = angel(R[n]+k, R[1]+k, R[n]+R[1]);
    for (int i = 2; i <= n; i++)
        cnr += angel(R[i-1]+k, R[i]+k, R[i-1]+R[i]);
    return cnr;
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> n;
    double l = 0, r = 0, res;
    for (int i = 1; i <= n; i++) cin >> R[i], r += R[i];

    while (l <= r) {
        double mid = (double) (l + r) / 2;
        if (check(mid) == 2*PI) res = mid, r = mid;
        else l = mid;
    }
    printf("%.3f", res);
    return 0;
}
