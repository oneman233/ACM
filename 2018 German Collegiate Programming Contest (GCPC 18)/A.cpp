#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e6+5;
const int mv[4][2]={0,1,0,-1,1,0,-1,0};
int n,m,dep[MAXN],qq,ua[MAXN],ans[MAXN],idd[MAXN];
bool vis[MAXN];
vector<int> e[MAXN],q[MAXN],id[MAXN];
unordered_set<int> sb[MAXN];
char s[2005][3005];

int _find(int x)
{
	if(x!=ua[x]) ua[x]=_find(ua[x]);
	return ua[x];
}

inline void _merge(int x,int y)
{
	x=_find(x),y=_find(y);
	if(x!=y) ua[x]=y;
}

void tarjan(int u,int fa)
{
	vis[u]=1;
	dep[u]=dep[fa]+1;
	for(auto v:e[u])
		if(!vis[v]) tarjan(v,u),_merge(v,u);
	for(int i=0;i<q[u].size();i++)
	{
		int v=q[u][i];
		int k=id[u][i];
		if(vis[v]&&ans[k]==0) ans[k]=_find(v);
	}
}

inline int get(int x,int y)
{
	return (x-1)*m+y-1;
}

inline int dis(int qaq)
{
	return dep[idd[qaq]]+dep[idd[qaq-1]]-2*dep[ans[qaq]];
}

void debug(int now,int fa)
{
	vis[now]=1;
	for(int to:e[now])
	{
		if(to==fa) continue;
		printf("!!! %d %d %d\n",now,to,vis[to]);
		//assert(!vis[to]);
		debug(to,now);
	}
}

int main()
{
	scanf("%d%d ",&n,&m);
	for(int i=0;i<=n;i++)
		scanf("%[^\n]%*c",s[i]+1);
	for(int i=0;i<MAXN;i++) ua[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=2*m;j++)
		{
			if(j&1) continue;
			for(int k=0;k<4;k++)
			{
				int dx=i+mv[k][0],dy=j+mv[k][1];
				if(dx<1||dx>n||dy<=1||dy>2*m) continue;
				if(k==0||k==1)
					if(s[dx][dy]=='|') continue;
				if(k==2&&s[i][j]=='_') continue;
				if(k==3&&s[dx][dy]=='_') continue;
				int x,y,tx,ty,a,b;
				x=i,tx=dx;
				y=j/2,ty=(j+2*mv[k][1])/2;
				a=get(x,y),b=get(tx,ty);
				if(sb[a].find(b)==sb[a].end())
					e[a].push_back(b),sb[a].insert(b);
				if(sb[b].find(a)==sb[b].end())
					e[a].push_back(
				e[get(tx,ty)].push_back(get(x,y));
				printf("! %d %d \n",get(x,y),get(tx,ty));
			}
		}
	scanf("%d",&qq);
	for(int i=0,x,y;i<qq;i++)
	{		
		scanf("%d%d",&x,&y);
		idd[i]=get(x,y);
	}
	for(int i=1;i<qq;i++)
	{
		q[idd[i]].push_back(idd[i-1]);
		q[idd[i-1]].push_back(idd[i]);
		id[idd[i]].push_back(i);
		id[idd[i-1]].push_back(i);
	}
	debug(idd[0],idd[0]);
	memset(vis,0,sizeof(vis));
	tarjan(idd[0],idd[0]);
	int sum=0;
	for(int i=1;i<qq;i++) sum+=dis(i);
	printf("%d",sum);
	return 0;
}

/*
2 6
 _ _ _ _ _ _ 
|  _ _ _ _ _|
|_ _ _ _ _ _|
5
1 5
1 1
1 6
1 1
1 5

5 5
 _ _ _ _ _ 
|_ _  |_  |
|  _| |  _|
| |_   _| |
|    _ _  |
|_|_ _ _|_|
7
4 4
1 4
3 1
4 5
1 2
2 2
5 4
*/

