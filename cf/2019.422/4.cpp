#include <bits/stdc++.h>
using namespace std;
const int maxn=300000;
typedef long long ll;

int n,x;
ll a[maxn+5],sum[maxn+5];
ll big,sml;

ll f_maxdif()
{
    ll m=sum[1];
    ll mdif=m-sum[2];
    for(int i=3;i<=n;++i)
    {
        if(sum[i-1]>m)
            m=sum[i-1];
        ll curdif=m-sum[i];
        if(curdif>mdif)
            mdif=curdif;
    }
    return mdif;
}

ll b_maxdif()
{
    ll m=sum[n];
    ll mdif=m-sum[n-1];
    for(int i=n-2;i>=0;--i)
    {
        if(sum[i+1]>m)
            m=sum[i+1];
        ll curdif=m-sum[i];
        if(curdif>mdif)
            mdif=curdif;
    }
    return mdif;
}

int main()
{
    scanf("%d %d",&n,&x);
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        sum[i]+=sum[i-1]+a[i];
    }
    ///Ç°×ººÍ
    big=b_maxdif();
    sml=-1*f_maxdif();
    ///cout<<big<<" "<<sml;
    if(x<0)
    {
        if(max(max(big,sum[n])+sml*x,max(big,sum[n]))>0)
            printf("%lld",max(max(big,sum[n])+sml*x,max(big,sum[n])));
        else
            printf("0");
    }
    else
    {
        if(x==0)
        {
            if(max(sum[n],big)>0)
                printf("%lld",max(big,sum[n]));
            else
                printf("0");
        }
        else
        {
            if(max(big,sum[n])*x>0)
                printf("%lld",max(big,sum[n])*x);
            else
                printf("0");
        }
    }
    return 0;
}
