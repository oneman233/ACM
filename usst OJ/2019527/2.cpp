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

/*
这不bzoj原题吗.jpg
*/

int main()
{
    int n,renhaoyun;
    cin>>n;
    fo(i,0,n)
        cin>>renhaoyun;
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n==3){
        cout<<6;
        return 0;
    }
    if(n%2==0){
        if(n%4==0){
            cout<<4;
        }
        else if(n%4==2){
            cout<<n;
        }
    }
    else if(n%2==1){
        if(n%4==1){
            cout<<2*n;
        }
        else if(n%4==3){
            cout<<12;
        }
    }
    return 0;
}
