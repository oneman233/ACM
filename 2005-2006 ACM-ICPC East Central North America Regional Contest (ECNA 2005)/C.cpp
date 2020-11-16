#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,Case=1;
int mp[20][20];

int main()
{
	while(scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0) break;
		int k;
		scanf("%d",&k);
		memset(mp,0,sizeof(mp));
		for(int i=1,x,y;i<=k;++i)
		{
			scanf("%d%d",&x,&y);
			mp[x][y]=1;
		}
		
		Case++;
	}
	return 0;
}
