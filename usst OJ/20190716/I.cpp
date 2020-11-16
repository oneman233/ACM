#include <bits/stdc++.h>
#define int long long
//#define debug
using namespace std;
const int maxn=100005;

int n;
int p[maxn],rk[maxn];
struct edge
{
    int x,y,v;
    bool operator < (edge &e)
    {
        return v<e.v;
    }
}e[maxn];

int _find(int x)
{
    if(x!=p[x])
        p[x]=_find(p[x]);
    return p[x];
}

void _merge(int x,int y)
{
    int rx=_find(x);
    int ry=_find(y);
    if(rx!=ry){
        p[rx]=ry;
        rk[ry]+=rk[rx];
    }
}

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        p[i]=i,rk[i]=1;
    for(int i=1;i<=n-1;++i)
        scanf("%lld %lld %lld",&e[i].x,&e[i].y,&e[i].v);
    sort(e+1,e+n);
    int ans=0;
    for(int i=1;i<=n-1;++i){
        int rx=_find(e[i].x);
        int ry=_find(e[i].y);
        #ifdef debug
        cout<<e[i].x<<' '<<e[i].y<<endl;
        cout<<rx<<' '<<ry<<endl;
        #endif
        ans+=(rk[rx]*rk[ry]-1)*(e[i].v+1);
        _merge(rx,ry);
    }
    printf("%lld",ans);
    return 0;
}
