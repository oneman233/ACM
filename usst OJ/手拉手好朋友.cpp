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
typedef long long ll;

int n,m,k;
ll c[101][101],ans=0;

int main()
{
    scii(n,m);
    sci(k);
    c[0][0]=1;
    re(i,1,100)
    {
        c[i][0]=c[i][i]=1;
        re(j,1,i-1)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    re(i,4,n)
    {
        if(k-i<2)
            break;
        ans+=c[n][i]*c[m][k-i];
    }
    prl(ans);
    return 0;
}
