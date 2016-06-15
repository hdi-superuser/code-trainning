#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <set>

#define ll long long 
#define x first
#define y second

using namespace std;

const int maxN = 1001;

int N, p[maxN], d[maxN][maxN], f[maxN];

int main(int argc, char **argv) {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif ONLINE_JUDGE 
    
    cin >> N;
    f[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        if (p[i] > 100) f[i] = f[i-1] + 1;
        else f[i] = f[i-1];
    }
    
    d[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= f[i]; j++) {
            d[i][j] = 1000000000;
            if (j <= f[i-1]) d[i][j] = d[i-1][j] + p[i];
            if (d[i-1][j-1]+p[i] < d[i][j] && p[i] > 100 && j > 0) d[i][j] = d[i-1][j-1] + p[i];
            if (d[i-1][j+1] < d[i][j] && j < f[i-1]) d[i][j] = d[i-1][j+1];
        }
    }
    
    int res = 1000000000;
    for (int i = 0; i <= f[N]; i++) res = min(res, d[N][i]);
    cout << res;
    
    return 0;
}
