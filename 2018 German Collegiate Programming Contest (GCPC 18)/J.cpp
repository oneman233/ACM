#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300005][4];
vector<pair<int,int>>v[600005];
vector<int>ans[300005];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;i++)for(int j=0;j<4;j++)scanf("%d",a[i]+j),v[a[i][j]].emplace_back(j,i);
	int f;
	for(int i=1;i<=n;i++)
	{
		int z=0;
		for(int j=0;j<4;j++){z+=!a[i][j];if(a[i][j])f=a[i][j];}
		if(z==2)break;
	}
	
	return 0;
}
