#include <bits/stdc++.h>
using namespace std;

int t,n,m;
vector<int> e[2][200005],v[2][200005];
bool pt[200005];
map<pair<int,int>,bool> mp;

void gao2(int x,int flip)
{
	pt[x]=1;
	for(int i=0;i<e[flip][x].size();++i)
	{
		if(pt[e[flip][x][i]]) continue;
		v[flip][x][i]=1;
		gao2(e[flip][x][i],flip);
	}
}

void gao()
{
	for(int i=1;i<=n;++i) pt[i]=0;
	gao2(1,0);
	for(int i=1;i<=n;++i) pt[i]=0;
	gao2(1,1);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<e[0][i].size();++j)
			if(v[0][i][j]) mp[make_pair(i,e[0][i][j])]=1;
		for(int j=0;j<e[1][i].size();++j)
			if(v[1][i][j]) mp[make_pair(e[1][i][j],i)]=1;
	}
	int cnt=m-2*n;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<e[0][i].size();++j)
		{
			if(cnt==0) return;
			if(!mp[make_pair(i,e[0][i][j])])
				printf("%d %d\n",i,e[0][i][j]),cnt--;
		}
	}
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mp.clear();
		for(int i=1;i<=n;++i)
			for(int j=0;j<=1;++j)
				e[j][i].clear(),v[j][i].clear();
		for(int i=1,x,y;i<=m;++i)
		{
			scanf("%d%d",&x,&y);
			e[0][x].push_back(y);
			e[1][y].push_back(x);
			v[0][x].push_back(0);
			v[1][y].push_back(0);
		}
		gao();
	}
	return 0;
}
