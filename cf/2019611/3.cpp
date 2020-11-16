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

int n,len=0;
string ttt="aeiou";
string s;
vector<vector<string> > v[5];
vector<string> you,zuo;

int ct(string s)
{
    int as=0;
    fo(i,0,s.length())
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            as++;
    }
    return as;
}

char fi(string s)
{
    rre(i,s.length()-1,0)
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            return s[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    map<char,int>m;
    fo(i,0,5)
        m[ttt[i]]=i;
    fo(i,0,5)
        v[m[ttt[i]]].reserve(1000005);
    re(i,1,n)
    {
        cin>>s;
        int cnt=ct(s);
        len=max(cnt,len);
        v[m[fi(s)]][cnt].pub(s);
    }
    //cout<<len<<endl;
    fo(i,0,5)
    {
        re(j,1,len)
        {
            while(v[i][j].size()>=2){
                int s=v[i][j].size();
                //cout<<s<<endl;
                you.pub(v[i][j][s-1]);
                you.pub(v[i][j][s-2]);
                v[i][j].pob();
                v[i][j].pob();
            }
        }
    }
    re(i,1,len)
    {
        fo(j,0,5)
        {
            for(int k=0;k<v[j][i].size();k++)
                zuo.pub(v[j][i][k]);
        }
        if(zuo.size()&1)
            zuo.pob();
    }
    //cout<<zuo.size()<<" "<<you.size()<<endl;
    int ans=min((zuo.size()+you.size())/4,you.size()/2);
    cout<<ans<<endl;
    int cnt=0;
    while(zuo.size()>=2 && you.size()>=2){
        cout<<zuo.back()<<" "<<you.back()<<'\n';
        zuo.pob();  you.pob();
        cout<<zuo.back()<<" "<<you.back()<<'\n';
        zuo.pob();  you.pob();
        ++cnt;
    }
    while(cnt<ans){
        cout<<you.back()<<" ";
        you.pob();
        string sss=you.back();
        you.pob();
        cout<<you.back()<<'\n';
        you.pob();
        cout<<sss<<" ";
        cout<<you.back()<<'\n';
        you.pob();
        ++cnt;
    }
    return 0;
}
