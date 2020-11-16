#include <bits/stdc++.h>
using namespace std;

int t,e,f,n;
int p[505],w[505];
int dp[10005];

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&e,&f);
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d %d",&p[i],&w[i]);
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=n;++i){
            for(int j=w[i];j<=(f-e);++j){
                dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
            }
        }
        if(dp[f-e]<0x3f3f3f3f)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f-e]);
        else
            printf("This is impossible.\n");
    }
    return 0;
}
