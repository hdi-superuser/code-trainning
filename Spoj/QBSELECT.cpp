#include <stdio.h>
#include <algorithm>

#define ll long long
#define maxN 10001
#define minC -200000000

using namespace std;

int n;
int a[5][maxN], f[16][maxN], fr[9][9];
bool flag = false;

int getbit(int k, int x){
    return (x >> (k-1)) & 1;
}

void inp(){
    int inmax = minC;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
            inmax = max(inmax, a[i][j]);
        }
    if (inmax < 0){
        printf("%d", inmax);
        flag = true;
    }
}

int ok(int x, int y){
    int bit[5], elsebit[5];
    for (int v = 1; v <= 4; v++) bit[v] = getbit(v, x);
    for (int v = 1; v <= 4; v++) elsebit[v] = getbit(v, y);
    for (int v = 1; v <= 4; v++)
        if ((bit[v] & elsebit[v]) == 1) return 0;
    return 1;
}

int value(int x, int y){
    int bit[5], sum = 0;
    for (int v = 1; v <= 4; v++) bit[v] = getbit(v, x);
    for (int v = 1; v <= 4; v++)
        if (bit[v] == 1) sum += a[v][y];
    return sum;
}

int bitmask(){
    int d[] = {0, 1, 2, 4, 5, 8, 9, 10}, res = minC;
    for (int i = 0; i <= 8; i++)
        for (int j = 0; j <= 8; j++) fr[i][j] = ok(d[i], d[j]);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 8; j++){
            int t = minC;
            for (int k = 0; k <= 8; k++)
                if (fr[j][k] == 1 && f[k][i-1] > t) t = f[k][i-1];
            f[j][i] = t + value(d[j], i);
        }
    for (int i = 0; i <= 8; i++) res = max(res, f[i][n]);
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
    	freopen("SELECT.INP", "r", stdin);
    	freopen("SELECT.OUT", "w", stdout);
    #endif
    scanf("%d", &n);
    inp();
    if (flag) return 0;
    printf("%d", bitmask());
    return 0;
}

