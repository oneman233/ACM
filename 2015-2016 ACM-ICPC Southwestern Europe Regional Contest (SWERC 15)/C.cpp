#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;

#if 0
int t,n,a[N];
ll ans=0,s[N];

void gao(int l,int r)
{
	if(l==r) return;
	int m=(l+r)/2;
	gao(l,m);
	gao(m+1,r);
	ans+=s[r]-s[l-1];
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
		ans=0;
		gao(1,n);
		printf("%lld\n",ans);
	}
	return 0;
}
//#endif 

int _t,n;
int arr[100005]={0};
ll sumof[100005]={0};
int valtoindex[100005]={0};
ll ans=0;


int main()
{
	scanf("%d",&_t);
	while(_t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",arr+i);
		}
		sumof[1]=arr[1];
		for(int i=2;i<=n;i++)
		{
			
		}
	}
		
}
#endif


