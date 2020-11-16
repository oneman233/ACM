#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=400005;

int n,q,judge,x,y;
ll read[maxn],mod,vv;
struct tree
{
    int l,r;
    ll v,mul=1ll,add=0ll;
}seg[maxn];

int ls(int p){return p*2;}
int rs(int p){return p*2+1;}
void up(int p){seg[p].v=seg[ls(p)].v+seg[rs(p)].v;seg[p].v%=mod;}

void down(int p)
{
    seg[ls(p)].mul*=seg[p].mul;
    seg[ls(p)].mul%=mod;
    seg[rs(p)].mul*=seg[p].mul;
    seg[rs(p)].mul%=mod;
    ///mul
    seg[ls(p)].add=seg[ls(p)].add*seg[p].mul+seg[p].add;
    seg[ls(p)].add%=mod;
    seg[rs(p)].add=seg[rs(p)].add*seg[p].mul+seg[p].add;
    seg[rs(p)].add%=mod;
    ///add
    seg[ls(p)].v=seg[ls(p)].v*seg[p].mul+seg[p].add*(seg[ls(p)].r-seg[ls(p)].l+1);
    seg[ls(p)].v%=mod;
    seg[rs(p)].v=seg[rs(p)].v*seg[p].mul+seg[p].add*(seg[rs(p)].r-seg[rs(p)].l+1);
    seg[rs(p)].v%=mod;
    ///v
    seg[p].add=0;
    seg[p].mul=1;
    ///
}

void build(int p,int l,int r)
{
    if(l>=r){
        seg[p].l=l;
        seg[p].r=r;
        seg[p].v=read[l];
        return;
    }
    int m=(l+r)/2;
    seg[p].l=l;
    seg[p].r=r;
    build(ls(p),l,m);
    build(rs(p),m+1,r);
    up(p);
}

void modify1(int p,int ml,int mr,ll val)///mul
{
    if(ml<=seg[p].l&&seg[p].r<=mr){
        seg[p].v*=val;
        seg[p].v%=mod;
        seg[p].mul*=val;
        seg[p].mul%=mod;
        seg[p].add*=val;
        seg[p].add%=mod;
        return;
    }
    down(p);
    if(seg[ls(p)].r>=ml)
        modify1(ls(p),ml,mr,val);
    if(seg[rs(p)].l<=mr)
        modify1(rs(p),ml,mr,val);
    up(p);
}

void modify2(int p,int ml,int mr,ll val)///add
{
    if(ml<=seg[p].l&&seg[p].r<=mr){
        seg[p].v+=val*(seg[p].r-seg[p].l+1);
        seg[p].v%=mod;
        seg[p].add+=val;
        seg[p].add%=mod;
        return;
    }
    down(p);
    if(seg[ls(p)].r>=ml)
        modify2(ls(p),ml,mr,val);
    if(seg[rs(p)].l<=mr)
        modify2(rs(p),ml,mr,val);
    up(p);
}

ll query(int p,int ql,int qr)
{
    if(ql<=seg[p].l&&seg[p].r<=qr)
        return seg[p].v%mod;
    ll ans=0;
    down(p);
    if(seg[ls(p)].r>=ql){
        ans+=query(ls(p),ql,qr);
        ans%=mod;
    }
    if(seg[rs(p)].l<=qr){
        ans+=query(rs(p),ql,qr);
        ans%=mod;
    }
    up(p);
    return ans%mod;
}

int main()
{
    //scanf("%d %d %lld",&n,&q,&mod);
    scanf("%d %lld",&n,&mod);
    for(int i=1;i<=n;++i)
        scanf("%lld",&read[i]);
    build(1,1,n);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&judge,&x,&y);
        if(judge==1){
            scanf("%lld",&vv);
            modify1(1,x,y,vv);
        }
        else if(judge==2){
            scanf("%lld",&vv);
            modify2(1,x,y,vv);
        }
        else if(judge==3)
            printf("%lld\n",query(1,x,y));
    }
    return 0;
}
