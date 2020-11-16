#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x,n;
ll pre[300005],suf[300005],a[300005],ans=0,maxsum[300005],maxlsum[300005];

void f1()
{
    ll minx=0;
    maxsum[0]=0;
    for(int i=1;i<=n;i++)
    {
        minx=min(minx,pre[i]);
        maxsum[i]=pre[i]-minx;
    }
    minx=0;
    maxlsum[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        minx=min(minx,suf[i]);
        maxlsum[i]=suf[i]-minx;
    }
}

void f2()
{
    int j=0;
    ll maxx=0;
    for(int i=1;i<=n;i++)
    {
        if(pre[i]>maxx)
        {
            maxx=pre[i];
            j=i;
        }
        maxx=max(maxx,pre[i]);
        ans=max(ans,x*(pre[i]-maxx)+max(maxsum[j],0ll)+max(maxlsum[i+1],0ll));
    }
}

int main()
{
    scanf("%d%d",&n,&x);
    pre[0]=0;suf[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+a[i];
    f1();
    if(x>=0)
    {
        for(int i=0;i<=n;i++)
            ans=max(maxsum[i],ans);
        printf("%lld",max(ans*x,ans));
        return 0;
    }
    f2();
    printf("%lld",ans);
    return 0;
}
