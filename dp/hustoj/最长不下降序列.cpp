#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int a[1005];
        for(int i=0;i<n;++i)
            cin>>a[i];
        int dp[1005];
        for(int i=0;i<n;++i)
            dp[i]=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(a[i]>=a[j])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        /*
        for(int i=0;i<n;++i)
            cout<<dp[i]<<" ";
        */
        int big=0;
        for(int i=0;i<n;++i)
            big=max(big,dp[i]);
        cout<<big<<endl;
    }
    return 0;
}
