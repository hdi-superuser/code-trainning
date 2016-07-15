#include <bits/stdc++.h>
#define filein(t) freopen(t, "r", stdin)
#define fileout(t) freopen(t, "w", stdout)
#define f first
#define s second
#define cs 137
#define ll long long
#define mp make_pair
#define N 105
#define ln 1e16
#define oo 10007
#define Pa pair < int, int >
#define Pi pair < int, Pa >

using namespace std;

int n, DP[N][N][N], Pre[2*N], Next[2*N], Mod[2*N], Cnt[N][N][N];
string S;

void Plus(int &x, int y)
{
    x += y;
    x %= oo;
}

int Pow(int x, int y)
{
    if(y == 0)  return 1;
    ll u = Pow(x, y/2);
    u = u * u % oo;
    if(y % 2)   u = u * x % oo;
    return u;
}

int main()
{
    filein("CAKES.inp");    fileout("CAKES.out");
    cin >> n;
    cin >> S;
    for(int i=0; i<2*n; i++)
    {
        Pre[i] = (i - 1 + n) % n;
        Next[i] = (i + 1) % n;
    }
    for(int i=0; i<2*n; i++)
        Mod[i] = i % n;
    for(int i=0; i<n; i++)
        DP[i][i][S[i]-'a'] = 1;
    Cnt[0][0][0] = 1;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
            {
                if(i > 0)
                    Plus(Cnt[i][j][k], Cnt[i-1][j][k]);
                if(j > 0)
                    Plus(Cnt[i][j][k], Cnt[i][j-1][k]);
                if(k > 0)
                    Plus(Cnt[i][j][k], Cnt[i][j][k-1]);
            }
    int Si;
    for(Si=3; Si<=n; Si+=2)
        for(int i=0; i<n; i++)
        {
            int j = (i + Si - 1);
            for(int p=i; p<j; p++)
                for(int q=p+2; q<=j; q++)
                {
                    int Sum = 0;
                    for(int K=0; K<26; K++)
                        Plus(Sum , DP[i][Mod[p]][K] * DP[Mod[q]][Mod[j]][K]);
                    int Num = Cnt[(p-i)/2][(q-2-p)/2][(j-q)/2];
                    if(Sum == 0)    continue;
                    for(int K=0; K<26; K++)
                        Plus(DP[i][Mod[j]][K] , (ll)DP[Next[p]][Pre[q]][K] * Sum * Num % oo);
                }
        }
    Si -= 2;
    int ans = 0;
    if(n % 2 == 1)
    {
        for(int i=0; i<n; i++)
        {
            int j = (i + Si - 1);
            for(int K=0; K<26; K++)
            {
                Plus(ans, DP[i][Mod[j]][K]);
            }
        }
        cout << ans;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            int j = (i + n - 1);
            for(int p=i; p<j; p++)
            {
                int Sum1 = 0, Sum2 = 0;
                for(int K=0; K<26; K++)
                    Plus(Sum1 , DP[i][Mod[p]][K]);
                for(int K=0; K<26; K++)
                    Plus(Sum2 , DP[Mod[p+1]][Mod[j]][K]);
                int Num = Cnt[(p-i)/2][(j-p-1)/2][0];
                Plus(ans, (ll)Sum1 * Sum2 * Num % oo);
            }
        }
        cout << ans * Pow(2, oo-2) % oo << endl;
    }
}
