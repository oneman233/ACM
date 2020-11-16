#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int maxn=200005;

bool can=false,vis[maxn];
int n,m,xx,yy,vv;
ll c,d,e;
struct edge
{
    int y,to,v;
}eg[maxn*2];
int head[maxn],tot=0;
int cnt[maxn];

void add(int x,int y,int v)
{
    eg[++tot].y=y;
    eg[tot].v=v;
    eg[tot].to=head[x];
    head[x]=tot;
}

bool check(ll cost)
{
    ll D=cost/c*d;
    ll E=cost/c*e;
    queue<int> q;
    memset(cnt,0x3f,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    q.push(1);
    cnt[1]=0;
    while(!q.empty())
    {
        int f=q.front();
        if(f==n&&cnt[f]<=E)
            return true;
        if(cnt[f]>E)
            return false;
        vis[f]=true;
        for(int i=head[f];i;i=eg[i].to)
        {
            if(eg[i].v<=D&&!vis[eg[i].y])
            {
                q.push(eg[i].y);
                cnt[eg[i].y]=min(cnt[eg[i].y],cnt[f]+1);
            }
        }
        q.pop();
    }
    if(vis[n]&&cnt[n]<=E)
        return true;
    else
        return false;
}

ll half(ll l,ll r)
{
    while(l<=r)
    {
        ll m=(l+r)/2;
        if(check(m))
        {
            can=true;
            r=m-1;
        }
        else
            l=m+1;
    }
    return l;
}

signed main()
{
    scanf("%lld %lld",&n,&m);
    scanf("%lld %lld %lld",&c,&d,&e);
    for(int i=1;i<=m;++i)
    {
        scanf("%lld %lld %lld",&xx,&yy,&vv);
        add(xx,yy,vv);
        add(yy,xx,vv);
    }
    ll ans=half(0LL,1000000000LL);
    if(can)
        printf("%lld",ans);
    else
        printf("-1");
    return 0;
}
/*
5 7
1 1 1
1 2 1
1 3 5
1 4 1
2 3 2
2 4 5
3 4 3
3 5 5

3 1
1 1 1
1 2 1

3 3
1 1 2
1 2 1
2 3 10
1 3 5

*/
