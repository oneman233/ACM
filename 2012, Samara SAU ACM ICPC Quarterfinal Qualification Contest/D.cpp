#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,dp[1000005];
vector<int> v;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(n%i==0) v.push_back(i);
	dp[0]=1;
	for(int i=1;i<v.size();i++)
		for(int j=0;j<i;j++) if(v[i]%v[j]==0) dp[i]+=dp[j];
	printf("%d",dp[v.size()-1]);	
	return 0;
}
