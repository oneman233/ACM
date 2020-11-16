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

int n,m;
string s,f;
vector<int> cnt[30];

int main()
{
    cin>>n>>s>>m;
    for(int i=0;i<n;++i){
        //cout<<s[i]-'a'<<endl;
        cnt[s[i]-'a'].push_back(i);
    }
    while(m--){
        cin>>f;
        map<char,int> m;
        for(int i=0;i<f.length();++i)
            m[f[i]]++;
        int ans=-100;
        for(char i='a';i<='z';++i){
            //cout<<cnt[i-'a'][m[i]-1]<<endl;
            if(m[i]>=1)
                ans=max(ans,cnt[i-'a'][m[i]-1]);
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
