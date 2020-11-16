#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
struct node
{
	int a,b;
}o[100005];

bool cmp(node a,node b)
{
	if(a.a!=b.a) return a.a>b.a;
	else return a.b>b.b;
}
int mx[100005];

signed main()
{
	scanf("%lld",&n);
	int M=0.0;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&o[i].a,&o[i].b);
		M=max(M,o[i].a*o[i].b);
		if(o[i].a>o[i].b) swap(o[i].a,o[i].b);
	}
	int ans=M;
	sort(o+1,o+1+n,cmp);
	for(int i=1;i<=n;++i) mx[i]=max(mx[i-1],o[i].b);
	for(int i=1;i<=n;++i)
		ans=max(ans,2*o[i].a*min(o[i].b,mx[i-1]));
	if(ans&1) printf("%lld.5",ans/2);
	else printf("%lld.0",ans/2);
	return 0;
}
/*
3
1 100
1 100
2 7

3
1 101
2 80
3 9
*/
