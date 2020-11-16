#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100005;
const int inf=0x3f3f3f3f;

int x,y,z;
int n,m;
int a[maxn];
int sum[maxn*4],mn[maxn*4],mx[maxn*4];

int up(int p)
{
    int ls=p*2;
    int rs=p*2+1;
    sum[p]=sum[ls]+sum[rs];
    mx[p]=max(mx[ls],mx[rs]);
    mn[p]=min(mn[ls],mn[rs]);
}

void build(int p,int l,int r)
{
    if(l==r)
    {
        sum[p]=a[l];
        mx[p]=a[l];
        mn[p]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(p*2,l,m);
    build(p*2+1,m+1,r);
    up(p);
}

void modify(int p,int l,int r,int pos,int val)
{
    if(l==r&&l==pos)
    {
        sum[p]=val;
        mx[p]=val;
        mn[p]=val;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m)
        modify(p*2,l,m,pos,val);
    else
        modify(p*2+1,m+1,r,pos,val);
    up(p);
}

int query1(int p,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr)
    {
        return sum[p];
    }
    int m=(l+r)/2,ans=0;
    if(ql<=m) ans+=query1(p*2,l,m,ql,qr);
    if(qr>m) ans+=query1(p*2+1,m+1,r,ql,qr);
    up(p);
    return ans;
}

int query2(int p,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr)
    {
        return mx[p];
    }
    int m=(l+r)/2,ans=-inf;
    if(ql<=m) ans=max(ans,query2(p*2,l,m,ql,qr));
    if(qr>m) ans=max(ans,query2(p*2+1,m+1,r,ql,qr));
    up(p);
    return ans;
}

int query3(int p,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr)
    {
        return mn[p];
    }
    int m=(l+r)/2,ans=inf;
    if(ql<=m) ans=min(ans,query3(p*2,l,m,ql,qr));
    if(qr>m) ans=min(ans,query3(p*2+1,m+1,r,ql,qr));
    up(p);
    return ans;
}

signed main()
{
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--)
    {
        scanf("%lld %lld %lld",&x,&y,&z);
        if(x==1)
            printf("%lld\n",query1(1,1,n,y,z)-query2(1,1,n,y,z)-query3(1,1,n,y,z));
        else if(x==2)
            modify(1,1,n,y,z);
    }
    return 0;
}
