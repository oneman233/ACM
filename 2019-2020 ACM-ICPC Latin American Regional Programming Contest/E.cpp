#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[200005];
int n,l1,l2;
int pre[200005];

int main()
{
	scanf("%s",s);
	scanf("%d",&n);
	l1=strlen(s);
	for(int i=0;i<n-1;++i) s[i+l1]=s[i];
	l2=l1+n-1;
	int flg=-0x3f3f3f3f;
	for(int i=0;i<l2;++i)
	{
		if(s[i]=='E') flg=i;
		pre[i]=flg;
	}
	ll ans=0;
	for(int i=0;i<l2;++i)
	{
		int len=i-pre[i]+1;
		if(len>n) continue;
		if(i>=l1) ans+=min(l1-i+n-1,pre[i]-i+n);
		else ans+=min(pre[i]+1,n-len+1);
	}
	printf("%lld",ans);
	return 0;
}
/*
EEEEE
4
*/
