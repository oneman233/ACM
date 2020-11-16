#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;

int n,m,s,x,y,v;
struct edge
{
    int v,y,to;
}e[maxn];
int head[maxn],tot=0;
int dis[maxn];
bool vis[maxn];

void add(int x,int y,int v)
{
    e[++tot].y=y;
    e[tot].v=v;
    e[tot].to=head[x];
    head[x]=tot;
}

void spfa(int s)
{
    for(int i=1;i<=n;++i)
        dis[i]=2147483647;
    dis[s]=0;
    memset(vis,0,sizeof(vis));
    vis[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int f=q.front();
        vis[f]=false;
        for(int i=head[f];i;i=e[i].to){
            if(dis[e[i].y]>=dis[f]+e[i].v){
                dis[e[i].y]=dis[f]+e[i].v;
                if(!vis[e[i].y])
                    q.push(e[i].y);
            }
        }
        q.pop();
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&s);
    while(m--){
        scanf("%d%d%d",&x,&y,&v);
        add(x,y,v);
    }
    spfa(s);
    printf("%d",dis[1]);
    for(int i=2;i<=n;++i)
        printf(" %d",dis[i]);
    return 0;
}
