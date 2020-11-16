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
using namespace std;
const int maxn=300000;
typedef long long ll;

double a,b,c,d,l,r;
double f()
{
    return c/a*(r-l)+(d/a-b*c/a/a)*log((a*r+b)/(a*l+b));
}

int main()
{
    cin>>a>>b>>c>>d>>l>>r;
    if(a==0)
        printf("%.6lf",c/b/2*(r-l)*(r+l)+d/b*(r-l));
    else
        printf("%.6lf",f());
    return 0;
}
