#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100000;

int n,m;
ll tr[maxn*4+5],big[maxn*4+5],a[maxn+5];

inline int ls(int p){return p*2;}
inline int rs(int p){return p*2+1;}

void up(int p)
{
    tr[p]=tr[ls(p)]+tr[rs(p)];
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

void modify(int p,int l,int r,int lll,int rrr)
{
    if(l==r&&lll<=l&&r<=rrr){
        tr[p]=sqrt(tr[p]);
        big[p]=sqrt(big[p]);
        return;
    }
    int m=(l+r)/2;
    if(lll<=m&&big[ls(p)]>1)
        modify(ls(p),l,m,lll,rrr);
    if(rrr>m&&big[rs(p)]>1)
        modify(rs(p),m+1,r,lll,rrr);
    up(p);
}

ll query(int p,int l,int r,int lll,int rrr)
{
    if(lll<=l&&r<=rrr)
        return tr[p];
    int m=(l+r)/2;
    ll ans=0;
    if(lll<=m)
        ans+=query(ls(p),l,m,lll,rrr);
    if(rrr>m)
        ans+=query(rs(p),m+1,r,lll,rrr);
    return ans;
}

int main()
{
    int cnt=1;
    while(~scanf("%d",&n)){
        memset(tr,0,sizeof(tr));
        memset(big,0,sizeof(big));
        printf("Case #%d:\n",cnt);
        cnt++;
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
        printf("\n");
    }
    return 0;
}
