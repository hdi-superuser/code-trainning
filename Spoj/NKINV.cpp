#include <stdio.h>

#define maxN 100001

using namespace std;

int tree[maxN];
int n, ans = 0;

void update(int x){
    while (x > 0){
        tree[x]++;
        x -= x & (-x);
    }
}

void get(int x){
    while (x < maxN){
        ans += tree[x];
        x += x & (-x);
    }
}

int main(){
    //freopen("NKINV.INP", "r", stdin);
    //freopen("NKINV.OUT", "w", stdout);
    scanf("%d", &n);
    for (int k = 1; k <= n; k++){
        int temp;
        scanf("%d", &temp);
        get(temp+1);
        update(temp);
    }
    printf("%d", ans);
    return 0;
}

