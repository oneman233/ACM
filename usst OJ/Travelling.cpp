#include <bits/stdc++.h>

using namespace std;

bool ok(int i,int j,int n,int m,int x,int y)//�ж��ܲ���������
{
    if(i>n||j>m)//����
        return false;
    if(i==x&&j==y)//λ���ϰ���
        return false;
    if(abs(i-x)==1&&abs(j-y)==2)//λ���ϰ�����Ƶ㣬�������
        return false;
    if(abs(i-x)==2&&abs(j-y)==1)//λ���ϰ�����Ƶ㣬�������
        return false;
    return true;
}

int main()
{
    long long dp[25][25];
    int i,j;
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    memset(dp,0,sizeof(dp));//����
    dp[0][0]=1;//����ʼֵ
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            //�������и��ӣ�������߾Ͱѵ�ǰ�߷���������ȥ
            if(ok(i+1,j,n,m,x,y))
                dp[i+1][j]+=dp[i][j];
            if(ok(i,j+1,n,m,x,y))
                dp[i][j+1]+=dp[i][j];
        }
    }
    cout<<dp[n][m];//��ӡ���
    return 0;
}
