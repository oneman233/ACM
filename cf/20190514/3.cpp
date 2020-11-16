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

map<int,int> m;
int a[maxn+5];

int main(){
    int n;
    cin>>n;
    fo(i,0,n){
        cin>>a[i];
        m[a[i]]++;
    }
    int idx=1;
    ll cnt=0;
    for(auto it=m.begin();it!=m.end();++it){
        while(it->second>0&&it->first>=idx){
            cnt++;
            it->second--;
            idx++;
        }
    }
    cout<<cnt;
    return 0;
}
