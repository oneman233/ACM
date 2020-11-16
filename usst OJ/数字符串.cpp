#include <bits/stdc++.h>
using namespace std;

int n;
long long ans=0;

void dfs(int num,int geshu,int sum)
{
	if(sum==n&&geshu!=3)
	{
		ans++;
		return;
	}
	if(sum==n)
		return;
	if(geshu>=3)
		return;
	if(num==1)
	{
		dfs(1,geshu+1,sum+1);
		dfs(0,1,sum+1);
	}
	else
	{
		dfs(0,geshu+1,sum+1);
		dfs(1,1,sum+1);
	}
}
int main()
{
	cin>>n;
	dfs(1,1,1);
	dfs(0,1,1);
	cout<<ans;
	return 0;
}
