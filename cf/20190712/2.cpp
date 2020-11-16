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

string a,b,c;
map<string,int> m;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>c;
    m[a]++;m[b]++;m[c]++;
    if(m.size()==1){
        cout<<0;
        return 0;
    }
    if(m.size()==2){
        cout<<1;
        return 0;
    }
    else{
        int aa=a[0]-'0';
        int bb=b[0]-'0';
        int cc=c[0]-'0';
        vector<int> v;
        v.pub(aa);
        v.pub(bb);
        v.pub(cc);
        sort(v.begin(),v.end());
        if(a[1]==b[1]&&b[1]==c[1]){
            if(v[0]==v[1]-1&&v[1]==v[2]-1)
                cout<<0;
            else{
                if(v[0]==v[1]-1||v[1]==v[2]-1||v[0]==v[2]-2||v[1]==v[2]-2||v[0]==v[1]-2)
                    cout<<1;
                else
                        cout<<2;
            }
        }
        else{
            if((a[1]==b[1]&&abs(aa-bb)==1)||(b[1]==c[1]&&abs(bb-cc)==1)||(a[1]==c[1]&&abs(aa-cc)==1))
                cout<<1;
            else
                cout<<2;
        }
    }
    return 0;
}
