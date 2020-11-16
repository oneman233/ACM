#include <bits/stdc++.h>
using namespace std;
int n,c[200005],cnt[10000006],fa[10000006],l[10000006];
map<int,int>h[200005];
vector<pair<int,int>>f[200005];
vector<pair<int,int>>ans[10000006];
void dfs(int id,int k,int now,int t)
{
	if(ans[t].size()>=cnt[t])return;
	if(k>=f[id].size())
	{
		ans[t].push_back({now,t/now});
		return;
	}
	int nn=now;
	for(int i=0;i<=f[id][k].second;i++)
		dfs(id,k+1,nn,t),nn*=f[id][k].first;
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",c+i),cnt[c[i]]++;
	for(int i=1;i<=n;i++)
		if(!fa[c[i]])
		{
			int t=c[i];
			for(int j=2;j*j<=t;j++)
				while(t%j==0)
					h[i][j]++,t/=j;
			if(t>1)
				h[i][t]++;
			int all=1;
			for(auto &p:h[i])
				all*=(p.second+1),f[i].push_back(p);
			//printf("%d %d %d\n",c[i],all,cnt[c[i]]);
			if(cnt[c[i]]>all)
				return !printf("NO");
			fa[c[i]]=i;
		}
	for(int i=1;i<=n;i++)
		if(fa[c[i]]==i)
			dfs(i,0,1,c[i]);
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d %d\n",ans[c[i]][l[c[i]]].first,ans[c[i]][l[c[i]]].second),++l[c[i]];
	return 0;
}
