#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a,long long b)//a是分母，b是分子
{
    while(b!=0)
    {
        long long i=a%b;
        a=b;
        b=i;
    }
    return a;
}

long long pow(int n)//用来算分母
{
    long long result=1;
    for(int i=0;i<n;i++)
        result*=6;
    return result;
}

int main()
{
    int n;
    int t;
    cin>>n>>t;
    if(6*n<t)
        printf("0");
    else if(t<=n)
        printf("1");
    else
    {
        long long dp[25][125];//最多20个骰子，和最大是125
        memset(dp,0,sizeof(dp));
        dp[1][1]=1;
        dp[1][2]=1;
        dp[1][3]=1;
        dp[1][4]=1;
        dp[1][5]=1;
        dp[1][6]=1;
        //投掷一次只有这些情况
        for(int i=2;i<=n;i++)
        {
            for(int j=6*i;j>=i;j--)
            {
                if(j>6)
                    dp[i][j]+=(dp[i-1][j-1]+dp[i-1][j-2]+dp[i-1][j-3]+dp[i-1][j-4]+dp[i-1][j-5]+dp[i-1][j-6]);
                else
                {
                    for(int k=1;k<j;k++)
                        dp[i][j]+=dp[i-1][j-k];
                }
            }
        }
        for(int i=t+1;i<=6*n;i++)
            dp[n][t]+=dp[n][i];
        cout<<dp[n][t]/gcd(pow(n),dp[n][t]);
        cout<<"/";
        cout<<pow(n)/gcd(pow(n),dp[n][t]);
    }
    return 0;
}
