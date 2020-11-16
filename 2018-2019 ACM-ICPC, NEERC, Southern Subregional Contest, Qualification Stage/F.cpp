#include <bits/stdc++.h>
using namespace std;

int ans[1000005];
char s[10];

int gao3(int x)
{
	int s1=0,s2=0;
	int cnt=3;
	while(cnt--)
	{
		s2+=x%10;
		x/=10;
	}
	cnt=3;
	while(cnt--)
	{
		s1+=x%10;
		x/=10;
	}
	return abs(s1-s2);
}

void gao()
{
	int cnt[100];
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<=1e6;++i)
	{
		int tmp=gao3(i);
		for(int j=0;j<tmp;++j)
			ans[i]+=cnt[j];
		cnt[tmp]++;
	}
}

int gao2()
{
	int base=1,ret=0;
	for(int i=5;i>=0;--i)
	{
		ret+=base*(s[i]-'0');
		base*=10;
	}
	return ret;
}

int t,n;

int main()
{
	gao();
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%s",s);
		printf("%d\n",ans[gao2()]);
	}
	return 0;
}
/*
5
001000
000000
999000
453234
654331
*/
