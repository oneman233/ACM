#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c,d,k,g;
vector<int> ans;

void debug()
{
	char s[100];
	scanf("%s",s);
	int n=strlen(s),a=0,b=0,c=0,d=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(s[i]=='1'&&s[j]=='1') d++;
			else if(s[i]=='1'&&s[j]=='0') c++;
			else if(s[i]=='0'&&s[j]=='1') b++;
			else a++;
		}
	printf("%d %d %d %d\n",a,b,c,d);
}

int main()
{
	//debug();
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	k=(1+sqrt((double)1+8*a))/2;
	g=(1+sqrt((double)1+8*d))/2; 
	if(k*(k-1)/2!=a||g*(g-1)/2!=d)
	{
		printf("impossible");
		return 0;
	}
	if(b==0&&c==0&&d==0)
	{
		for(int i=0;i<k;i++) printf("0");
		return 0;
	}
	if(a==0&&b==0&&c==0)
	{
		for(int i=0;i<g;i++) printf("1");
		return 0;
	} 
	if(b+c!=k*g)
	{
		printf("impossible");
		return 0;
	}
	while(k||g)
		if(g&&c>=k) c-=k,ans.push_back(1),g--;
		else ans.push_back(0),k--;
	for(auto p:ans) printf("%d",p);
	return 0;
}
