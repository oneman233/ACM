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
string s;

void m()
{
    if(ans>0)
        ans--;
}

void a()
{
    if(ans<n)
        ans++;
}

int main()
{
    cin>>n>>s;
    for(int i=0;i<s.length();++i){
        if(s[i]=='-')
            m();
        else
            a();
    }
    cout<<ans;
    return 0;
}
