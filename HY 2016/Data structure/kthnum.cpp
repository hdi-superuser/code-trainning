#include<cstdio>
 2 #include<algorithm>
 3 #include<cstdlib>
 4 using namespace std;
 5 const int N=1000;
 6 int a[N],b[N],ls[N],rs[N],sum[N],root[N];
 7 int t,sz,n,m;
 8 void build(int l,int r,int x,int &y,int v){
 9     y=++sz;
10     ls[y]=ls[x]; rs[y]=rs[x];
11     sum[y]=sum[x]+1;
12     if (l==r) return;
13     int mid=(l+r)>>1;
14     if (v>mid) build(mid+1,r,rs[x],rs[y],v);
15     else build(l,mid,ls[x],ls[y],v);
16 }
17 
18 int query(int L,int R,int w){
19     int l=1,r=t,mid=(l+r)>>1;
20     int x=root[L-1],y=root[R];
21     while (l!=r){
22         if (sum[ls[y]]-sum[ls[x]]>=w){r=mid;x=ls[x];y=ls[y];mid=(l+r)>>1;}
23         else {w-=sum[ls[y]];w+=sum[ls[x]];l=mid+1;x=rs[x];y=rs[y];mid=(l+r)>>1;}
24     }
25     return l;
26 }
27 
28 int main(){
29     scanf("%d%d",&n,&m);
30     for (int i=1;i<=n;i++){scanf("%d",&a[i]);b[i]=a[i];}
31     sort(b+1,b+n+1);
32     t=unique(b+1,b+n+1)-b-1;
33     for (int i=1;i<=n;i++){
34         int w=lower_bound(b+1,b+t+1,a[i])-b;
35         build(1,t,root[i-1],root[i],w);
36     }
37     int l,r,w;
38     for (int i=1;i<=m;i++){
39         scanf("%d%d%d",&l,&r,&w);
40         printf("%d\n",b[query(l,r,w)]);
41     }
42 }
