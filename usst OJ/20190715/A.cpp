#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;

int n,qian,shijian;
int q[maxn],s[maxn];
int dp[maxn][maxn];

int main()
{
    scanf("%d %d %d",&n,&qian,&shijian);
    for(int i=0;i<n;++i)
        scanf("%d %d",&q[i],&s[i]);
    for(int i=0;i<n;++i)
    {
        for(int j=qian;j>=q[i];--j)
        {
            for(int k=shijian;k>=s[i];--k)
            {
                dp[j][k]=max(dp[j][k],dp[j-q[i]][k-s[i]]+1);
            }
        }
    }
    printf("%d",dp[qian][shijian]);
    return 0;
}
