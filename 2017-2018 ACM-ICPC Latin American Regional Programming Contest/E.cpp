#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int d,n,dp[1005][1005];
char s[1005],t[1005];

void dfs(int now,int low,ll sum)
{
	dp[now][sum]=1;
	if(now==n)
	{
		if(sum==0) 
		{
			printf("%s",s);
			exit(0);
		}
		return;
	}
	if(t[now]!='?') 
		dfs(now+1,0,(sum*10+s[now]-'0')%d);
	else 
	{
		for(int i=low;i<=9;i++)
		{
			s[now]=i+'0';
			if(!dp[now+1][(sum*10+i)%d]) dfs(now+1,0,(sum*10+i)%d);
		}
	}
}

int main()
{
	scanf("%s%d",s,&d);
	n=strlen(s);
	for(int i=0;i<n;i++) t[i]=s[i];
	dfs(0,1,0);
	printf("*");
	return 0;
}
/*
????????77081 999
*/
