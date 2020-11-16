#include <bits/stdc++.h>
using namespace std;

int t,n,m,ans=0;
int p[10][10];
int dp[10][100];
int x[8]={1,1,1,-1,-1,-1,0,0};
int y[8]={0,1,-1,0,1,-1,1,-1};

bool chk1(int state)
{
    int tmp[10];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<m;++i)
        if(state&(1<<i))
            tmp[m-1-i]=1;
    for(int i=1;i<m-1;++i)
        if(tmp[i]==1&&(tmp[i-1]==1||tmp[i+1]==1))
            return false;
    if(tmp[0]==1&&tmp[1]==1)
        return false;
    if(tmp[m-1]==1&&tmp[m-2]==1)
        return false;
    return true;
}

bool chk(int i,int j)
{
    if(i<0||i>1||j<0||j>=m)
        return false;
    return true;
}

bool chk2(int a,int b)
{
    if(a==0||b==0)
        return true;
    int tmp[2][10];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<m;++i){
        if(a&(1<<i))
            tmp[0][m-1-i]=1;
        if(b&(1<<i))
            tmp[1][m-1-i]=1;
    }
    for(int i=0;i<2;++i){
        for(int j=0;j<m;++j){
            if(tmp[i][j]==1){
                for(int k=0;k<8;++k){
                    if(chk(i+x[k],j+y[k])&&tmp[i+x[k]][j+y[k]]==1)
                        return false;
                }
            }
        }
    }
    return true;
}

int cnt(int x,int state)
{
    int tmp[10];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<m;++i)
        if(state&(1<<i))
            tmp[m-1-i]=1;
    int sum=0;
    for(int i=0;i<m;++i)
        if(tmp[i]==1)
            sum+=p[x][i+1];
    return sum;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        ans=0;
        memset(dp,0,sizeof(dp));
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scanf("%d",&p[i][j]);
        for(int i=1;i<=n;++i){
            for(int a=0;a<(1<<m);++a){
                if(!chk1(a))
                    continue;
                for(int b=0;b<(1<<m);++b){
                    if((!chk1(b))||(!chk2(a,b))){
                        continue;
                    }
                    dp[i][a]=max(dp[i][a],dp[i-1][b]);
                }
                dp[i][a]+=cnt(i,a);
            }
        }
        for(int i=0;i<(1<<m);++i)
            ans=max(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
