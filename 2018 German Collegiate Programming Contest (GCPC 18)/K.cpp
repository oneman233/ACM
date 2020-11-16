#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[66],t,g;
bitset<1005>h[66];
double ans=-1;
int main()
{
	h[0][0]=1;
	scanf("%d%d",&n,&g);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);t-=10;
		for(int j=i;j>=1;j--)
			h[j]|=h[j-1]<<t;
	}
	for(int i=1;i<=n;i++)
		for(int j=max(0,g-10*(i+1));j<=g-5*(i+1);j++)
			if(h[i][j])
				ans=max(ans,10-(g-j)*1.0/(i+1));//,printf("%d %d\n",i,j);
	if(ans!=-1)printf("%.12f",ans);else puts("impossible");
	return 0;
}
