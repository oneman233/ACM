#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[33];
ll n,x,y;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='1')
		{
			x+=(1LL<<(n-i));
		}
		else if(s[i]=='2')
		{
			y+=(1LL<<(n-i));
		}
		else if(s[i]=='3')
		{
			x+=(1LL<<(n-i));
			y+=(1LL<<(n-i));
		}
	printf("%lld %lld %lld",n,x,y);
	return 0;
}
