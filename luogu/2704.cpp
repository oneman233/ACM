#include <bits/stdc++.h>
#define re(i,n) for(int i=1;i<=n;++i)
#define vec vector<int>
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;

int n,m;
char p[105][15];
ll dp[105][1025];
vector<vec >law;

void getlaw()
{
    for(int i=0;i<(1<<m);++i){
        vec v;
        for(int j=m-1;j>=0;--j){
            if(i&(1<<j)) v.pb(1);
            else v.pb(0);
        }
        bool can=true;
        for(int j=0;j<=v.size()-3;++j){
            if(v[j]+v[j+1]+v[j+2]>=2){
                can=false;
                break;
            }
        }
        if(can) law.pb(v);
    }
}

bool ok1(int x,vec s)
{
    for(int i=0;i<s.size();++i){
        if(s[i]==1&&p[x][i+1]=='H')
            return false;
    }
    return true;
}

bool ok2(vec a,vec b,vec c)
{
    for(int i=0;i<a.size();++i){
        if(a[i]+b[i]+c[i]>=2)
            return false;
    }
    return true;
}

ll cnt(vec a)
{
    ll as=0;
    for(int i=0;i<a.size();++i)
        if(a[i]==1)
            as++;
    return as;
}

bool non_eql(int j,int x,int y)
{
    return x!=y&&x!=j&&y!=j;
}

int main()
{
    memset(dp,0,sizeof(dp));
    cin>>n>>m;
    re(i,n)
    {
        getchar();
        re(j,m)
        {
            cin>>p[i][j];
        }
    }
    getlaw();
    for(int i=0;i<law.size();++i)
        if(ok1(1,law[i]))
            dp[1][i]=cnt(law[i]);
    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<law.size();++j){
            if(ok1(i,law[j])){
                for(int x=0;x<law.size();++x){
                    for(int y=0;y<law.size();++y){
                        if(ok2(law[j],law[x],law[y])&&noneql(j,x,y)){
                            dp[i][j]=max(dp[i][j],dp[i-2][x]+dp[i-1][y]+cnt(law[j]));
                        }
                    }
                }
            }
        }
    }
    ll ans=-100;
    for(int i=0;i<law.size();++i)
        ans=max(ans,dp[3][i]);
    cout<<ans;
    return 0;
}
/*
3 10
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP
*/
