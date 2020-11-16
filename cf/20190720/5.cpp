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
#define int long long
using namespace std;
typedef long long ll;
const ll maxn=100005;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

string s,le,ri;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    map<char,int> m;
    for(int i=0;i<s.length();++i)
        m[s[i]]++;
    int mx=-inf;
    char cc;
    for(char c='a';c<='c';++c){
        if(m[c]>mx){
            mx=m[c];
            cc=c;
        }
    }
    if(mx>=s.length()/2){
        for(int i=0;i<mx;++i)
            cout<<cc;
    }
    else{
        int l=1,r=s.length()-2;
        while(l<=r){
            if(l==r){
                le+=s[l];
                break;
            }
            else{
                if(s[l-1]==s[r+1]){
                    le+=s[l-1];
                    ri+=s[r+1];
                    l++;
                    r--;
                }
                else if(s[l-1]==s[r]){
                    le+=s[l-1];
                    ri+=s[r];
                    l++;
                    r-=2;
                }
                else if(s[l]==s[r+1]){
                    le+=s[l];
                    ri+=s[r+1];
                    l+=2;
                    r--;
                }
                else if(s[l]==s[r]){
                    le+=s[l];
                    ri+=s[r];
                    l+=2;
                    r-=2;
                }

                else if(s[l-1]==s[r-1]){
                    le+=s[l-1];
                    ri+=s[r-1];
                    l++;
                    r-=3;
                }

                else if(s[l+1]==s[r+1]){
                    le+=s[l+1];
                    ri+=s[r+1];
                    l+=3;
                    r--;
                }

                else if(s[l]==s[r-1]){
                    le+=s[l];
                    ri+=s[r-1];
                    l+=2;
                    r-=3;
                }

                else if(s[l+1]==s[r]){
                    le+=s[l];
                    ri+=s[r];
                    l+=3;
                    r-=2;
                }
                else if(s[l+1]==s[r-1]){
                    le+=s[l];
                    ri+=s[r-1];
                    l+=3;
                    r-=3;
                }
            }
        }
    }
    cout<<le;
    ///cout<<s[s.length()/2-1];
    int lttt=ri.size();
    for(int i=lttt-1;i>=0;i--){
        cout<<ri[i];
    }
    return 0;
}
