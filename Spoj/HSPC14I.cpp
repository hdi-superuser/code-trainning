#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif ONLINE_JUDGE 
    
    int A[3];
    while (cin >> A[0] >> A[1] >> A[2]) {
        sort(A, A + 3);
        cout << max(abs(A[0] - A[1]), abs(A[1] - A[2])) - 1 << endl;
    }
    
    return 0;
}
