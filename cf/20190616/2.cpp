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

int n,l=-1,r=-1;
string s;

string add(string a,string b)
{
    while(a.length()<b.length())
        a.insert(a.begin(),'0');
    while(b.length()<a.length())
        b.insert(b.begin(),'0');
    vector<int> as;
    for(int i=0;i<a.length();++i)
        as.pub(a[i]+b[i]-2*'0');
    for(int i=as.size()-1;i>=1;--i){
        if(as[i]>=10){
            as[i-1]++;
            as[i]%=10;
        }
    }
    if(as[0]>=10){
        as.insert(as.begin(),1);
        as[1]%=10;
    }
    string ss="";
    for(int i=0;i<as.size();++i){
        ss.append(1,as[i]+'0');
    }
    return ss;
}

bool isbig(string a,string b)
{
    if(a.length()>b.length())
        return true;
    else if(a.length()<b.length())
        return false;
    else{
        for(int i=0;i<a.length();++i){
            if(a[i]<b[i])
                return false;
            else if(a[i]>b[i])
                return true;
        }
        return false;
    }
}

int main()
{
    cin>>n>>s;
    for(int i=n/2;i>=0;--i){
        if(s[i]!='0'){
            l=i;
            break;
        }
    }
    for(int i=n/2+1;i<n;++i){
        if(s[i]!='0'){
            r=i;
            break;
        }
    }
    string rs,ls;
    if(r!=-1)
        rs=add(s.substr(0,r),s.substr(r,n-r));
    if(l!=-1)
        ls=add(s.substr(0,l),s.substr(l,n-l));
    if(l==-1){
        cout<<rs;
        return 0;
    }
    if(r==-1){
        cout<<ls;
        return 0;
    }
/*
    cout<<rs<<" "<<ls<<endl;
    cout<<s.substr(0,r)<<" "<<s.substr(r,n-r)<<endl;
    cout<<s.substr(0,l)<<" "<<s.substr(l,n-l)<<endl;
*/
    if(isbig(rs,ls))
        cout<<ls;
    else
        cout<<rs;
    return 0;
}
