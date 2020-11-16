#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int inf=-0x3f3f3f3f;

int t,n;
int a[maxn],dp[maxn][4];

int mmax(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int mmax(int a,int b,int c)
{
    return mmax(a,mmax(b,c));
}

int mmax(int a,int b,int c,int d)
{
    return mmax(a,mmax(b,c,d));
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(dp,-0x3f,sizeof(dp));
        dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;++i){
            dp[i][0]=mmax(dp[i-1][0],dp[i-1][1])+a[i];
            dp[i][1]=dp[i-1][1]+a[i]*(-1);
            dp[i][2]=mmax(dp[i-1][0],dp[i-1][2],dp[i-1][3])+a[i]*(-1);
            dp[i][3]=mmax(dp[i-1][0],dp[i-1][1],dp[i-1][3])+a[i];
        }
        printf("%d\n",mmax(dp[n][0],dp[n][1],dp[n][2],dp[n][3]));
    }
    return 0;
}
