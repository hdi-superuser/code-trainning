#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    char buffer[1000];
    int time = 0, v = 0;
    double distance = 0;
    while (cin.getline(buffer, sizeof(buffer))) {
        int h, m, s, newv;
        int n = sscanf(buffer, "%d:%d:%d %d", &h, &m, &s, &newv);
        int now = h*3600 + m*60 + s;
        distance += (now - time) * v;
        time = now;
        if (n == 3) printf("%02d:%02d:%02d %.2lf km\n", h, m, s, distance/3600);
        else if (n == 4) v = newv;
    }
    return 0;
}
