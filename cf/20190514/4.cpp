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

int t,n;
ll a[305];

int main()
{
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        map<ll,int> m;
        sci(n);
        fo(i,0,n){
            scl(a[i]);
            m[a[i]]++;
        }
        sort(a,a+n);
        if(n==1&&a[0]==1){
            cout<<-1<<endl;
            continue;
        }
        if(m[1]!=0){
            cout<<-1<<endl;
            continue;
        }
        ll ans;
        bool can=true;
        if(n&1){
            ans=a[n/2]*a[n/2];
            ///cout<<ans<<endl;
            can=true;
            for(int i=0;i<n/2;++i){
                if(ans/a[i]!=a[n-i-1]){
                    can=false;
                    break;
                }
            }
        }
        else{
            ans=a[0]*a[n-1];
            ///cout<<ans<<endl;
            can=true;
            for(int i=0;i<n/2;++i){
                if(ans/a[i]!=a[n-i-1]){
                    can=false;
                    break;
                }
            }
        }
        for(ll i=2;i*i<=ans;++i){
            if(ans%i==0&&(m[i]==0||m[ans/i]==0)){
                can=false;
                break;
            }
        }
        for(auto it=m.begin();it!=m.end();++it){
            if(it->second!=0&&ans%it->first!=0){
                can=false;
                break;
            }
        }
        if(can)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
