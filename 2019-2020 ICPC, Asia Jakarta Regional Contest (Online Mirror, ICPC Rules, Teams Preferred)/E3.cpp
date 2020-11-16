#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;

int n;
ll l,r,k,a[100005];
vector<int> E[100005];
vector<ll> V[100005];

inline void add(int x,int y,ll z)
{
	E[x].push_back(y);
	V[x].push_back(z);
}

ll dis[100005];
bool vis[100005];
int cnt[100005];

bool flg=0;
void have(int s)
{
	if(flg) return;
	vis[s]=1;
	for(int i=0;i<E[s].size();++i)
	{
		int e=E[s][i];
		ll v=V[s][i];
		if(dis[e]>dis[s]+v)
		{
			dis[e]=dis[s]+v;
			if(vis[e]) flg=1;
			else have(e);
		}
	}
	vis[s]=0;
}

bool spfa()
{
	for(register int i=1;i<=n;++i) dis[i]=0x3f3f3f3f3f3f3f3f;
	int u,v,num=0;
	ll x=0;
	list<int> q;
	dis[0]=0;
	vis[0]=1;
	cnt[0]=0;
	q.push_back(0);
	num++;
	while(!q.empty())
	{
		register int f=q.front();
		q.pop_front();
		num--;
		x-=dis[f];
		while(num&&dis[f]>x/num)
		{
			q.push_back(f);
			f=q.front();
			q.pop_front();
		}
		vis[f]=0;
		for(register int i=0;i<E[f].size();++i)
		{
			register int e=E[f][i];
			register int v=V[f][i];
			if(dis[e]>dis[f]+v)
			{
				dis[e]=dis[f]+v;
				cnt[e]=cnt[f]+1;
				if(cnt[e]>n) return 1;
				if(!vis[e])
				{
					vis[e]=1;
					if(!q.empty()&&dis[e]>=dis[q.front()])
						q.push_back(e);
					else q.push_front(e);
					num++;
					x+=dis[e];
				}
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d%lld%lld%lld",&n,&l,&r,&k);
	for(register int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(register int i=1;i<n;++i)
	{
		if(a[i]>a[i+1])
		{
			add(i,i+1,k);
			add(i+1,i,-1);
		}
		else if(a[i]<a[i+1])
		{
			add(i+1,i,k);
			add(i,i+1,-1);
		}
		else if(a[i]==a[i+1])
		{
			add(i+1,i,0ll);
			add(i,i+1,0ll);
		}
	}
	for(register int i=1;i<=n;++i) add(i,0,r),add(0,i,-l);//
	//if(spfa()) return puts("-1"),0;
	for(register int i=1;i<=n;++i) dis[i]=0x3f3f3f3f3f3f3f3f;
	have(0);
	if(flg) return puts("-1"),0;
	for(register int i=1;i<=n;++i) printf("%lld ",-dis[i]);
	return 0;
}
/*
16 1 10 10
1 3 5 6 7 8 9 10 3 7 8 9 1 11 12 13
*/
