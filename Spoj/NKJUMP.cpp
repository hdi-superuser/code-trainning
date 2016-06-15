#include<iostream>
#include<algorithm>
using namespace std;
 
const int maxn=1005;
int n,a[maxn],f[maxn];
 
void Init()
{
	//freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
 
int Binary_Search(int x)
{
	int l=1, r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]==x) return mid;
		if(a[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return -1;
}
void Solve()
{
	sort(a+1,a+n+1);
	int res=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		{
			int vitri=Binary_Search(a[i]-a[j]);
			if(vitri>=1)
			{
				if(2*a[j]!=a[i])				
					if(f[j]+1>f[i]) f[i]=f[j]+1;
				if(2*a[j]==a[i])
					if(a[vitri+1]==a[vitri] || a[vitri-1]==a[vitri])
						if(f[j]+1>f[i]) f[i]=f[j]+1;
			}
		}
		if(f[i]>res) res=f[i];
	}
	cout<<res;
}
 
int main()
{
	Init();
	Solve();
}