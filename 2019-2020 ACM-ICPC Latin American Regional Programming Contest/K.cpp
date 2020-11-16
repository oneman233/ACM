#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[10005];
ll a[100],l;
vector<int> v;

void gao()
{
	//for(auto i:v) cout<<i<<' ';
	int n=v.size();
	printf("%d\n",n);
	for(int i=0;i<(1<<n);i++)
	{
		ll mul=1,cnt=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j)) mul*=-v[j],cnt++;
		a[cnt]+=mul; 
		//printf("! %lld %lld\n",cnt,mul);
	}
	ll k=1;
	if(s[l]=='A') k=-1;
	for(int i=0;i<=n;i++) printf("%lld ",k*a[i]);
}

int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);
	for(int i=1;i<l;++i)
		if((s[i]=='A'&&s[i+1]=='H')||(s[i]=='H'&&s[i+1]=='A'))
			v.push_back(i+i+1);
	gao();
	return 0;
}
