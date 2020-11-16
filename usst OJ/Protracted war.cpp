#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200000;

int n,m;
ll a[maxn+5],tr[maxn*4+5],big[maxn*4+5];

inline int ls(int p){return p*2;}
inline int rs(int p){return p*2+1;}

void up(int p)
{
    tr[p]=__gcd(tr[ls(p)],tr[rs(p)]);
    big[p]=max(big[ls(p)],big[rs(p)]);
}

void build(int p,int l,int r)
{
    if(l==r){
        tr[p]=big[p]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(ls(p),l,m);
    build(rs(p),m+1,r);
    up(p);
}

void modify(int p,int l,int r,int meml,int memr)
{
    if(l==r&&meml<=l&&r<=memr){
        tr[p]=(ll)sqrt(tr[p]);
        big[p]=(ll)sqrt(big[p]);
        return;
    }
    int m=(l+r)/2;
    if(meml<=m&&big[ls(p)]>1)
        modify(ls(p),l,m,meml,memr);
    if(memr>m&&big[rs(p)]>1)
        modify(rs(p),m+1,r,meml,memr);
    up(p);
}

ll query(int p,int l,int r,int meml,int memr)
{
    if(meml<=l&&r<=memr)
        return tr[p];
    int m=(l+r)/2;
    ll ans=0;
    if(meml<=m)
        ans=__gcd(ans,query(ls(p),l,m,meml,memr));
    if(memr>m)
        ans=__gcd(ans,query(rs(p),m+1,r,meml,memr));
    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
        int opt,x,y;
        scanf("%d %d %d",&opt,&x,&y);
        if(x>y){
            int tmp=x;
            x=y;
            y=tmp;
        }
        if(opt==0)
            modify(1,1,n,x,y);
        else if(opt==1)
            printf("%lld\n",query(1,1,n,x,y));
    }
    return 0;
}
