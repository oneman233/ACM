#include <bits/stdc++.h>
using namespace std;

int n;
string a,b,c;
int dp[155][155][155];
int fa[155],fb[155],fc[155];

int rongchi(int i,int j,int k)
{
    return dp[i-1][j][k]+dp[i][j-1][k]+dp[i][j][k-1]-dp[i-1][j-1][k]
           -dp[i-1][j][k-1]-dp[i][j-1][k-1]+dp[i-1][j-1][k-1];
}

void pre()
{
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=0;
    map<char,int> m;
    for(char c='a';c<='z';++c)
        m[c]=1;
    for(int i=0;i<n;++i){
        fa[i+1]=m[a[i]];
        m[a[i]]=i+1;
    }
    for(char c='a';c<='z';++c)
        m[c]=1;
    for(int i=0;i<n;++i){
        fb[i+1]=m[b[i]];
        m[b[i]]=i+1;
    }
    for(char c='a';c<='z';++c)
        m[c]=1;
    for(int i=0;i<n;++i){
        fc[i+1]=m[c[i]];
        m[c[i]]=i+1;
    }
}

int main()
{
    cin>>n>>a>>b>>c;
    pre();
    for(int i=1;i<=n;++i)
        cout<<fc[i]<<' ';
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                if(a[i-1]==b[j-1]&&b[j-1]==c[k-1])
                    dp[i][j][k]=2*dp[i-1][j-1][k-1]-dp[fa[i]-1][fb[j]-1][fc[k]-1];
                else
                    dp[i][j][k]=rongchi(i,j,k);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                ans+=dp[i][j][k];
    cout<<dp[n][n][n];
    return 0;
}
