#include <bits/stdc++.h>

using namespace std;

bool ok(int i,int j,int n,int m,int x,int y)//判断能不能往下走
{
    if(i>n||j>m)//出界
        return false;
    if(i==x&&j==y)//位于障碍点
        return false;
    if(abs(i-x)==1&&abs(j-y)==2)//位于障碍点控制点，四种情况
        return false;
    if(abs(i-x)==2&&abs(j-y)==1)//位于障碍点控制点，四种情况
        return false;
    return true;
}

int main()
{
    long long dp[25][25];
    int i,j;
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    memset(dp,0,sizeof(dp));//清零
    dp[0][0]=1;//赋初始值
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            //遍历所有格子，如果能走就把当前走法种数加上去
            if(ok(i+1,j,n,m,x,y))
                dp[i+1][j]+=dp[i][j];
            if(ok(i,j+1,n,m,x,y))
                dp[i][j+1]+=dp[i][j];
        }
    }
    cout<<dp[n][m];//打印结果
    return 0;
}
