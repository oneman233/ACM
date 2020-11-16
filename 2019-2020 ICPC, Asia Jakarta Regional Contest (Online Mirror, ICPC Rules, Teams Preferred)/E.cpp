#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll l,r,k,a[100005];
vector<int> E[100005];
vector<ll> V[100005];

void add(int x,int y,ll z)
{
	E[x].push_back(y);
	V[x].push_back(z);
}

ll dis[100005];
bool vis[100005];
int cnt[100005];
bool spfa()
{
	for(int i=1;i<=n;++i) dis[i]=0x3f3f3f3f3f3f3f3f;
	dis[0]=0;
	vis[0]=1;
	cnt[0]=1;
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		vis[f]=0;
		for(int i=0;i<E[f].size();++i)
		{
			int e=E[f][i];
			int v=V[f][i];
			if(dis[e]>dis[f]+v)
			{
				dis[e]=dis[f]+v;
				if(!vis[e])
				{
					vis[e]=1;
					cnt[e]++;
					if(cnt[e]>n) return 1;
					q.push(e);
				}
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d%lld%lld%lld",&n,&l,&r,&k);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<n;++i)
	{
		if(a[i]>a[i+1])
		{
			add(i+1,i,k);
			add(i,i+1,-1);
		}
		else if(a[i]<a[i+1])
		{
			add(i,i+1,k);
			add(i+1,i,-1);
		}
		else if(a[i]==a[i+1])
		{
			add(i,i+1,0ll);
			add(i+1,i,0ll);
		}
	}
	for(int i=1;i<=n;++i) add(0,i,r),add(i,0,-l);//
	if(spfa()) return puts("-1"),0;
	for(int i=1;i<=n;++i) printf("%lld ",dis[i]);
	return 0;
}
/*
16 1 10 10
1 3 5 6 7 8 9 10 3 7 8 9 1 11 12 13
*/
