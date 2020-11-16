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
#define pb(a) push_back(a)
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
using namespace std;
const int maxn=300000;
typedef long long ll;

int main()
{
    int n;
    int a[105];
    cin>>n;
    fo(i,0,n)
        cin>>a[i];
    fo(i,0,n-1)
    {
        if((a[i]==3&&a[i+1]==2)||(a[i]==2&&a[i+1]==3))
        {
            cout<<"Infinite";
            return 0;
        }
    }
    int ans=0;
    fo(i,0,n-1)
    {
        if(a[i]==1&&a[i+1]==2)
            ans+=3;
        if(a[i]==2&&a[i+1]==1)
            ans+=3;
        if(a[i]==1&&a[i+1]==3)
            ans+=4;
        if(a[i]==3&&a[i+1]==1){
            if(a[i+2]==2)
                ans+=3;
            else
                ans+=4;
        }
    }
    cout<<"Finite"<<endl;
    cout<<ans;
    return 0;
}
