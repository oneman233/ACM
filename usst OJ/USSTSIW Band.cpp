#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define scs(a) scanf("%s",a)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define prd(a) printf("%lf",a)
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
const int MAX=100;
const int inf=0x3f3f3f3f;
const double pi=3.1415926535;
typedef long long ll;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int n,t,m;
int a[MAX+5];
int dp[MAX+5][MAX+5];
///j背包中的剩余容量为k

void read()
{
    scii(n,t);
    sci(m);
    re(i,1,n)
        sci(a[i]);
}

int main()
{
    read();
    re(i,1,n)
    ///歌曲从前往后
    {
        for(int j=m;j>=1;--j)
        ///背包从后往前
        ///这样j与j-1背包就不会互相影响
        {
            for(int k=t;k>=a[i];--k)
            {
                /*
                dp[j][k]=max(dp[j][k],dp[j][k-a[i]]+1);
                ///装到第j个
                dp[j][k]=max(dp[j][k],dp[j-1][t]+1);
                ///装到j-1个
                */
                dp[j][k]=mmax(dp[j][k],dp[j][k-a[i]]+1,dp[j-1][t]+1);
                ///随时新开一个背包？
            }
        }
    }
    pri(dp[m][t]);
    return 0;
}
