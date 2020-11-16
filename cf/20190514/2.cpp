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

bool chk()
{
    if(s.length()==0)
        return true;
    if(s.length()%2!=0)
        return false;
    for(int i=0;i<=s.length()-1;i+=2)
        if(s[i]==s[i+1])
            return false;
    return true;
}

int main()
{
    cin>>n;
    cin>>s;
    while(!chk()){
        for(int i=0;i<=s.length()-1;i+=2){
            while(s[i]==s[i+1]){
                s.erase(i+1,1);
                ans++;
            }
        }
        if(s.length()&1){
            ans++;
            s.erase(s.length()-1,1);
        }
    }
    cout<<ans<<endl;
    cout<<s;
    return 0;
}
