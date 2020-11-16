#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=10000005;

ll n,m,k,pp,qq,r,mod;
ll a[maxn];
ll ansmax[maxn],anscnt[maxn],tot;
ll head,tail,q[maxn],p[maxn];
ll ans1=0,ans2=0;

int main()
{
    scanf("%lld %lld %lld %lld %lld %lld %lld",&n,&m,&k,&pp,&qq,&r,&mod);
    for(int i=1;i<=k;++i)
        scanf("%lld",&a[i]);
    for(int i=k+1;i<=n;++i)
        a[i]=(pp*a[i-1]+qq*i+r)%mod;
    head=1,tail=0;
    for(int i=1;i<=m;++i)
    {
        while(head<=tail&&q[tail]<=a[i])
            tail--;
        q[++tail]=a[i];
        p[tail]=i;
        while(p[head]<=i-m)
            head++;
    }
    tot=1;
    ansmax[tot]=q[head];
    for(int i=m+1;i<=n;++i)
    {
        while(head<=tail&&q[tail]<=a[i])
            tail--;
        q[++tail]=a[i];
        p[tail]=i;
        while(p[head]<=i-m)
            head++;
        ansmax[++tot]=q[head];
    }
    for(int i=1;i<=n-m+1;++i)
        ans1+=ansmax[i]^i;
    printf("%lld ",ans1);
    head=1,tail=0;
    for(int i=n;i>=n-m+1;--i)
    {
        while(head<=tail&&q[tail]<=a[i])
            tail--;
        q[++tail]=a[i];
        p[tail]=i;
        while(p[head]>=i+m)
            head++;
    }
    tot=n-m+1;
    anscnt[tot]=tail-head+1;
    for(int i=n-m;i>=1;--i)
    {
        while(head<=tail&&q[tail]<=a[i])
            tail--;
        q[++tail]=a[i];
        p[tail]=i;
        while(p[head]>=i+m)
            head++;
        anscnt[--tot]=tail-head+1;
    }
    for(int i=1;i<=n-m+1;++i)
        ans2+=anscnt[i]^i;
    printf("%lld",ans2);
    return 0;
}
