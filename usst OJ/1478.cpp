#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s,a,b;
    int x[5005],y[5005];
    cin>>n>>s;
    cin>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];//��һ�б��ڿ��ƺ����i-1
    int dp[5005][1005];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)//����ƻ�����
    {
        for(int j=0;j<=s;j++)//������������
        {
            dp[i][j]=dp[i-1][j];//��������ô��
            if(j>=y[i]&&x[i]<=a+b)//�߶ȹ��������Ĺ�
                dp[i][j]=max(dp[i][j],dp[i-1][j-y[i]]+1);
        }
    }
    cout<<dp[n][s];
    return 0;
}
