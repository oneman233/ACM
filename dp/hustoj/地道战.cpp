#include <bits/stdc++.h>
using namespace std;
const int INF=1000000;

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int dp[110][110];
        int heng[110][110],zong[110][110];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m-1;++j){
            scanf("%d",&heng[i][j]);
            }
        }
        for(int j=1;j<=m;++j){
            for(int i=1;i<=n-1;++i){
                scanf("%d",&zong[i][j]);
            }
        }
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=m;++j)
            {
                dp[i][j]=INF;
            }
        }
        dp[1][1]=0;
        ///init
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                dp[i][j]=min(dp[i][j],min(dp[i][j-1]+heng[i][j-1],dp[i-1][j]+zong[i-1][j]));
            }
        }
        printf("%d\n",dp[n][m]);
        /*
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        */
    }
    return 0;
}
