#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;

int n,m,x,y;
struct edge
{
    int y,to;
}e[maxn];
int tot=0,head[maxn],color[maxn];
int ans=0,cnt1=0,cnt2=0;
bool can=true;

void add(int x,int y)
{
    e[++tot].y=y;
    e[tot].to=head[x];
    head[x]=tot;
}

void dfs(int x,int flag)
{
    if(!can||color[x]!=0)
        return;
    color[x]=flag;
    if(flag==1)
        cnt1++;
    else if(flag==2)
        cnt2++;
    for(int i=head[x];i;i=e[i].to){
        if(color[e[i].y]==0)
            dfs(e[i].y,3-flag);
        else if(color[e[i].y]==flag){
            can=false;
            return;
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d %d",&n,&m);
    memset(color,0,sizeof(color));
    memset(head,0,sizeof(head));
    memset(e,0,sizeof(e));
    for(int i=1;i<=m;++i)
    {
        scanf("%d %d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;++i){
        if(color[i]==0){
            cnt1=0;cnt2=0;
            dfs(i,1);
            if(!can)
                break;
            ans+=min(cnt1,cnt2);
        }
    }
    if(can)
        printf("%d",ans);
    else
        printf("QAQ");
    return 0;
}
