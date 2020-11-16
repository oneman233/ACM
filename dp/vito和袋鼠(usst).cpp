#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const int Max=10000;
int n;
int hi[Max+5],dp[Max+5];
int ans=Max+5;

///dp比dfs优化了大概五百倍的时间

int main()
{

    cin>>n;
    _for(i,0,n)
        cin>>hi[i];
    _for(i,0,n)
        dp[i]=Max+5;
        ///抵达某一位置所需的最小步数
    dp[0]=0;
    ///初始位置设定
    _for(i,0,n)
    {
        if(i+hi[i]>=n&&dp[i]!=Max+5)
        {
            cout<<dp[i]+1;
            return 0;
        }
        ///直接跳过河，可以输出答案
        _for(j,0,hi[i]+1)
            dp[i+j]=min(dp[i]+1,dp[i+j]);
            ///从某一格起跳，更新下面那些格子的最小步数
    }
    cout<<-1;
    ///跳不过河
    return 0;
}
