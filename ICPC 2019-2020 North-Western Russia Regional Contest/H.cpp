#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a[200005],s[200005],MAX=-1;
struct query
{
	int id,t;
}q[200005];
int ans[200005];

bool cmp(query a,query b)
{
	return a.t<b.t;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
		MAX=max(MAX,a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&q[i].t);
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp);
	
	return 0;
}
