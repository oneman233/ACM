#include <bits/stdc++.h>
#define prin(a) printf("%d\n",a)
using namespace std;
const int maxn=2000000;

int n,m;
int dp[maxn+5][22];

int mi(int a,int b)
{
    return a>b?b:a;
}

int q(int l,int r)
{
    int k=(int)log2(r-l+1);
    return mi(dp[l][k],dp[r-(1<<k)+1][k]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",&dp[i][0]);
    for(int j=1;j<=21;++j)
        for(int i=0;i<n;++i)
            if(i+(1<<j)<n)
                dp[i][j]=mi(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    printf("0\n");
    prin(dp[0][0]);
    for(int i=2;i<n;++i)
    {
        if(i<m)
            prin(q(1,i-1));
        else
            prin(q(i-m,i-1));
    }
    return 0;
}
