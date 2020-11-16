#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200005;
const int inf=-0x3f3f3f3f;

int a,b,c,d;
int n,q,arr[maxn];
int sum[maxn*4];
int mx[maxn*4],mmx[maxn*4];
int tag[maxn*4],cnt[maxn*4];

int ls(int x){return x*2;}
int rs(int x){return x*2+1;}

int max3(int x,int y,int z){return max(x,max(y,z));}
int min3(int x,int y,int z){return min(x,min(y,z));}

void up(int p)
{
    sum[p]=sum[ls(p)]+sum[rs(p)];
    if(mx[ls(p)]>mx[rs(p)]){
        mx[p]=mx[ls(p)];
        cnt[p]=cnt[ls(p)];
        mmx[p]=max3(mx[rs(p)],mmx[ls(p)],mmx[rs(p)]);
    }
    else if(mx[ls(p)]<mx[rs(p)]){
        mx[p]=mx[rs(p)];
        cnt[p]=cnt[rs(p)];
        mmx[p]=max3(mx[ls(p)],mmx[ls(p)],mmx[rs(p)]);
    }
    else{
        mx[p]=mx[ls(p)];
        cnt[p]=cnt[ls(p)]+cnt[rs(p)];
        mmx[p]=max(mmx[ls(p)],mmx[rs(p)]);
    }
}

void down(int p)
{
    if(tag[p]!=0){
        tag[ls(p)]=1;
        tag[rs(p)]=1;
        if(mx[p]<mx[ls(p)]){
            sum[ls(p)]-=(mx[ls(p)]-mx[p])*cnt[ls(p)];
            mx[ls(p)]=mx[p];
        }
        if(mx[p]<mx[rs(p)]){
            sum[rs(p)]-=(mx[rs(p)]-mx[p])*cnt[rs(p)];
            mx[rs(p)]=mx[p];
        }
        tag[p]=0;
    }
}

void build(int p,int l,int r)
{
    if(l==r){
        mx[p]=arr[l];
        mmx[p]=inf;
        cnt[p]=1;
        sum[p]=arr[l];
        return;
    }
    int m=(l+r)/2;
    build(ls(p),l,m);
    build(rs(p),m+1,r);
    up(p);
}

void modify(int p,int l,int r,int L,int R,int val)
{
    if(L<=l&&r<=R){
        if(val>=mx[p])
            return;
        if(val<mx[p]&&val>=mmx[p]){
            tag[p]=1;
            sum[p]-=(mx[p]-val)*cnt[p];
            mx[p]=val;
            return;
        }
    }
    down(p);
    int m=(l+r)/2;
    if(L<=m) modify(ls(p),l,m,L,R,val);
    if(R>m) modify(rs(p),m+1,r,L,R,val);
    up(p);
}

int ask(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R){return sum[p];}
    down(p);
    int m=(l+r)/2,ans=0;
    if(L<=m) ans+=ask(ls(p),l,m,L,R);
    if(R>m) ans+=ask(rs(p),m+1,r,L,R);
    up(p);
    return ans;
}

signed main()
{
    scanf("%lld %lld",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%lld",&arr[i]);
    build(1,1,n);
    while(q--){
        scanf("%lld",&a);
        if(a==1){
            scanf("%lld %lld %lld",&b,&c,&d);
            modify(1,1,n,b,c,d);
        }
        else if(a==2){
            scanf("%lld %lld",&b,&c);
            printf("%lld\n",ask(1,1,n,b,c));
        }
    }
    return 0;
}
