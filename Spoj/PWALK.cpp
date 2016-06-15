#include <bits/stdc++.h>
using namespace std;
 
int n,q,p1,p2,res;
vector< vector<int> > Ke,L;
vector<bool> Visit;
 
void Init()
{
	scanf("%d%d",&n,&q);
	Ke.resize(n+2);
	L.resize(n+2);
	for (int i=0;i<=n+1;i++)  L[i].resize(n+2);
	int ai,bi,li;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&ai,&bi,&li);
		Ke[ai].push_back(bi);
		Ke[bi].push_back(ai);
		L[ai][bi]=L[bi][ai]=li;
	}
}
 
void Try(int k)
{
	Visit[k]=true;
	for (int i=0;i<Ke[k].size();i++)
	{
		int d=Ke[k][i];
		if(!Visit[d] && d==p2)
		{
			res+=L[k][d];
			printf("%d\n",res);
			res-=L[k][d];
			return;
		}
		if(!Visit[d])
		{
			res+=L[k][d];
			Try(d);
			res-=L[k][d];
		}
	}
}
 
void Solve()
{
	while(q--)
	{
		scanf("%d%d",&p1,&p2);
		res=0;
		Visit.clear();
		Visit.resize(n+2);
		Try(p1);
	}
}
 
int main()
{
	Init();
	Solve();
}