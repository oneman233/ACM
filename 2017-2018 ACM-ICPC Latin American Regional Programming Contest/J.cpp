#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,ans=0;
string s;
int nx(int i,int k){return (i+k)%n;}

bool dfs(int now,int k)
{
	if()
}

int main()
{
	cin>>s;
	n=s.length();
	for(int i=1;i<=n-1;++i) if(dfs(0,i)) ans++;
	printf("%d",ans);
	return 0;
}
