#include <bits/stdc++.h>
using namespace std;
inline int read(){char ch=getchar();int s=0,w=1;while(ch<48||ch>57){if(ch=='-')w=-1;ch=getchar();}while(ch>=48&&ch<=57){s=(s<<1)+(s<<3)+ch-48;ch=getchar();}return s*w;}
inline void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+48);}
int a[1005][1005],p[1005][1005],n,m;
inline bool ok(int i,int j,int x)
{
	if(i+x-1>n||j+x-1>m)return false;
	//printf("%d %d %d %d\n",i,j,x,p[i+x-1][j+x-1]-p[i][j-1]-p[i-1][j]+p[i-1][j-1]);
	return p[i+x-1][j+x-1]-p[i+x-1][j-1]-p[i-1][j+x-1]+p[i-1][j-1]<=1;
}
int main()
{
	int _;scanf("%d",&_);
	while(_--)
	{
		int ans=1;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
		//for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)printf("%d%c",p[i][j]," \n"[j==m]);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		{
			if(!ok(i,j,ans))continue;
			while(ok(i,j,ans))++ans;
			--ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
