#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
const int inf=0x3f3f3f3f;

int n;
int p[maxn][maxn];
int dis[maxn];
bool vis[maxn];

int dij(int s)
{
    int start=s;
    for(int i=1;i<=n;++i)
        dis[i]=p[s][i];
    dis[s]=inf;
    memset(vis,0,sizeof(vis));
    for(int j=1;j<=n;++j){
        int mn=inf,pos;
        for(int i=1;i<=n;++i){
            if(!vis[i]&&dis[i]<mn){
                mn=dis[i];
                pos=i;
            }
        }
        start=pos;
        vis[pos]=1;
        for(int i=1;i<=n;++i)
            dis[i]=min(dis[i],dis[start]+p[start][i]);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&p[i][j]);
        }
    }
    dij(1);
    int ans=dis[n];
    int tmp=dis[1];
    dij(n);
    printf("%d",min(ans,tmp+dis[n]));
    return 0;
}
