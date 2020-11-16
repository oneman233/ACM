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
const int maxn=10000;
typedef long long ll;

int t,n,m;
int a[maxn+5];
map<int,int> vis;
int sum;
bool gcd_one=false;

int main()
{
    sci(t);
    re(Case,1,t)
    {
        memset(a,0,sizeof(a));
        vis.clear();
        sum=0;
        gcd_one=false;
        ///init
        scii(n,m);
        re(i,1,n)
            sci(a[i]);
        re(i,1,n)
        {
            int gcd=__gcd(a[i],m);
            if(gcd==1)
            {
                gcd_one=true;
                break;
            }
            else
            {
                for(int j=0;j<m;j+=gcd)
                {
                    if(vis[j]==0){
                        sum+=j;
                        vis[j]++;
                    }
                }
            }
        }
        if(gcd_one)
            printf("Case #%d: %d",Case,m*(m-1)/2);
        else
            printf("Case #%d: %d",Case,sum);
        prn();
    }
    return 0;
}
