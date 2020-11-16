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
const int MAX=500000;
const int inf=0x3f3f3f3f;
typedef long long ll;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int n,k;
double line[10005],big=-1.0;

int main()
{
    scii(n,k);
    fo(i,0,n)
    {
        scd(line[i]);
        big=max(big,line[i]);
    }
    sort(line,line+n);
    double l=0.01,r=100000,mid;
    int c=10000;
    while(c--){
        mid=(l+r)/2.0;
        int cnt=0;
        fo(i,0,n)
            cnt+=floor(line[i]/mid);
        if(cnt<k)
            r=mid;
        else
            l=mid;
    }
    printf("%.2lf",mid);
    return 0;
}
/*
4 11
8.02
7.43
4.57
5.39
*/
