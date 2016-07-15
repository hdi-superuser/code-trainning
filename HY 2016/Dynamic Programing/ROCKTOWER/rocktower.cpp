/***************************************************************************/
/**********************  NGUYEN VAN HIEU  **********************************/
/***************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define maxn 5003
#define maxc 1000000003

using namespace std;

struct rock
{
    int dai, rong, cao, id;
    rock(){};
    rock(int _d, int _r, int _c, int _id):dai(_d), rong(_r), cao(_c), id(_id){};
};

int n,kq;
rock a[maxn];
int d[maxn], tr[maxn];
int luu[maxn];


void nhap()
{
    int x1,x2,x3;
    cin >> n;
    FOR(i,1,n)
    {
        cin >> x1 >> x2 >> x3;
        if (x1 > x2) swap(x1,x2);
        if (x1 > x3) swap(x1,x3);
        if (x2 > x3) swap(x2,x3);
        a[i] = rock(x3,x2,x1,i);
    }
}

bool sosanh(rock p, rock q)
{
    return (p.dai*p.rong > q.dai*q.rong);
}

bool lonhon(rock p, rock q)
{
    return ((p.dai >= q.dai) && (p.rong >= q.rong));
}


void chuanbi()
{
    a[0] = rock(1000,1000,1000,0);
    d[0] = 0;
    sort(a+1,a+n+1,sosanh);
}

void xuli()
{
    FOR(i,1,n)
        FOR(j,0,i-1)
            if (lonhon(a[j],a[i]))
                if (d[i] < d[j] + a[i].cao)
                {
                    d[i] = d[j] + a[i].cao;
                    tr[i] = j;
                }
}

void inra()
{
    int vtmax = 1;
    FOR(i,1,n)
        if (d[vtmax] < d[i]) vtmax = i;

    cout << d[vtmax] << endl;
    int dem = 0;
    while (vtmax)
    {
        luu[++dem] = vtmax;
        vtmax = tr[vtmax];
    }
    cout << dem << endl;
    FORD(i,dem,1)
    {
        int u = luu[i];
        cout << a[u]. id << " " << a[u].rong << " " << a[u].dai << " " << a[u].cao << endl;
    }
}

int main()
{
	freopen("rocktower.inp", "r", stdin);
	freopen("rocktower.out", "w", stdout);
    nhap();
    chuanbi();
    xuli();
    inra();
    return 0;
}
