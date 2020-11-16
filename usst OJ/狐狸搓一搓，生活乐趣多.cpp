#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scc(a) scanf("%c",&a)
#define scs(a) scanf("%s",a)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define prc(a) printf("%c",a)
#define prs(a) printf("%s",a)
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
const int mod=19260817;
typedef long long ll;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int n,m,s,t;
ll dp[25][105];

int main()
{
    scii(n,m);
    scii(s,t);
    memset(dp,0,sizeof(dp));
    dp[m][s]=1;
    rre(i,m-1,0)
    {
        re(j,1,n)
        {
            if(j==1)
                dp[i][j]=dp[i+1][2]%mod;
            else if(j==n)
                dp[i][j]=dp[i+1][n-1]%mod;
            else
                dp[i][j]=(dp[i+1][j-1]+dp[i+1][j+1])%mod;
        }
    }
    prl(dp[0][t]);
    return 0;
}
