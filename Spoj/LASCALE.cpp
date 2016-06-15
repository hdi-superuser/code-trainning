#include <bits/stdc++.h>

using namespace std; 

typedef pair<int,int> ii;
typedef long long ll; 
typedef long double ld;
typedef unsigned long long llu;

#define X  first
#define Y  second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)
#define EL printf("\n")
#define debug 1

const double pi = acos(-1.0);
ll  n, tr[20], ph[20], nt, np, a[20];
 
int main() {
    scanf("%I64d",&n);
    a[0] = 1;
    for (int i=1;i<=18;i++) a[i] = a[i-1]*3;
    for (int i=0;n>0;n/=3,i++) ph[i] = n%3;
    for (int i=0;i<=17;i++) {
        if (ph[i] == 1) np++; else
        if (ph[i] == 2) nt++, tr[i] = 1, ph[i+1]++;  else
        if (ph[i] == 3) ph[i+1]++;
    }
 
    printf("%I64d ", nt);
    for (int i=0;i<=18;i++)
        if (tr[i] == 1) printf("%I64d ", a[i]);
 
    EL;

    printf("%I64d ", np);
    for (int i=0;i<=18;i++)
        if (ph[i] == 1) printf("%I64d ", a[i]);
 
    return 0;
}