#include <bits/stdc++.h>
using namespace std;

int t;
int n,a[100010],sum[100010];
int s,e,ans;

void divide(int l,int r)
{
    if(l>r)
        return;
    if(sum[r]-sum[l-1]>ans)
    {
        ans=sum[r]-sum[l-1];
        s=l;
        e=r;
    }
    div(l,(l+r)/2);
    div((l+r)/2+1,r);
}

int main()
{
    scanf("%d",&t);
    for(int idx=1;idx<=t;++idx)
    {
        memset(sum,0,sizeof(sum));
        ans=-10000;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<=n;++i)
            ans=max(sum[i],ans);
        for(int i=1;i<=n;++i)
            divide(1,i);
        for(int i=n;i>=0;--i)
            divide(i,n);
        printf("Payoff %d:\n",idx);
        printf("%d %d %d",ans,s,e);
        if(idx!=t)
            printf("\n\n");
    }
    return 0;
}
