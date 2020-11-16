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

int n;
string s;
set<string> se;

int main()
{
    cin>>n;
    while(n--)
    {
        cin>>s;
        se.insert(s);
    }
    cout<<se.size();
    return 0;
}
