#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pu(a) push_back(a)
#define po() pop_back()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=300000;
const int inf=1e9;
typedef long long ll;

int n,m,t;
int x,y,ans=-100;
int dis[305][305];

int main()
{
    scii(n,m);
    sci(t);
    re(i,0,n-1)
    {
        re(j,0,n-1)
        {
            dis[i][j]=inf;
        }
    }
    re(i,0,n-1)
        dis[i][i]=0;
    while(m--){
        scii(x,y);
        dis[x][y]=dis[y][x]=1;
    }
    re(k,0,n-1)
    {
        re(i,0,n-1)
        {
            re(j,0,n-1)
            {
                if(i!=j)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    re(i,0,n-1)
    {
        re(j,0,n-1)
        {
            ans=max(ans,dis[i][j]);
        }
    }
    ///cout<<ans<<endl;
    if(ans<=t){
        cout<<"Win";
    }
    else{
        cout<<"Fail";
    }
    return 0;
}
