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

int main(int argc, char **argv) {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif ONLINE_JUDGE 
    
    int T;
    cin >> T;
    while (T--) {
        long long cntA, cntB, maxA, maxB;
        cin >> cntA >> cntB >> maxA >> maxB;
        if (maxA == 0) cntA = 0;
        if (maxB == 0) cntB = 0;
        if (cntA > cntB) {
            swap(cntA, cntB);
            swap(maxA, maxB);
        }
        cout << cntA + min(cntB, (cntA + 1)*maxB) << endl;
    }
    
    return 0;
}
