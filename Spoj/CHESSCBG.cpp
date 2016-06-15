#include <cstdio>
#include <iostream>
#include <bitset>
#include <queue>
using namespace std;
#define SIZE 16
typedef bitset<SIZE> BS;
BS S, F;
int d[] = {-4, 1, 4, -1};
int m[65536] = {0};
void input(BS &t)
{
    string line;
    int k = 0;
    for(int i=0; i<4; i++)
    {
        getline(cin, line);
        for(int j=0; j<4; j++)
        {
            t[k] = line[j] - '0';
            k++;
        }
    }
}
bool finish(BS t)
{
    for(int i=0; i<SIZE; i++)
        if(t[i] != F[i])
            return 0;
    return 1;
}
int main()
{
    //freopen("chesscbg.inp", "r", stdin);
    //freopen("chesscbg.out", "w", stdout);
    queue<BS> q;
    input(S);
    input(F);
    q.push(S);
    m[S.to_ulong()] = 1;
    BS t;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        if(finish(t))
            break;
        for(int i=0; i<SIZE; i++)
            if(t[i]==1)
	                for(int j=0; j<4; j++)
                {
                    if((i%4==0) && d[j]==-1) continue;
                    if((i%4==3) && d[j]==1) continue;
                    int u = i+d[j];
                    if(u>=0 && u<SIZE && t[u]==0)
                    {
                        int z = t.to_ulong();
                        t.flip(u);
                        t.flip(i);
                        if(m[t.to_ulong()]==0)
                        {
                            q.push(t);
                            m[t.to_ulong()] = m[z]+1;
                        }
                        t.flip(u);
                        t.flip(i);
                    }
                } 
    }
    cout<<m[t.to_ulong()]-1<<endl;
    return 0;
}