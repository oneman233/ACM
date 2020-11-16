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
const int MAX=1000;
const int inf=0x3f3f3f3f;
const double pi=3.1415926535;
const int mod=10007;
typedef long long ll;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int x,ans=1000000;
        cin>>x;
        for(int i=0;i<=6;++i){
            for(int j=0;j<=10;++j){
                for(int k=0;k<=3;k++){
                    for(int a=0;a<=1;++a){
                        for(int b=0;b<=1;++b){
                            if(150-4*i-5*j-14*k-16*a-18*b==x){
                                ans=min(ans,i+j+k+a+b);
                            }
                        }
                    }
                }
            }
        }
        if(ans==1000000)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
