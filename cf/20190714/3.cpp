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
#define debug(a) cout<<a<<endl
using namespace std;
typedef long long ll;
const ll maxn=500005;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int q;
string s,t,p;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>q;
    while(q--){
        cin>>s>>t>>p;
        if(s==t){
            cout<<"YES"<<endl;
            continue;
        }
        if(s.length()>=t.length()||t.length()>s.length()+p.length()){
            cout<<"NO"<<endl;
            continue;
        }
        map<char,int> ms,mt;
        for(int i=0;i<s.length();++i)
            ms[s[i]]++;
        for(int i=0;i<p.length();++i)
            ms[p[i]]++;
        for(int i=0;i<t.length();++i)
            mt[t[i]]++;
        bool can=true;
        for(char i='a';i<='z';++i){
            if(ms[i]<mt[i]){
                can=false;
                break;
            }
        }
        if(!can){
            cout<<"NO"<<endl;
            continue;
        }
        int i=0;
        for(int j=0;j<t.length();++j){
            if(t[j]==s[i]){
                ms[s[i]]--;
                mt[t[j]]--;
                i++;
            }
        }
        if(i!=s.length()){
            cout<<"NO"<<endl;
            continue;
        }
        can=true;
        for(char i='a';i<='z';++i){
            if(ms[i]<mt[i]){
                can=false;
                break;
            }
        }
        if(can)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
