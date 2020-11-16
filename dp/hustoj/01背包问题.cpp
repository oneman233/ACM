#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c,n;
    while(cin>>c>>n)
    {
        int w[10000];
        double p[10000];
        double dp[10000];
        for(int i=0;i<n;++i)
            cin>>w[i]>>p[i];
        for(int i=0;i<n;++i)
        {
            for(int j=c;j>=w[i];--j)
                dp[j]=max(dp[j],dp[j-w[i]]+p[i]);
        }
        int wei,pri;
        int tmp=dp[1]/1.0;
        for(int i=2;i<=c;++i)
        {
            if(dp[i]/i>tmp)
            {
                pri=dp[i];
                wei=i;
            }
        }
        cout<<wei<<" "<<pri<<endl;
    }
    return 0;
}
