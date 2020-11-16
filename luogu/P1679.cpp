#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int main()
{
    int m;
    cin>>m;
    vector<int> v;
    for(int i=1;i*i*i*i<=m;++i)
        v.push_back(i*i*i*i);
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<v.size();++i){
        for(int j=v[i];j<=m;++j){
            dp[j]=min(dp[j],dp[j-v[i]]+1);
        }
    }
    cout<<dp[m];
    return 0;
}
