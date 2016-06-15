#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
 
using namespace std;
 
struct qwe
{
    int z1, s1, m1, z2, s2, m2;
};
 
struct wer
{
    int z, s, m, k;
};
 
int     k, z, s, m, z0, s0, m0, n, l, r, f[10][10][10], ans, t; 
int     dd[10][10][10];

qwe     a[1000];
wer     st[1000], res[100];
 
void push(int z, int s, int m, int z3, int s3, int m3)
{
    r++;
    st[r].z = z3;
    st[r].s = s3;
    st[r].m = m3;
    f[z3][s3][m3] = f[z][s][m] + 1;
    dd[z3][s3][m3] = 1;
}
 
bool compare(const wer u, const wer v)
{
    if (u.z < v.z) return true;
    if (u.z == v.z and u.s < v.s) return true;
    if (u.z == v.z and u.s == v.s and u.m < v.m) return true;
    return false;
}
 
void xuat()
{
    if (ans == 0) printf("-1");
    else {
        printf("%d\n",ans);
        sort(res+1,res+ans+1,compare);
        for (int i=1;i<=ans;i++)
            printf("%d %d %d %d\n", res[i].z,res[i].s,res[i].m,
res[i].k);
    }
}
 
void luu(int z, int s, int m)
{
    ans++;
    res[ans].z = z;
    res[ans].s = s;
    res[ans].m = m;
    res[ans].k = f[z][s][m];
}
 
int main()
{
    scanf("%d",&k);
    scanf("%d%d%d%d%d%d",&z,&s,&m,&z0,&s0,&m0);
    while (scanf("%d",&t) != EOF) {
        n++;
        a[n].z1 = t;
        scanf("%d%d%d%d%d",&a[n].s1,&a[n].m1,&a[n].z2,&a[n].s2,
&a[n].m2);
    }
    l = 1;
    r = 1;
    st[1].z = z; st[1].s = s; st[1].m = m;
    while (l <= r) {
        z = st[l].z;
        s = st[l].s;
        m = st[l].m;
        if (z >= z0 and s >= s0 and m >= m0 and f[z][s][m] <= k)
            luu(z,s,m);
        else {
            if (f[z][s][m] > k) break;
            for (int i=1;i<=n;i++) {
                int z3 = z - a[i].z1 + a[i].z2;
                int s3 = s - a[i].s1 + a[i].s2;
                int m3 = m - a[i].m1 + a[i].m2;
                if (z >= a[i].z1 && z3 <= 4 && s >= a[i].s1 && 
s3 <= 4 && m >= a[i].m1 && m3 <= 4 && dd[z3][s3][m3] == 0)
                        push(z,s,m,z3,s3,m3);
            }
        }
        l++;
    }
    xuat();
    return 0;
}