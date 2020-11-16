#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
int dp[100005][30];

void build()
{
    for(int i=1;i<=n;++i)
        dp[i][0]=a[i];
    for(int j=1;j<=30;++j){
        for(int i=1;i+(1LL<<(j-1))<=n;++i){
            dp[i][j]=max(dp[i][j-1],dp[i+(1LL<<(j-1))][j-1]);
        }
    }
}

int q(int l,int r)
{
    int k=log2(r-l+1);
    return max(dp[l][k],dp[r-(1LL<<k)+1][k]);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    build();
    int x,y;
    while(m--){
        scanf("%d %d",&x,&y);
        printf("%d\n",q(x,y));
    }
    return 0;
}
