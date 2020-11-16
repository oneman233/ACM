#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,ans,vis[100],x[100],y[100],qaq;
map<long double,int> mp;

void dfs(int now)
{
	if(now==n)
	{
		int tmp=0;
		for(auto &p:mp) tmp+=p.second*(p.second-1)/2;
		ans=max(ans,tmp+qaq*(qaq-1)/2);
		return;
	}
	if(vis[now])
	{ 
		dfs(now+1);
		return;
	}
	vis[now]=1;
	for(int i=now+1;i<n;i++)
	{
		if(!vis[i]) 
		{
			vis[i]=1;
			if(x[now]==x[i])
			{
				qaq++;
				dfs(now+1);
				qaq--;
			}
			else
			{
				long double k=(long double)(y[i]-y[now])/(x[i]-x[now]);
				mp[k]++;
				dfs(now+1);
				mp[k]--;
			}
			vis[i]=0;
		}
	}
	vis[now]=0;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	dfs(0);
	printf("%d",ans);
	return 0;
}
