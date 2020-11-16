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

int main()
{
    int n;
    int man[1005][5],ans=0;
    int sum[5];
    memset(sum,0,sizeof(sum));
    cin>>n;
    fo(i,0,n)
    {
        int cnt=0;
        fo(j,0,5)
            cin>>man[i][j],cnt+=man[i][j],sum[j]+=man[i][j];
        if(cnt>=5)
            ans++;
    }
    int ans2=inf;
    fo(i,0,5)
        ans2=min(ans2,sum[i]);
    pri(min(ans,ans2));
    return 0;
}
