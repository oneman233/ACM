#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define re(i,a) for(int i=1;i<=a;++i)
using namespace std;
typedef long long ll;
const ll maxn=100001;

ll n,e[maxn];
ll x,y,v;
struct edge
{
    ll son,v;
    edge(ll a,ll b):son(a),v(b){}
};
vector<edge> p[maxn];
ll sz[maxn],dp[maxn],as[maxn];

void d1(ll x,ll fa)
{
    sz[x]+=e[x];
    for(int i=0;i<p[x].size();++i)
    {
        ll son=p[x][i].son;
        ll v=p[x][i].v;
        if(son==fa)
            continue;
        d1(son,x);
        sz[x]+=sz[son];
        dp[x]+=dp[son]+sz[son]*v;
    }
}

void d2(ll x,ll fa,ll v)
{
    if(x!=1)
        as[x]=as[fa]+(sz[1]-2*sz[x])*v;
    for(int i=0;i<p[x].size();++i)
    {
        ll son=p[x][i].son;
        ll v=p[x][i].v;
        if(son==fa)
            continue;
        d2(son,x,v);
    }
}

void debug()
{
    re(i,n)
        cout<<sz[i]<<" ";
    cout<<endl;
    re(i,n)
        cout<<dp[i]<<" ";
    cout<<endl;
    re(i,n)
        cout<<as[i]<<" ";
    cout<<endl;
}

void init()
{
    memset(sz,0,sizeof(sz));
    memset(dp,0,sizeof(dp));
    memset(as,0,sizeof(as));
}

void read()
{
    cin>>n;
    re(i,n)
        cin>>e[i];
    re(i,n-1)
    {
        cin>>x>>y>>v;
        p[x].pb(edge(y,v));
        p[y].pb(edge(x,v));
    }
}

void out()
{
    ll sml=as[n],ix=n;
    re(i,n-1)
    {
        if(as[i]<sml){
            sml=as[i];
            ix=i;
        }
    }
    cout<<ix<<'\n'<<as[ix]*2;
}

int main()
{
    init();
    read();
    d1(1,1);
    as[1]=dp[1];
    d2(1,1,0);
    ///debug();
    out();
    return 0;
}
/*
long long is long
but not too long
life is short
but long long is long
*/
