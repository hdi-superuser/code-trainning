/*
 * Sample preview code
 * This is a block comment
 */

#include <stdio.h> // this is a line comment
#include <iostream>
#include <string.h>
#include <math.h>
#include <cmath>

/**
  * This is a documentation comment block
  * @param xxx does this (this is the documentation keyword)
  * @authr some user (this is the documentation keyword error)
  * Code::Blocks 13.12 GNU C++ Compiler 4.7.1
  */

#define file "BEND"
#define maxN 15000001

using namespace std;

int N;
int Count[maxN];
int Pythagore[maxN];

int GCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void genARR() {
    //memset(Count, 0, sizeof(Count));
    //memset(Pythagore, 0, sizeof(Pythagore));
    for (int m = 1; m <= trunc(sqrt(maxN)); m++)
        for (int n = 1; n < m; n++)
            if ((GCD(m, n) == 1) && (((n + m)) % 2) == 1) {
                int a = 2*m*n, b = m*m - n*n, c = m*m + n*n;
                int k = 1;
                while (k*a + k*b + k*c <= maxN) {
                    Pythagore[k*a+k*b+k*c]++;
                    //if (b*b + a*a == c*c) cout << 1 << " "; else cout << 0 << " ";
                    //cout << k*a << " " << k*b << " " << k*c << " " << k*a + k*b + k*c << endl;
                    k++;
                }
            }
    for (int i = 1; i <= maxN; i++)
        if (Pythagore[i] == 1) Count[i] = Count[i-1] + 1;
        else Count[i] = Count[i-1];
}

void Solve() {
    genARR();
    while (cin >> N) {
        cout << Count[N] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    Solve();
    return 0;
}
