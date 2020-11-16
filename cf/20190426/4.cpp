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

using namespace std;
long long n,a[200010],b[200010]={};
int main()
{

	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int tol=0,l=0,r=n-1;
	string x,ll="L",rr="R";
	while(a[l]>b[tol]||a[r]>b[tol]&&l!=r)
	{
		if(a[l]==a[r])
		{
			int k=0;
			while(a[l+k]<a[l+k+1]&&(l+k)<r)
				k++;
			int o=0;
			while(a[r-o]<a[r-o-1]&&(r-o)>l)
				o++;
			if(o>k)
			{
				tol+=o;
				for(int i=0;i<=o;i++)
					x+=rr;
			}
			else
			{
				tol+=k;
				for(int i=0;i<=k;i++)
					x+=ll;
			}
			tol++;
			break;
		}
		if(a[l]<a[r]&&a[l]>b[tol])
		{
			b[tol+1]=a[l];
			l++;
			tol++;
			x+=ll;
		}
		else if(a[r]>b[tol])
		{
			b[tol+1]=a[r];
			r--;
			tol++;
			x+=rr;
		}
		else if(a[l]>b[tol])
		{
			b[tol+1]=a[l];
			l++;
			tol++;
			x+=ll;
		}
	}
	cout<<tol<<endl;
	cout<<x;
}
