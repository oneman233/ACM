#include<bits/stdc++.h>
using namespace std;

int n;
int dp[2010][2010],a[2010];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        dp[i][i]=a[i]*n;///��n���ʱ������
    }
    for(int l=2;l<=n;++l)
    {
        for(int i=1;(i+l-1)<=n;++i)
        {
            int j=i+l-1;
            dp[i][j]=max(dp[i+1][j]+a[i]*(n-l+1),dp[i][j-1]+a[j]*(n-l+1));
        }
    }
    ///l��������������м�����
    ///n-l�����ȥ��������ʣ�¼�����
    ///ʱ���1��ʼ�������ȫ��ȡ��ʱ��ʱ��������1+n-l
    cout<<dp[1][n];
    return 0;
}
