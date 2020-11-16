#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int f[1005];
char ans[1005];
int w1[1005][1005],w2[1005][1005];

int _find(int x)
{
	if(f[x]!=x) f[x]=_find(f[x]);
	return f[x];
}

void _merge(int x,int y)
{
	x=_find(x),y=_find(y);
	if(x!=y) f[x]=y;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) f[i]=i,ans[i]='?';
	for(int i=1;i<=m;++i)
	{
		int a,b;
		char c;
		scanf("%d%c%d",&a,&c,&b);
		if(c=='>')
		{
			w1[a][b]=2;
			w1[b][a]=1;
		}
		else if(c=='<')
		{
			w1[a][b]=1;
			w1[b][a]=2;
		}
		else if(c=='=')
		{
			_merge(a,b);
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(w1[i][j]) w2[_find(i)][_find(j)]=w1[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		bool one=0,two=0;
		for(int j=1;j<=n;++j)
		{
			if(w2[i][j]==2) two=1;
			if(w2[i][j]==1) one=1;
		}
		if(one&&two)
		{
			ans[i]='R';
			for(int j=1;j<=n;++j)
			{
				if(w2[i][j]==2) ans[j]='B';
				if(w2[i][j]==1) ans[j]='W';
			}
		}
	}
	for(int i=1;i<=n;++i) printf("%c",ans[_find(i)]);
	return 0;
}
/*
3
2
1<3
1>2
*/
