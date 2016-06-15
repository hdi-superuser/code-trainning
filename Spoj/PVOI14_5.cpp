/*
 * Sample preview code
 * This is a block comment
 */

#include <stdio.h> // this is a line comment
#include <string.h>
#include <math.h>

/**
  * This is a documentation comment block
  * @param xxx does this (this is the documentation keyword)
  * @authr Huynh Duy Idol
  * Code::Blocks 13.12 GNU C++ Compiler 4.7.1
  */

#define file "P"
#define maxN 100001

using namespace std;

long long Z[maxN], A[maxN], C[maxN], D[maxN];
bool PRIME[maxN];
long long L[31][maxN];
long long T[51];
long long N, Count, cntl, x, res, step;

void Eratosthene(long long MAX) {
    memset(PRIME, true, sizeof(PRIME));
    PRIME[1] = false;
    for (long long i = 2; i <=  trunc(sqrt(MAX)); i++)
        for (long long j = 2; j <= MAX / i; j++) PRIME[i*j] = false;
    for (long long i = 1; i <= MAX; i++)
        if (PRIME[i]) Z[++Count] = i;
}

long long Power(long long A, long long x) {
    long long t;
    if (x == 0) return 1;
    if (x == 1) return A;
    t = Power(A, x / 2);
    if (x % 2 == 0) return t*t; else return t*t*A;
}

void getPRIME(long long i) {
    long long j = 1, T = A[i];
    while (T > 1 && j <= Count) {
        if (T % Z[j] == 0) {
            T /= Z[j];
            L[j][i]++;
        } else j++;
    }
    if (T > 1)
    if (D[T] == 0) {
        C[++cntl] = T;
        D[T] = 1;
    } else D[T]++;
}

long long ABS(long long k1, long long k2) {
    if (k1 > k2) return k1 - k2; else return k2 - k1;
}

void Process() {
    res = 1;
    Eratosthene(101);
    scanf("%lld", &N);
    if (N % 2 == 0) x = N / 2; else x = (N+1) / 2;
    for (long long i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
        getPRIME(i);
    }
    for (long long i = 1; i <= Count; i++) {
        memset(T, 0, sizeof(T));
        for (long long j = 1; j <= N; j++) T[L[i][j]]++;
        long long temp = T[0];
        long long y = 0, j = 0;
        while (temp < x) {
            j++;
            temp += T[j];
        }
        y = j;
        for (long long j = 0; j <= 15; j++) step += T[j]*ABS(y, j);
        res *= Power(Z[i], y);
    }
    for (long long i = 1; i <= cntl; i++) {
        if (N - D[C[cntl]] >= x) step += D[C[i]];
        else {
            res *= C[cntl];
            step += N - D[C[cntl]];
        }
    }
    printf("%lld %lld", step, res);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    Process();
    return 0;
}

