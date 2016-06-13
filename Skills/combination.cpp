#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int N, M;
vi primes;
bitset<30001> bs;

void _sieve(int upperbound) {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= upperbound; i++)
        if (bs[i]) {
            for (int j = i*i; j <= upperbound; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
}

vi primesFactor(ll x) {
    vi factor;
    factor.assign(30000, 0);
    ll PF_idx = 0, PF = primes[PF_idx];
    while (PF*PF <= x) {
        while (x % PF == 0 && x) N /= PF, factor[PF]++;
        PF = primes[++PF_idx];
    }
    if (N != 1) factor[N]++, PF = N;
    factor[0] = PF;
    return factor;
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    _sieve(30000);
    vi fac_N = primesFactor(N);
    vi fac_M = primesFactor(M);
    vi fac_NM = primesFactor(N - M);

    int cnt = 0;
    for (int i = 1; i <= fac_N[0]; i++)
        if (fac_N[i] - fac_M[i] - fac_NM[i] > 0) cnt++;
    printf("%d\n", cnt);
}
