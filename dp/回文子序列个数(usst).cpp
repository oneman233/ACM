#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long dp[55][55];
    string s;
    cin>>s;
    for(int i=0;i<s.length();++i)
        dp[i][i]=1;
        ///��ʼ��
    for(int j=0;j<s.length();++j)
    {
        for(int i=j-1;i>=0;--i)
        {
            if(s[i]==s[j])
                dp[i][j]+=dp[i+1][j]+dp[i][j-1]+1;
            ///����ȥ��ͷβ�Ŀ����γɶԳƣ����Լ��������γ�һ��Գ�
            else
                dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                ///ȥ��ͷβ�Ĳ����γɶԳ�
        }
    }
    cout<<dp[0][s.length()-1];
    return 0;
}
