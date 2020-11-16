#include <bits/stdc++.h>
using namespace std;

long long dp[25][25];
int x,y,a,b;

bool ok(int i,int j)
{
    if(i>x||j>y)
        return false;
    if((abs(i-a)==2&&abs(j-b)==1)||(abs(i-a)==1&&abs(j-b)==2)||(i==a&&j==b))
        return false;
    return true;
}

int main()
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    cin>>x>>y>>a>>b;
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(ok(i+1,j))
                dp[i+1][j]+=dp[i][j];
            if(ok(i,j+1))
                dp[i][j+1]+=dp[i][j];
        }
    }
    cout<<dp[x][y];
    return 0;
}
