#include <bits/stdc++.h>
//#define debug
using namespace std;

int t,tot=0;
int num[1000001],cnt[10],dp[9];
int pre[1000001][9];

int main()
{
    scanf("%d",&t);
    while(t--){
        tot=0;
        for(int i=0;i<=9;++i){
            scanf("%d",&cnt[i]);
            if(i!=0&&i!=9){
                for(int j=tot;j<tot+cnt[i];++j)
                    num[j]=i;
                tot+=cnt[i];
            }
        }
        memset(dp,-0x3f,sizeof(dp));
        memset(pre,0,sizeof(pre));
        dp[0]=0;
        for(int i=0;i<tot;++i){
            for(int j=8;j>=num[i];--j){
                if(dp[j]>dp[(j-num[i]+9)%9]+1){
                    pre[i][j]=0;

                }
                else{
                    pre[i][j]=1;

                }
                ///dp[j]=max(dp[j],dp[(j-num[i]+9)%9]+1);
            }
        }
        #ifdef debug
        for(int i=0;i<tot;++i)
            cout<<num[i]<<' ';
        cout<<endl;
        for(int i=0;i<=8;++i)
            cout<<dp[i]<<' ';
        cout<<endl;
        #endif
        if(dp[0]==0)
            printf("-1\n");
        else{

        }
    }
    return 0;
}
/*
100
0 0 0 0 0 0 0 0 1 0
0 1 0 0 1 1 0 0 1 0
*/
