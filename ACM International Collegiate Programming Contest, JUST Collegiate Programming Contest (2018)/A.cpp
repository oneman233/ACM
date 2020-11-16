#include <bits/stdc++.h>
using namespace std;

map<int,int> cnt;
int n,q,op,x,y,a[100005],sum;

void solve()
{
	sum=0;
	cnt.clear();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i),cnt[a[i]]++;
		if(cnt[a[i]]==1&&a[i]) sum++;
	}
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			cnt[a[x]]--;
			if(cnt[a[x]]==0&&a[x]) sum--;
			a[x]=y;
			cnt[a[x]]++;
			if(cnt[a[x]]==1&&a[x]) sum++;
		}
		else
		{
			printf("%d\n",sum);
		}
	}
}

int main()
{
	int _;
	scanf("%d",&_);
	while(_--) solve();
	return 0;
}
