#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;

int n,m,k,u,v;
int p[maxn],x[maxn],ans[maxn];
struct edge
{
    int next,to;
}e[2*maxn];
int head[maxn],tot=0;
bool del[maxn];

void ad(int x,int y)
{
    e[++tot].to=y;
    e[tot].next=head[x];
    head[x]=tot;
}

int fi(int x)
{
    if(x!=p[x])
        p[x]=fi(p[x]);
    return p[x];
}

void me(int x,int y)
{
    int rx=fi(x);
    int ry=fi(y);
    if(rx!=ry)
        p[rx]=ry;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        p[i]=i;
    for(int i=0;i<m;++i){
        scanf("%d%d",&u,&v);
        ad(u,v);
        ad(v,u);
    }
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        scanf("%d",&x[i]);
        del[x[i]]=true;
    }
    for(int i=1;i<=n;++i){
        if(!del[i]){
            for(int j=head[i];j;j=e[j].next){
                if(!del[e[j].to]){
                    me(i,e[j].to);
                }
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;++i)
        if(!del[i]&&p[i]==i)
            cnt++;
    ans[k]=cnt;
    for(int i=k-1;i>=0;--i){
        del[x[i]]=false;
        cnt++;
        for(int j=head[x[i]];j;j=e[j].next){
            if(!del[e[j].to]){
                cnt--;
                me(i,e[j].to);
            }
        }
        cnt=max(cnt,1);
        ans[i]=cnt;
    }
    for(int i=1;i<=k;++i)
        printf("%d\n",ans[i]);
    return 0;
}
