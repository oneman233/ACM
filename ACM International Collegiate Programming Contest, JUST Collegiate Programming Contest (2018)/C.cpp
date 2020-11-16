#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,pos[100005],a[100005];
ll bit[100005];

void add(int x)
{
	for(;x<=n;x+=x&-x) bit[x]++;
}

ll sum(int x)
{
	ll ret=0;
	for(;x;x-=x&-x) ret+=bit[x];
	return ret;
}

void solve()
{
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),pos[a[i]]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),a[i]=pos[a[i]],bit[i]=0;
	for(int i=n;i>=1;i--)
	{
		ans+=sum(a[i]);
		add(a[i]);
	}
	printf("%lld\n",ans);
}


int main()
{
	int _;
	scanf("%d",&_);
	while(_--) solve();
	return 0;
}

/*
2
5
5 4 2 1 3
2 5 4 1 3
4
1 2 3 4
1 2 4 3
*/
