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

ll n,x,y,ans=0;
string a;

int main()
{
	cin>>n>>x>>y;
	cin>>a;
	rre(i,n-1,0)
	{
		if(n-i-1<y)
		{
			if(a[i]!='0')
			ans++;
		}
		else if(n-i-1==y)
		{
			if(a[i]!='1')
			ans++;
		}
		else if(n-i-1<x)
		{
			if(a[i]!='0')
			ans++;
		}
		else
            break;
	}
	cout<<ans;
	return 0;
}
