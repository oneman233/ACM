#include <bits/stdc++.h>
using namespace std;
const int maxn=100000;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        int dp[maxn],a[maxn];
        for(int i=0;i<n;++i)
            cin>>a[i];
        for(int i=0;i<n;++i)
            dp[i]=a[i];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(a[i]>a[j])
                    dp[i]=max(dp[i],dp[j]+a[i]);
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
            ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
    return 0;
}
