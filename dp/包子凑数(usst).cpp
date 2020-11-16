#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[110];
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int dp[10010];
    dp[0]=1;///钱刚好花完算一种
    for(int i=0;i<n;++i)
    {
        for(int j=a[i];j<=10000;++j)
            dp[j]+=dp[j-a[i]];
    }
    int zero=0;
    for(int i=1;i<=10000;++i)
        if(dp[i]==0)
            ++zero;
    if(zero>=3000)
        cout<<"INF";
    else
        cout<<zero;
    return 0;
}
