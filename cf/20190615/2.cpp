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

int n;
string a,b;

void work()
{
    if(b.length()<a.length()){
        cout<<"NO"<<endl;
        return;
    }
    else if(b.length()==a.length()){
        if(b==a)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else{
        map<char,int> ma,mb;
        for(int k=0;k<a.length();++k)
            ma[a[k]]++;
        for(int k=0;k<b.length();++k)
            mb[b[k]]++;
        for(char k='a';k<='z';++k){
            if(mb[k]<ma[k]||(mb[k]!=0&&ma[k]==0)){
                cout<<"NO"<<endl;
                return;
            }
        }
        long long i=0,j=0;
        char last = b[0];
        int flag = 1;
        while(i!=a.length()&&j!=b.length()){
            if(a[i] == b[j]){
                i++;
                j++;
                continue;
                last = b[j];
            }else{
                if(i == 0 && j == 0){
                    flag = 0;
                    break;
                }else{
                    if(b[j] == last){
                        b.erase(j,1);
                        continue;
                    }else{
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if(flag == 0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--){
        cin>>a;
        cin>>b;
        work();
    }
    return 0;
}
