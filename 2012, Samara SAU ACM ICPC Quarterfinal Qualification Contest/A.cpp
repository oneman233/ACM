#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,m;
char c[2505][2005];
char s[2505];
int col[2505][2505],row[2505][2505];
int mp[2505][2505];

int sumr(int r,int x,int y)
{
	if(x>=y) swap(x,y);
	return row[r][y]-row[r][x-1];
}

int sumc(int c,int x,int y)
{
	if(x>=y) swap(x,y);
	return col[y][c]-col[x-1][c];
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
		{
			c[i][j]=s[j];
			if(c[i][j]=='#') mp[i][j]=1;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			row[i][j]=row[i][j-1]+mp[i][j];
	for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i)
			col[i][j]=col[i-1][j]+mp[i][j];
	int q,x1,y1,x2,y2;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int a=sumr(x1,y1,y2)+sumc(y2,x1,x2);
		int b=sumr(x2,y1,y2)+sumc(y1,x1,x2);
		if(a==0||b==0) puts("YES");
		else puts("NO");
	}
	return 0;
}
