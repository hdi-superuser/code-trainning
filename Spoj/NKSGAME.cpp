#include <stdio.h>
#include <algorithm>

#define maxN 100001
#define maxint 2000000000

using namespace std;

int main(){
    //freopen("SGAME.INP", "r", stdin);
    //freopen("SGAME.OUT", "w", stdout);
    int n, a[maxN], b[maxN];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    int k = 0, i = 1, j = n;
    int res = maxint;
    while ( i <= n && j >= 1 ){
        k = a[i]+b[j];
        if (k == 0){
            printf("0");
            return 0;
        }
        res = min(res, abs(k));
        if (k < 0) i++;
        else j--;
    }
    printf("%d", res);
    return 0;
}

