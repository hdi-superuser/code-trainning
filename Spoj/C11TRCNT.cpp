#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <set>

using namespace std;

const int maxN = 201;

int N, d[maxN], x[maxN], y[maxN];

bool ok(int i, int j, int k) {
    int abx = x[j] - x[i];
    int aby = y[j] - y[i];
    int acx = x[k] - x[i];
    int acy = y[k] - y[i];
    return abx*acy != aby*acx;
}

int main(int argc, char **argv) {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif ONLINE_JUDGE 
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
    
    int ans = 0;
    for (int i = 1; i <= N-2; i++) 
        for (int j = i + 1; j <= N-1; j++)
            for (int k = j + 1; k <= N; k++) 
                if (ok(i, j, k))
                    ans++, d[i]++, d[j]++, d[k]++;
    int id = 1;
    for (int i = 1; i <= N; i++) 
        if (d[id] > d[i]) id = i;
        
    cout << ans << " " << id;
    
    return 0;
}
