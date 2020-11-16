#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=10005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m,s,t,tot,dis[MAXN],cur[MAXN];
struct edge
{
    int to,cap,rev;
    edge(){}
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
};
vector<edge> E[MAXN];

inline void add_edge(int x,int y,int f)
{
    E[x].emplace_back(y,f,E[y].size());
    E[y].emplace_back(x,0,E[x].size()-1);
}

int bfs()
{
    for(int i=0;i<=n;i++) dis[i]=0x3f3f3f3f;
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=0;i<E[now].size();i++)
        {
            edge &e=E[now][i];
            if(dis[e.to]>dis[now]+1&&e.cap)
            {
                dis[e.to]=dis[now]+1;
                if(e.to==t) return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

ll dfs(int now,ll flow)
{
    if(now==t) return flow;
    ll rest=flow,k;
    for(int i=cur[now];i<E[now].size();i++)
    {
        edge &e=E[now][i];
        if(e.cap&&dis[e.to]==dis[now]+1)
        {
            cur[now]=i;
            k=dfs(e.to,min(rest,(long long)e.cap));
            e.cap-=k;
            E[e.to][e.rev].cap+=k;
            rest-=k;
        }
    }
    return flow-rest;
}

ll dinic()
{
    ll ret=0,delta;
    while(bfs())
    {
        for(int i=0;i<=n;i++) cur[i]=0;
        while(delta=dfs(s,inf)) ret+=delta;
    }
    return ret;
}

int x,y,A,B;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char mp[55][55];

int ha(int i,int j){return (i-1)*y+j;}
bool ok(int i,int j){if(i<1||i>x||j<1||j>y)return 0;return 1;}

int main()
{
	scanf("%d%d%d%d",&x,&y,&A,&B);
	s=0,t=x*y+1,n=x*y+1;
	for(int i=1;i<=x;++i)
	{
		scanf("%s",mp[i]+1);
		for(int j=1;j<=y;++j)
		{
			if(mp[i][j]=='.') add_edge(s,ha(i,j),B);
			else add_edge(ha(i,j),t,B);
		}
	}
	for(int i=1;i<=x;++i)
	{
		for(int j=1;j<=y;++j)
		{
			for(int k=0;k<4;++k)
			{
				int xx=i+dx[k],yy=j+dy[k];
				if(ok(xx,yy))
					add_edge(ha(i,j),ha(xx,yy),A);
			}
		}
	}
	printf("%lld",dinic());
	return 0;
}
/*
5 4 1000 2000
...#
#..#
...#
##..
###.
*/
