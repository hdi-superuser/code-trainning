#include <bits/stdc++.h>

#define long long long

using namespace std;

const long M = 1000000007;

map<long, long> F;

long f(long n) {
     if (F.count(n)) return F[n];
     long k = n/2;
     if (n % 2 == 0) { // n=2*k
         return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
     } else { // n=2*k+1
         return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
     }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    F[0]=F[1]=1;
    cin >> N;
    cout << f(N);

    return 0;
}
