#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n;
ll a[305][305];
ll d[305][305];

ll inf=0x3f3f3f3f3f3f3f3f;

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) scanf("%lld",&d[i][j]),a[i][j]=d[i][j];
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(a[i][j]==0) a[i][j]=d[i][j]=inf;
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cout<<a[i][j]<<" \n"[j==n];
//	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cout<<d[i][j]<<" \n"[j==n];
	bool can=1;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(d[i][j]!=a[i][j]&&a[i][j]!=inf){can=0;break;}
	if(can)
	{
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) printf("%lld%c",(a[i][j]==inf?0:a[i][j])," \n"[j==n]);
	}
	else printf("-1");
	return 0;
}
