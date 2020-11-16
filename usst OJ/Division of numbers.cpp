#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

const long long INF=0x3f3f3f3f;

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int dp[205][10];//[个数][堆数]
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    dp[2][1]=1;dp[2][2]=1;
    dp[3][1]=1;dp[3][2]=1;dp[3][3]=1;
    dp[4][1]=1;dp[4][2]=2;dp[4][3]=1;dp[4][4]=1;
    dp[5][1]=1;dp[5][2]=2;dp[5][3]=2;dp[5][4]=1;dp[5][5]=1;
    dp[6][1]=1;dp[6][2]=3;dp[6][3]=3;dp[6][4]=2;dp[6][5]=1;dp[6][6]=1;
    _rep(i,7,n)
    {
        _rep(j,1,k)
        {
            dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
            //把i个分成j堆，就是抽掉所有的1堆，以及把每个堆抽掉一个
        }
    }
    cout<<dp[n][k];
    return 0;
}
