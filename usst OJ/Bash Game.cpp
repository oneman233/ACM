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
const int mod=99999;
typedef long long ll;

int t,p,m;

int main()
{
    while(scii(p,m)){
        if(p==0&&m==0)
            break;
        if(p==1){
            cout<<"king"<<endl;
            continue;
        }
        if(m>=p){
            cout<<"sorahjy"<<endl;
            continue;
        }
        ///cout<<"king"<<endl;
        ///cout<<"sorahjy"<<endl;
        if((p-1)%(m+1)==0){
            cout<<"king"<<endl;
        }
        else{
            cout<<"sorahjy"<<endl;
        }
    }
    return 0;
}