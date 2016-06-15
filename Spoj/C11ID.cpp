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

const int maxN = 100001;

int N, A[maxN];

int main(int argc, char **argv) {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif ONLINE_JUDGE 
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    sort(A + 1, A + N + 1);
    
    long long ans = 1;
    for (int i = 1; i <= N; i++) ans *= (A[i] - i + 1);
    
    cout << ans;
    
    return 0;
}
