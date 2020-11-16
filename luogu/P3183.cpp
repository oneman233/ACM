#include <bits/stdc++.h>
using namespace std;
const int maxn=400000;

int n,m,ans;
int fst[maxn+5],nxt[maxn+5];
int x[maxn+5],y[maxn+5];
int ind[maxn+5],otd[maxn+5];
bool vis[maxn+5];
int mem[maxn+5];

int dfs(int x)
{
    if(mem[x]!=0)
        return mem[x];
    int tmp=0;
    if(otd[x]==0&&ind[x]!=0)
        return 1;
    if(vis[x]||otd[x]==0)
        return 0;
    vis[x]=1;
    int i=fst[x];
    while(i!=-1){
        tmp+=dfs(y[i]);
        i=nxt[i];
    }
    vis[x]=0;
    mem[x]=tmp;
    return tmp;
}

void pre()
{
    memset(ind,0,sizeof(ind));
    memset(otd,0,sizeof(otd));
    memset(vis,0,sizeof(vis));
    memset(mem,0,sizeof(mem));
    for(int i=1;i<=n;++i)
        fst[i]=-1;
}

int main()
{
    scanf("%d %d",&n,&m);
    pre();
    if(m==0){
        printf("0");
        return 0;
    }
    for(int i=1;i<=m;++i){
        scanf("%d %d",&x[i],&y[i]);
        otd[x[i]]++;
        ind[y[i]]++;
        nxt[i]=fst[x[i]];
        fst[x[i]]=i;
    }
    for(int i=1;i<=n;++i){
        if(ind[i]==0){
            dfs(i);
            ans+=mem[i];
        }
    }
    printf("%d",ans);
    return 0;
}
