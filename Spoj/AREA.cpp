#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long       ll;
typedef int64_t         ll;
typedef double          real;
 
//-------------------------------------//
 
struct Node {
    int x, y1, y2, type;
};
 
struct Tree {
    int len, cnt;
};
 
//-----------------------------------//
const int   N = 30010;
int         n, x0; // x0 la vi tri cuoi cung dang xet
ll          res;
Node        a[N];
Tree        t[5*N]; // luu ve phuong dien do dai , khong phai toa do (*)
//------------------------------------//
 
bool cmp(const Node u, const Node v)
{
    return (u.x < v.x or (u.x == v.x and u.type < v.type));
}
 
void update(int k, int l, int r, int L, int R, int type)
{
    if (r < L or R < l) return ;
    if (L <= l and r <= R) {
        t[k].cnt += type;
        if (type == 1)          // them hcn nen bao phu ca canh nay
            t[k].len = (r-l+1); // chang han l = 5, r = 8 thi t[k].len = 4 do (5,6,7,8)
        else  {                 // truong hop xoa thi phai lay thong tin tu node con
            if (t[k].cnt == 0)
                t[k].len = t[k*2].len + t[k*2+1].len;
        }
        return ;
    }
    int mid = (l+r)/2;
    update(k*2,l,mid,L,R,type);
    update(k*2+1,mid+1,r,L,R,type);
    if (t[k].cnt == 0)
        t[k].len = t[k*2].len + t[k*2+1].len;
}
 
int main()
{
    //freopen("INP.INP","r",stdin);
    //freopen("OUT.OUT","w",stdout);
 
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
        a[i].x = x1;
        a[i+n].x = x2;
        a[i].y1 = a[i+n].y1 = y1;
        a[i].y2 = a[i+n].y2 = y2;
        a[i].type = 1;
        a[i+n].type = -1;
    }
 
    n *= 2;
    sort(a+1,a+n+1,cmp);
 
    //for (int i=1;i<=n;i++)
    //    printf("%d %d %d %d\n", a[i].x, a[i].y1, a[i].y2, a[i].type);
 
    for (int i=1;i<=n;i++) {
        //cout << (a[i].x-x0)*(t[1].len) << endl;
        res += (a[i].x - x0) * (t[1].len);
        x0 = a[i].x;
        update(1,0,N, a[i].y1, a[i].y2-1, a[i].type); // a[i].y2-1 la do (*)
    }
    cout << res;
 
    return 0;
}