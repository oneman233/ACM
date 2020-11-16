#include <iostream>
#include <cstdio>
#define int long long
///#define debug
using namespace std;
const int maxn=1000005;
const int mod=10007;

int n,m;
int p1[maxn],p2[maxn],p3[maxn];
int add[maxn],mul[maxn],isset[maxn];
int a,b,c,d;

int ll(int p){return p*2;}
int rr(int p){return p*2+1;}
int pow2(int x){return (x*x)%mod;}
int pow3(int x){return (x*x*x)%mod;}

void up(int p)
{
    p1[p]=p1[ll(p)]+p1[rr(p)];
    p2[p]=p2[ll(p)]+p2[rr(p)];
    p3[p]=p3[ll(p)]+p3[rr(p)];
}

void down(int p,int l,int r)
{
    if(isset[p]!=0){
        int m=(l+r)/2;
        int lenll=m-l+1,lenrr=r-m;
        mul[ll(p)]=1;mul[rr(p)]=1;
        add[ll(p)]=0;add[rr(p)]=0;
        p1[ll(p)]=isset[p]*lenll;
        p1[ll(p)]%=mod;
        p2[ll(p)]=pow2(isset[p])*lenll;
        p2[ll(p)]%=mod;
        p3[ll(p)]=pow3(isset[p])*lenll;
        p3[ll(p)]%=mod;
        ///ll
        p1[rr(p)]=isset[p]*lenrr;
        p1[rr(p)]%=mod;
        p2[rr(p)]=pow2(isset[p])*lenrr;
        p2[rr(p)]%=mod;
        p3[rr(p)]=pow3(isset[p])*lenrr;
        p3[rr(p)]%=mod;
        ///rr
        isset[ll(p)]=isset[p];
        isset[rr(p)]=isset[p];
        isset[p]=0;
    }
    if(mul[p]!=1){
        mul[ll(p)]*=mul[p];mul[ll(p)]%=mod;
        mul[rr(p)]*=mul[p];mul[rr(p)]%=mod;
        ///mul
        add[ll(p)]*=mul[p];add[ll(p)]%=mod;
        add[rr(p)]*=mul[p];add[rr(p)]%=mod;
        ///add
        p3[ll(p)]*=pow3(mul[p]);
        p3[ll(p)]%=mod;
        ///p3ll
        p3[rr(p)]*=pow3(mul[p]);
        p3[rr(p)]%=mod;
        ///p3rr
        p2[ll(p)]*=pow2(mul[p]);
        p2[ll(p)]%=mod;
        ///p2ll
        p2[rr(p)]*=pow2(mul[p]);
        p2[rr(p)]%=mod;
        ///p2rr
        p1[ll(p)]*=mul[p];
        p1[ll(p)]%=mod;
        ///p1ll
        p1[rr(p)]*=mul[p];
        p1[rr(p)]%=mod;
        ///p1rr
        mul[p]=1;
    }
    if(add[p]!=0){
        int m=(l+r)/2;
        int lenll=m-l+1,lenrr=r-m;
        add[ll(p)]+=add[p];add[ll(p)]%=mod;
        add[rr(p)]+=add[p];add[rr(p)]%=mod;
        ///add
        p3[ll(p)]+=
              3*add[p]*p2[ll(p)]
              +3*pow2(add[p])*p1[ll(p)]
              +pow3(add[p])*lenll;
        p3[ll(p)]%=mod;
        ///p3ll
        p3[rr(p)]+=
              3*add[p]*p2[rr(p)]
              +3*pow2(add[p])*p1[rr(p)]
              +pow3(add[p])*lenrr;
        p3[rr(p)]%=mod;
        ///p3rr
        p2[ll(p)]+=2*add[p]*p1[ll(p)]
                 +pow2(add[p])*lenll;
        p2[ll(p)]%=mod;
        ///p2ll
        p2[rr(p)]+=2*add[p]*p1[rr(p)]
                 +pow2(add[p])*lenrr;
        p2[rr(p)]%=mod;
        ///p2rr
        p1[ll(p)]+=add[p]*lenll;
        p1[ll(p)]%=mod;
        ///p1ll
        p1[rr(p)]+=add[p]*lenrr;
        p1[rr(p)]%=mod;
        ///p1rr
        add[p]=0;
    }
}

void build(int p,int l,int r)
{
    add[p]=0;
    mul[p]=1;
    isset[p]=0;
    p1[p]=0;
    p2[p]=0;
    p3[p]=0;
    if(l==r)
        return;
    int m=(l+r)/2;
    build(ll(p),l,m);
    build(rr(p),m+1,r);
}

void modifyadd(int p,int l,int r,int L,int R,int val)
{
    if(L<=l&&r<=R){
        add[p]+=val;
        add[p]%=mod;
        int len=r-l+1;
        p3[p]+=3*val*p2[p]+3*pow2(val)*p1[p]+pow3(val)*len;
        p3[p]%=mod;
        p2[p]+=2*val*p1[p]+pow2(val)*len;
        p2[p]%=mod;
        p1[p]+=len*val;
        p1[p]%=mod;
        return;
    }
    down(p,l,r);
    int m=(l+r)/2;
    if(L<=m) modifyadd(ll(p),l,m,L,R,val);
    if(R>m) modifyadd(rr(p),m+1,r,L,R,val);
    up(p);
}

void modifymul(int p,int l,int r,int L,int R,int val)
{
    if(L<=l&&r<=R){
        mul[p]*=val;
        mul[p]%=mod;
        add[p]*=val;
        add[p]%=mod;
        p1[p]*=val;
        p1[p]%=mod;
        p2[p]*=pow2(val);
        p2[p]%=mod;
        p3[p]*=pow3(val);
        p3[p]%=mod;
        return;
    }
    down(p,l,r);
    int m=(l+r)/2;
    if(L<=m) modifymul(ll(p),l,m,L,R,val);
    if(R>m) modifymul(rr(p),m+1,r,L,R,val);
    up(p);
}

void modifyset(int p,int l,int r,int L,int R,int val)
{
    if(L<=l&&r<=R){
        int len=r-l+1;
        p1[p]=val*len;
        p1[p]%=mod;
        p2[p]=pow2(val)*len;
        p2[p]%=mod;
        p3[p]=pow3(val)*len;
        p3[p]%=mod;
        add[p]=0;mul[p]=1;
        isset[p]=val;
        isset[p]%=mod;
        return;
    }
    down(p,l,r);
    int m=(l+r)/2;
    if(L<=m) modifyset(ll(p),l,m,L,R,val);
    if(R>m) modifyset(rr(p),m+1,r,L,R,val);
    up(p);
}

int ask1(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return p1[p];
    down(p,l,r);
    int m=(l+r)/2,ans=0;
    if(L<=m) ans+=ask1(ll(p),l,m,L,R);
    ans%=mod;
    if(R>m) ans+=ask1(rr(p),m+1,r,L,R);
    ans%=mod;
    up(p);
    return ans;
}

int ask2(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return p2[p];
    down(p,l,r);
    int m=(l+r)/2,ans=0;
    if(L<=m) ans+=ask2(ll(p),l,m,L,R);
    ans%=mod;
    if(R>m) ans+=ask2(rr(p),m+1,r,L,R);
    ans%=mod;
    up(p);
    return ans;
}

int ask3(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return p3[p];
    down(p,l,r);
    int m=(l+r)/2,ans=0;
    if(L<=m) ans+=ask3(ll(p),l,m,L,R);
    ans%=mod;
    if(R>m) ans+=ask3(rr(p),m+1,r,L,R);
    ans%=mod;
    up(p);
    return ans;
}

signed main()
{
    scanf("%lld %lld",&n,&m);
    build(1,1,n);
    while(m--){
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(a==1)
            d%=mod,modifyadd(1,1,n,b,c,d);
        else if(a==2)
            d%=mod,modifymul(1,1,n,b,c,d);
        else if(a==3)
            d%=mod,modifyset(1,1,n,b,c,d);
        else if(a==4){
            if(d==1)
                printf("%lld\n",ask1(1,1,n,b,c));
            else if(d==2)
                printf("%lld\n",ask2(1,1,n,b,c));
            else if(d==3)
                printf("%lld\n",ask3(1,1,n,b,c));
        }
        #ifdef debug
        for(int i=1;i<=n;++i)
            cout<<ask1(1,1,n,i,i)<<' ';
        cout<<endl;
        for(int i=1;i<=n;++i)
            cout<<ask2(1,1,n,i,i)<<' ';
        cout<<endl;
        for(int i=1;i<=n;++i)
            cout<<ask3(1,1,n,i,i)<<' ';
        cout<<endl;
        #endif // debug
    }
    return 0;
}
