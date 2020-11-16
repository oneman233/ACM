#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

vector<int> v;
int n,tmp;
int ans=0,dp[100005];

void clean()
{
    for(int i=0;i<n;++i)
        dp[i]=1;
    ans=0;
}

int main()
{
    while(scanf("%d",&tmp)!=EOF)
        v.pb(tmp);
    n=v.size();
    /*
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        v.pb(tmp);
    }
    */
    clean();
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(v[i]<=v[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    for(int i=0;i<n;++i)
        ans=max(ans,dp[i]);
    cout<<ans<<" ";
    clean();
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(v[i]>v[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    for(int i=0;i<n;++i)
        ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}
