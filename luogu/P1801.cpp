#include <bits/stdc++.h>
using namespace std;
const int maxn=200000;
typedef long long ll;

int n,m,cnt=0,tot=0;
ll tr[maxn+5],a[maxn+5],b[maxn+5],u[maxn+5];

int lowbit(int x){return x&-x;}

void add(int pos,int x)
{
    for(int i=pos;i<=tot;i+=lowbit(i))
        tr[i]+=x;
}

int kth(int k)
{
    int ans=0,cnt=0;
    for(int i=20;i>=0;--i){
        ans+=(1<<i);
        if(ans>tot||cnt+tr[ans]>=k)
            ans-=(1<<i);
        else
            cnt+=tr[ans];
    }
    return ans+1;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[++tot]);
        b[tot]=a[tot];
    }
    for(int i=1;i<=m;++i)
        scanf("%lld",&u[i]);
    sort(a+1,a+1+n);
    tot=unique(a+1,a+1+tot)-a-1;
    for(int i=1;i<=n;++i)
        b[i]=lower_bound(a+1,a+1+tot,b[i])-a;
    int flg=1;
    for(int i=1;i<=n;++i){
        add(b[i],1);
        while(flg<=m&&i==u[flg]){
            cnt++;
            printf("%lld\n",a[kth(cnt)]);
            flg++;
        }
        if(flg>m)
            break;
    }
    return 0;
}
