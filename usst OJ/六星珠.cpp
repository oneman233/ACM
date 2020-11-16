#include <bits/stdc++.h>
using namespace std;
const int maxn=300000;

int n,m,t;
int h[maxn+5],l[maxn+5],cnth[maxn+5],cntl[maxn+5];
int x,y,c;

int main()
{
	cin>>n>>m;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>x>>y>>c;
		if(x==1)
		{
			h[y]=c;
			cnth[y]=i;
		}
		else if(x==2)
		{
			l[y]=c;
			cntl[y]=i;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(cntl[j]>cnth[i])
				printf("%d",l[j]);
			else
				printf("%d",h[i]);
			if(j!=m)
				printf(" ");
		}
		if(i!=n)
			printf("\n");
	}
	return 0;
}
