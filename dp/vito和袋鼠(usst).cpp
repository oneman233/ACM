#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const int Max=10000;
int n;
int hi[Max+5],dp[Max+5];
int ans=Max+5;

///dp��dfs�Ż��˴����ٱ���ʱ��

int main()
{

    cin>>n;
    _for(i,0,n)
        cin>>hi[i];
    _for(i,0,n)
        dp[i]=Max+5;
        ///�ִ�ĳһλ���������С����
    dp[0]=0;
    ///��ʼλ���趨
    _for(i,0,n)
    {
        if(i+hi[i]>=n&&dp[i]!=Max+5)
        {
            cout<<dp[i]+1;
            return 0;
        }
        ///ֱ�������ӣ����������
        _for(j,0,hi[i]+1)
            dp[i+j]=min(dp[i]+1,dp[i+j]);
            ///��ĳһ������������������Щ���ӵ���С����
    }
    cout<<-1;
    ///��������
    return 0;
}
