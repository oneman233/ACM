#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n,x,y;
vector<int> e[N];
int a[N],b[N];
int now=1e9-1;
map<int,bool> mp;

void dfs(int x,int f)
{
	if(a[x]==0||b[x]==0)
	{
		if(a[x]==0)
		{
			if(mp[a[f]]&&mp[b[f]])
			{
				a[x]=now;
				now--;
			}
			else if(!mp[a[f]])
			{
				a[x]=a[f];
				mp[a[f]]=1;
			}
			else if(!mp[b[f]])
			{
				a[x]=b[f];
				mp[b[f]]=1;
			}
		}
		if(b[x]==0)
		{
			if(mp[a[f]]&&mp[b[f]])
			{
				b[x]=now;
				now--;
			}
			else if(!mp[a[f]])
			{
				b[x]=a[f];
				mp[a[f]]=1;
			}
			else if(!mp[b[f]])
			{
				b[x]=b[f];
				mp[b[f]]=1;
			}
		}
	}
	set<int> s;
	s.insert(a[x]),s.insert(b[x]),s.insert(a[f]),s.insert(b[f]);
	if((int)s.size()==4)
	{
		a[x]=a[f];
	}
	for(auto y:e[x])
	{
		if(y==f) continue;
		dfs(y,x);
	}
}

int d[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;++i)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
		d[x]++,d[y]++;
	}
	int s=-1;
	for(int i=1;i<=n;++i)
	{
		if(d[i]==1)
		{
			s=i;
			break;
		}
	}
	a[s]=now;
	now--;
	b[s]=now;
	now--;
	dfs(s,0);
	for(int i=1;i<=n;++i)
		printf("%d %d\n",a[i],b[i]);
	return 0;	
}
/*
4
1 2
2 3
2 4
*/
