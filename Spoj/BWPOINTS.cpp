#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, bool> data;

bool comp(data p, data q){
    return p.first < q.first;
}

int main(){
    int n;
    vector < pair <int, bool> > a;
    //freopen("BWPOINTS.INP", "r", stdin);
    //freopen("BWPOINTS.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        a.push_back(make_pair(x, true));
    }
    for (int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        a.push_back(make_pair(x, false));
    }
    sort(a.begin(), a.end(), comp);
    int res = 0;
    int i = 1;
    while (i < 2*n){
        if (a[i].second != a[i-1].second){
            i += 2;
            res++;
        }
        else i++;
    }
    printf("%d", res);
    return 0;
}

