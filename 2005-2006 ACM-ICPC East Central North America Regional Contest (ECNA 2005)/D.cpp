#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int mp[1005][1005];
int mvi[8]={0,0,1,1,1,-1,-1,-1};
int mvj[8]={1,-1,0,1,-1,0,1,-1};

bool ok(int i,int j)
{
	if(i<1||i>n||j<1||j>m||mp[i][j]>0) return 0;
	return 1;
}

void gao1(int i,int j)
{
	for(int k=0;k<8;++k)
	{
		int di=i+mvi[k];
		int dj=j+mvj[k];
		while(ok(di,dj))
		{
			mp[di][dj]=-1;
			di+=mvi[k];
			dj+=mvj[k];
		}
	}
}

void gao2(int i,int j)
{
	if(ok(i+1,j+2)) mp[i+1][j+2]=-1;
	if(ok(i+1,j-2)) mp[i+1][j-2]=-1;
	if(ok(i-1,j+2)) mp[i-1][j+2]=-1;
	if(ok(i-1,j-2)) mp[i-1][j-2]=-1;
	if(ok(i+2,j+1)) mp[i+2][j+1]=-1;
	if(ok(i+2,j-1)) mp[i+2][j-1]=-1;
	if(ok(i-2,j-1)) mp[i-2][j-1]=-1;
	if(ok(i-2,j+1)) mp[i-2][j+1]=-1;
}

int Case=1;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0) break;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				mp[i][j]=0;
		for(int i=1,k;i<=3;++i)
		{
			scanf("%d",&k);
			for(int j=1,r,c;j<=k;++j)
			{
				scanf("%d%d",&r,&c);
				mp[r][c]=i;
			}
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				if(mp[i][j]==1) gao1(i,j);
				else if(mp[i][j]==2) gao2(i,j);
			}
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(mp[i][j]==0) ++ans;
//		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cout<<mp[i][j]<<" \n"[j==m];
		printf("Board %d has %d safe squares.\n",Case,ans);
		Case++;
	}
	return 0;
}
/*
4 4
2 1 4 2 4
1 1 2
1 2 3
*/
