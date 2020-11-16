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

int t,n,x,y,dx,dy,tx,ty;
unordered_set<int> s;

int main()
{
    cin>>t>>n>>x>>y>>dx>>dy;
    fo(i,0,n)
    {
        fo(j,0,n)
        {
            tx=x-i*dx;
            ty=y-j*dy;
            ///cout<<tx<<" "<<ty<<endl;
            s.insert(tx);
            s.insert(ty);
            s.insert(tx+ty);
        }
    }
    /*
    for(auto it:s){
        cout<<it<<endl;
    }
    */
    if(s.count(t)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
