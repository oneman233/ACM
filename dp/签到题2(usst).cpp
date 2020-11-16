#include <bits/stdc++.h>
using namespace std;

int n;
int a[10010];
int dp[100010];
bool can=true;

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;++i)
    {
        for(int j=90000;j>=a[i];j--)
            dp[j]+=dp[j-a[i]];
    }
    for(int i=1;i<=90000;++i)
        if(dp[i]==0)
        {
            cout<<i;
            can=false;
            break;
        }
    if(can)
    {
        long long sum=0;
        for(int i=0;i<n;++i)
            sum+=a[i];
        cout<<sum+1;
    }
    return 0;
}
