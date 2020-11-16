#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,v[205],dp[205][205];
    memset(dp,0,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    v[0]=v[n+1]=1;
    for(int len=1;len<=n;++len){
        for(int i=1;i<=n;++i){
            int j=i+len;
            if(j>n+1)
                break;
            for(int k=i;k<j;++k)
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+v[k]*v[i-1]*v[j]);
        }
    }
    /*
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n+1;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<dp[1][n+1];
    return 0;
}
/*
3
1 2 3
*/
