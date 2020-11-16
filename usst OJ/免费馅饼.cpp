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
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
#define endl "\n"
using namespace std;
const int MAX=500000;
const int inf=0x3f3f3f3f;
typedef long long ll;
template <typename t>
t mmax(t a,t b,t c)
{
    return max(a,max(b,c));
}
template <typename t>
t mmin(t a,t b,t c)
{
    return min(a,min(b,c));
}

int n,t,x;
int a[100005][12],dp[100005][12];

int main()
{
    while(scanf("%d",&n)){
        int maxt=0;
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        if(n==0)
            break;
        for(int i=0;i<n;++i){
            scanf("%d %d",&x,&t);
            a[t][x]++;
            maxt=max(t,maxt);
        }
        for(int i=maxt;i>=0;--i){
            for(int j=0;j<=10;++j){
                if(j==0)
                    dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
                else if(j==10)
                    dp[i][j]=max(dp[i+1][j],dp[i+1][j-1])+a[i][j];
                else
                    dp[i][j]=mmax(dp[i+1][j],dp[i+1][j-1],dp[i+1][j+1])+a[i][j];
            }
        }
        printf("%d\n",dp[0][5]);
    }
    return 0;
}
