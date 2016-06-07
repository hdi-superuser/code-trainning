/* Combinatorics: Digits in N!
   =================================================================
   Description: Given N, computes the number of digits that N! will
                occupy in base B.

   Complexity:  O(N)
   -----------------------------------------------------------------
   Author:      Gilbert Lee, Ashley Zinyk
   Date:        Feb 14, 2003
   References:
   -----------------------------------------------------------------
   Reliability: 1 (Problem B - Big Number Feb 11, 2003)
   Notes:       The results fit nicely in doubles up to N = 10^7, but
                run time may be slow.

                Returns 1 for n < 0, although technically undefined.
                The base must be larger than 1.
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

ll fact_digit(int n, int b) {
    double sum = 0;
    for (int i = 2; i <= n; i++) sum += log(i);
    return (ll) floor(1 + sum/log(b));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cout << fact_digit(1, 2);

    return 0;
}
