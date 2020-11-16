#include <bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long ll;

int n,m,row[N][N],col[N][N],pre,suf;
char s[N],mp[N][N];
inline int read(){char ch=getchar();int s=0,w=1;while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}return s*w;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}

const int MAXN=1e6+5;
const int mv[2][2]={0,1,1,0};
int dep[MAXN],lg[MAXN],fa[MAXN][32],a[N][N],val[MAXN],q,ua[MAXN];
int mx[MAXN][32],ans[MAXN];
struct edge
{
    int v,x,y;
    edge(){}
    edge(int x,int y,int v):x(x),y(y),v(v){}
};
vector<edge> ee;
vector<int> e[MAXN];
 
inline bool cmp(edge a,edge b){return a.v>b.v;}

int _find(int x)
{
    if(x==ua[x]) return x;
    return ua[x]=_find(ua[x]);
}
 
inline void _merge(int x,int y)
{
    x=_find(x),y=_find(y);
    if(x!=y) ua[x]=y;
}
 
void dfs(int now,int pa)
{
    dep[now]=dep[pa]+1;
    fa[now][0]=pa;
    mx[now][0]=min(val[now],val[pa]);
    for(int i=1;(1<<i)<=dep[now];i++)
        fa[now][i]=fa[fa[now][i-1]][i-1],
        mx[now][i]=min(mx[now][i-1],mx[fa[now][i-1]][i-1]);
    for(auto to:e[now])
        if(to!=pa) dfs(to,now);
}
 
int lca(int x,int y)
{
    int ret=val[x];
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y]) 
        ret=min(ret,mx[x][lg[dep[x]-dep[y]]-1]),
        x=fa[x][lg[dep[x]-dep[y]]-1];
    if(x==y) return ret;
    for(int i=lg[dep[x]]-1;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
        {
            ret=min(ret,mx[x][i]);
            ret=min(ret,mx[y][i]);
            x=fa[x][i],y=fa[y][i];
        }
    ret=min(ret,mx[x][0]);
    ret=min(ret,mx[y][0]);
    return ret;
}

inline int get(int x,int y){return (x-1)*n+y;}

void gao()
{
	for(int i=1;i<=n;++i)
	{
		pre=suf=0;
		for(int j=1;j<=n;++j)
			if(mp[i][j]=='#')
			{
				suf=j;
				break;
			}
		if(suf==0) suf=n+1;
		for(int j=1;j<=n;++j)
		{
			if(suf==j)
			{
				suf++;
				while(suf<=n)
				{
					if(mp[i][suf]=='#') break;
					suf++;
				}
			}
			if(mp[i][j]=='#')
			{
				row[i][j]=0;
				pre=j;
			}
			else row[i][j]=min(j-pre,suf-j)*2-1;
		}
	}
	for(int j=1;j<=n;++j)
	{
		pre=suf=0;
		for(int i=1;i<=n;++i)
			if(mp[i][j]=='#')
			{
				suf=i;
				break;
			}
		if(suf==0) suf=n+1;
		for(int i=1;i<=n;++i)
		{
			if(suf==i)
			{
				suf++;
				while(suf<=n)
				{
					if(mp[suf][j]=='#') break;
					suf++;
				}
			}
			if(mp[i][j]=='#')
			{
				col[i][j]=0;
				pre=i;
			}
			else col[i][j]=min(i-pre,suf-i)*2-1;
		}
	}
}

void gao2(int x)
{
	for(int i=1;i<=n*n;++i) ua[i]=i;
	ee.clear();
	for(int i=1;i<=n*n;++i) e[i].clear();
	if(x==1)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				val[get(i,j)]=min(row[i][j],col[i][j]);
	}
	else if(x==2)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				val[get(i,j)]=col[i][j];
	}
	if(x==1)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				for(int k=0;k<2;++k)
				{
					int dx=i+mv[k][0],dy=j+mv[k][1];
					if(dx==n+1||dy==n+1) continue;
					int v=min(min(row[i][j],col[i][j]),min(row[dx][dy],col[dx][dy]));
					ee.emplace_back(get(i,j),get(dx,dy),v);
				}
	}
	else if(x==2)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				for(int k=0;k<2;++k)
				{
					int dx=i+mv[k][0],dy=j+mv[k][1];
					if(dx==n+1||dy==n+1) continue;
					int v=min(col[i][j],col[dx][dy]);
					ee.emplace_back(get(i,j),get(dx,dy),v);
				}
	}
	sort(ee.begin(),ee.end(),cmp);
	for(auto p:ee)
		if(_find(p.x)!=_find(p.y))
		{
			e[p.x].push_back(p.y),e[p.y].push_back(p.x);
            _merge(p.x,p.y);
		}
	val[0]=0x3f3f3f3f;
	dfs(1,0);
}

const int RHY=3e+5;
int x1[RHY],y1[RHY],x2[RHY],y2[RHY];

int main()
{
	for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	n=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=n;++j)
			mp[i][j]=s[j];
	}
	gao();
	m=read();
	gao2(1);
	for(int i=1;i<=m;++i)
	{
		x1[i]=read(),y1[i]=read(),x2[i]=read(),y2[i]=read();
		ans[i]=lca(get(x1[i],y1[i]),get(x2[i],y2[i]));
		printf("%d\n",ans[i]);
	}
//	for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
	//gao2(2);
	//for(int i=1;i<=m;++i)
	//{
	//	printf("%d\n",max(ans[i],lca(get(x1[i],y1[i]),get(x2[i],y2[i]))));
	//}
	return 0;
}
/*
7
.....#.
...#.#.
....#..
....###
....#..
#......
.......
5
2 5 5 2
2 5 3 6
2 2 6 3
2 2 6 6
1 1 7 7
*/
