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
#define pb(a) push_back(a)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=300000;
typedef long long ll;

int n;
string s;
int f[10];

int g(char c)
{
    return c-'0';
}

int main()
{
    sci(n);
    cin>>s;
    re(i,1,9)
        sci(f[i]);
    int idx=0;
    while(f[g(s[idx])]<=g(s[idx])&&idx<s.length())
        ++idx;
    while(idx<s.length())
    {
        if(f[g(s[idx])]>=g(s[idx]))
            s[idx]=f[g(s[idx])]+'0';
        else
            break;
        ++idx;
    }
    cout<<s;
    return 0;
}
