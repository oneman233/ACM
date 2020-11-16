#include <bits/stdc++.h>
using namespace std;

string a,b;
int dp[1005][1005];

int main()
{
    cin>>a>>b;
    int lena=a.length(),lenb=b.length();
    ///从1开始不考虑0-1的情况
    for(int i=1;i<=lena;++i)
    {
        for(int j=1;j<=lenb;++j)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[lena][lenb];
    return 0;
}
