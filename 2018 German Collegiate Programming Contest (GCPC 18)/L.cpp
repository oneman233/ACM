#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[111][111],h[111][111],b[111][111];
int dx[]={-1,-1,-1,0,0,0,1,1,1};
int dy[]={-1,0,1,-1,0,1,-1,0,1};
int main()
{
	scanf("%d%d",&n,&m);++n;++n;++m;++m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",a[i]+j);
	for(int i=1;i<n;i++)
	{
		//h[i+1][2]=a[i][1]?1:-1;
//		h[i+1][m-1]=a[i][m]?1:-1;
		for(int j=1;j<m;j++)
		{
			int c=0;
			for(int k=0;k<8;k++)c+=h[i+dx[k]][j+dy[k]]==1;
			//if(c>a[i][j]||c<a[i][j]-1)return !printf("impossible");
			h[i+1][j+1]=c!=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)h[i][1]=h[i][m]=h[i][0]=h[i][m+1]=0;
	for(int i=1;i<=m;i++)h[1][i]=h[n][i]=h[0][i]=h[n+1][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int c=0;
			for(int k=0;k<9;k++)c+=h[i+dx[k]][j+dy[k]];
			//printf("%d%c",c," \n"[j==m]);
			if(c!=a[i][j])return !printf("impossible");
		}
	for(int i=2;i<n;i++,puts(""))for(int j=2;j<m;j++)printf("%c",h[i][j]==1?'X':'.');
	
	return 0;
}
