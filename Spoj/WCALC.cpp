#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
long res;
ll tmp,n,b,m;

int main()
{
	scanf("%lld%lld",&b,&n);
	for (m=1; m<2*n; ++m)
	{
		ll tmp=b*m*(2LL*n-m);
		if (tmp%(1LL*n*n)==0LL)
		{
			tmp/=n*n;
			if (tmp>0LL) res++;
		}
	}
	printf("%ld",res);
	return 0;
}


