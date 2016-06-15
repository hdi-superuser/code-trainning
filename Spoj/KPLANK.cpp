#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<int> a,l,r;
 
void Init()
{
	scanf("%d",&n);
	a.resize(n+2);	l.resize(n+2);	r.resize(n+2);
	for (int i=1;i<=n;i++)	scanf("%d",&a[i]);
}
 
void Solve()
{
	stack<int> sl;
	sl.push(0);
	for (int i=1;i<=n;i++)
	{
		while(!sl.empty() && a[i]<=a[sl.top()])		sl.pop();
		if(!sl.empty())		l[i]=sl.top();
		sl.push(i);
	}
	stack<int> sr;
	sr.push(n+1);
	for (int i=n;i>0;i--)
	{
		while(!sr.empty() && a[i]<=a[sr.top()])		sr.pop();
		if(!sr.empty())		r[i]=sr.top();
		sr.push(i);
	}
	int res=0;
	for (int i=1;i<=n;i++)
		if(r[i]-l[i]-1 >= a[i])		res=max(res,a[i]);
	printf("%d",res);
}
 
int main()
{
	Init();
	Solve();
}