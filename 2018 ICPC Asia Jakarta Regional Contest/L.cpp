#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;
char s[100];

bool check()
{
	int n=strlen(s);
	ll chk=0;
	for(int i=0;i<n;i++)
		chk*=2,chk+=s[i]-'0';
	return chk<=k;
}

int main()
{
	scanf("%lld%s",&k,s);
	int cnt=0;
	do
	{
		if(check()) 
		{
			printf("%d",cnt);
			return 0;
		}
		int n=strlen(s),flag=0;
		for(int j=1;j<n;j++)
		{
			if(s[j]=='1')
			{
				for(int k=j;k<n;k++) s[k]=s[k+1];
				flag=1;
				break;
			}
		}
		if(!flag) s[n-1]=0;
		cnt++;
	}while(strlen(s)>=1);
	return 0;
}
