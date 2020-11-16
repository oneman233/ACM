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

int n,ans=0;
int x[10005],y[10005];

int main()
{
    sci(n);
    fo(i,0,n)
        scii(x[i],y[i]);
    fo(i,0,n)
    {
        bool can=true;
        fo(j,0,n)
        {
            if((x[j]<x[i]&&y[j]<=y[i])||(x[j]<=x[i]&&y[j]<y[i])){
                can=false;
                break;
            }
        }
        if(can)
            ans++;
    }
    pri(ans);
    return 0;
}
