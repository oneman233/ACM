#include <bits/stdc++.h>
using namespace std;

int n,a[110],sum=0,dp[101][10000];

int main()
{
    ///dp����ѡ�񼸸���ʱ������ֵ
    ///ÿ���˾���һ��ѡ�񣬹���Ϊa[i]������Ϊ1
    ///��������Ϊn/2
    ///����ѡһ���ˣ�dp[0]=0
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ///read
    memset(dp,0,sizeof(dp));
    ///init
    for(int i=0;i<n;++i)
    {
        for(int j=n/2;j>=1;--j)
        {
            for(int k=sum/2;k>=a[i];--k)
            {
                dp[j][k]=max(dp[j][k],dp[j-1][k-a[i]]+a[i]);
            }
        }
    }
    cout<<dp[n/2][sum/2];
    return 0;
}
