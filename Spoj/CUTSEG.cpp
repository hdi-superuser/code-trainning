#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>

#define file "CUTSEG"
#define maxN 200

using namespace std;

int N, cnt, a[maxN], len[maxN], color[maxN], F[maxN][maxN][maxN];
char s[maxN];

void inp(){
    scanf("%d", &N);
    scanf("%s", s);
    for (int i = 0; i < N; i++) a[i] = s[i]-48;
}

void init(){
    cnt = 0;
    len[cnt] = 1;
    color[cnt] = a[0];
    int temp = a[0];
    for (int i = 1; i < N; i++)
        if (a[i] == temp) len[cnt]++;
        else{
            len[++cnt] = 1;
            color[cnt] = temp = a[i];
        }
    cnt++;
    memset(F, -1, sizeof(F));
}

int Dynamic_Programing(int low, int high, int key){
    if (low > high) return 0;
    if (F[low][high][key] != -1) return F[low][high][key];
    int res = Dynamic_Programing(low, high-1, 0) + (len[high] + key) * (len[high] + key);
    for (int i = high-1; i >= low; i--)
        if (color[i] == color[high])
            res = max(res, Dynamic_Programing(low, i, len[high]+key) + Dynamic_Programing(i+1, high-1, 0));
    return F[low][high][key] = res;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    inp();
    init();
    printf("%d", Dynamic_Programing(0, cnt - 1, 0));
    return 0;
}
