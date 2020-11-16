#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pu(a) push_back(a)
#define po() pop_back()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=1005;
typedef long long ll;
const int inf=-10000000;

int n,t;
int v[maxn],w[maxn];
///contribution = 1
int dp[1000005];

void com_bag(int i)
{
    re(j,v[i],t)
        dp[j]=max(dp[j],dp[j-v[i]]+1);
}

void zero_one(int i)
{
    int cnt=1;
    while(cnt<=w[i]){
        rre(j,t,v[i]*cnt)
            dp[j]=max(dp[j],dp[j-v[i]*cnt]+cnt);
        w[i]-=cnt;
        cnt<<=1;
    }
    rre(j,t,v[i]*w[i])
        dp[j]=max(dp[j],dp[j-v[i]*w[i]]+w[i]);
}

int main()
{
    scii(n,t);
    for(int i=0;i<=t;++i)
        dp[i]=inf;
    dp[0]=0;
    fo(i,0,n)
        scii(v[i],w[i]);
    fo(i,0,n)
    {
        if(v[i]*w[i]>=t)
            com_bag(i);
        else
            zero_one(i);
    }
    /*
    for(int i=0;i<=t;++i)
        cout<<dp[i]<<" ";
    */
    if(dp[t]>0)
        pri(dp[t]);
    else
        printf("0");
    return 0;
}
/*
2 10
1 9
11 1
*/
