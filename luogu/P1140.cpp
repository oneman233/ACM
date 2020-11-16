#include <bits/stdc++.h>
using namespace std;

int m[5][5]=
{
    5,-1,-2,-1,-3,
    -1,5,-3,-2,-4,
    -2,-3,5,-2,-2,
    -1,-2,-2,5,-1,
    -3,-4,-2,-1,0
};
int aa,bb;
string a,b;
int dp[105][105];

int f(char c)
{
    if(c=='A')
        return 0;
    else if(c=='C')
        return 1;
    else if(c=='G')
        return 2;
    else if(c=='T')
        return 3;
    else if(c=='-')
        return 4;
}

int main()
{
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;///- and -
    cin>>aa>>a;
    for(int i=1;i<=aa;++i)
        dp[i][0]=dp[i-1][0]+m[f(a[i-1])][4];
    cin>>bb>>b;
    for(int i=1;i<=bb;++i)
        dp[0][i]=dp[0][i-1]+m[4][f(b[i-1])];
    for(int i=1;i<=aa;++i){
        for(int j=1;j<=bb;++j){
            dp[i][j]=max(dp[i][j],dp[i-1][j]+m[f(a[i-1])][4]);
            dp[i][j]=max(dp[i][j],dp[i][j-1]+m[4][f(b[j-1])]);
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+m[f(a[i-1])][f(b[j-1])]);
        }
    }
    cout<<dp[aa][bb];
    return 0;
}
