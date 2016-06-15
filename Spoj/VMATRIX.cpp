#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define REP(i,a,b) for( int i=(a),_b=(b);i<_b;++i)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define DEBUGARR(a,n) {cout << #a << " = " ; FOR(_,1,n) cout << a[_] << ' '; cout <<endl;}
#define CHECK printf("OK\n");
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define pb push_back
#define mp make_pair
#define st first
#define nd second

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }


typedef pair< int, int > pii;
typedef long long LL;

//const int MAXINT = 2147483647;
//const LL MAXLL = (long long)9223372036854775807;

int a[1011][1011], b[1011][1011], c[1011][1011], res[1011][1011];
int n;
int nTest;

void solve1() {
    memset(res, 0, sizeof(res));
    FOR(i, 1, n)
    FOR(j, 1, n)
    FOR(k, 1, n)
        res[i][j] = (res[i][j] + a[i][k]*b[k][j])%10;
    FOR(i, 1, n)
    FOR(j, 1, n)
        if (res[i][j] != c[i][j]) {
            printf("NO\n");
            return;
        }
    printf("YES\n");
}

int tmp[1011][2];
int b2[1011][2];
int a2[1011][2];
int c2[1011][2];

bool check() {
    memset(res, 0, sizeof(res));
    memset(b2, 0, sizeof(b2));
    memset(a2, 0, sizeof(a2));
    memset(c2, 0, sizeof(c2));
    FOR(i, 1, 1)
    FOR(j, 1, n)
    FOR(k, 1, n)
        b2[j][i] = (b2[j][i] + b[j][k]*tmp[k][i])%10;
    FOR(i, 1, 1)
    FOR(j, 1, n)
    FOR(k, 1, n)
        a2[j][i] = (a2[j][i] + a[j][k]*b2[k][i])%10;
    FOR(i, 1, 1)
    FOR(j, 1, n) {
        FOR(k, 1, n)
            c2[j][i] = (c2[j][i] + c[j][k]*tmp[k][i])%10;
        if (c2[j][i] != a2[j][i]) return false;
    }
    return true;
}

void solve2() {
    int maxK = 3;
    FOR(k, 1, maxK) {
        FOR(i, 1, n)
            tmp[i][1] = rand()%2;
        if (!check()) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    srand (time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d\n", &nTest);
    FOR(test, 1, nTest) {
        scanf("%d\n", &n);
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                char ch;
                scanf("%c", &ch);
                a[i][j] = ch - '0';
            }
            scanf("\n");
        }
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                char ch;
                scanf("%c", &ch);
                b[i][j] = ch - '0';
            }
            scanf("\n");
        }
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                char ch;
                scanf("%c", &ch);
                c[i][j] = ch - '0';
            }
            scanf("\n");
        }
        if (n <= 100) solve1();
        else solve2();
    }
    return 0;
}