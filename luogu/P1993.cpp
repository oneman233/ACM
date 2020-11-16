#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> e[10005],v[10005];

void add(int x,int y,int z)
{
	e[x].push_back(y);
	v[x].push_back(z);
}

int dis[10005],cnt[10005],vis[10005];
bool spfa()
{
	for(int i=1;i<=n;++i) dis[i]=0x3f3f3f3f;
	queue<int> q;
	vis[0]=1;
	dis[0]=0;
	cnt[0]=1;
	q.push(0);
	while(!q.empty())
	{
		int f=q.front();q.pop();
		vis[f]=0;
		for(int i=0;i<e[f].size();++i)
		{
			int y=e[f][i];
			if(dis[y]>dis[f]+v[f][i])
			{
				dis[y]=dis[f]+v[f][i];
				if(!vis[y])
				{
					vis[y]=1;
					q.push(y);
					cnt[y]=cnt[f]+1;
					if(cnt[y]>n)
						return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,a,b,c;
		scanf("%d%d%d",&x,&a,&b);
		if(x==1)
		{
			scanf("%d",&c);
			add(a,b,-c);
		}
		else if(x==2)
		{
			scanf("%d",&c);
			add(b,a,c);
		}
		else if(x==3)
		{
			add(a,b,0);
			add(b,a,0);
		}
	}
	for(int i=1;i<=n;++i) add(0,i,0);
	if(spfa()) puts("No");
	else puts("Yes");
	return 0;
}
