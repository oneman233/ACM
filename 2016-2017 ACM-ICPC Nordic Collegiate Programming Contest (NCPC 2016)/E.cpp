#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tbl[]={0,1,2,9,1<<18};

int qpow(ll a,int b,int p)
{
	ll rt=1;
	for(;b;b>>=1)
	{
		if(b&1) rt=rt*a%p;
		a=a*a%p;
	}
	return rt;
}

map<int,int>eu;
int euler(int n)
{
	if(eu[n]) return eu[n];
	int ans=n, ed=sqrt(n)+1;
	for(int i=2; i<=ed; ++i)
	{
		if(n%i==0)
		{
			ans-=ans/i;
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans-=ans/n;
	return eu[n]=ans;
}

int solve(int n,int p)	//return exponial(n)%m
{
	if(p==1) return 0;
	if(n<5) return tbl[n]%p;
	int phip=euler(p);
	int ans=solve(n-1,phip);
	return qpow(n,ans+phip,p);
}

int main()
{
	int n,m; scanf("%d%d",&n,&m);
	if(m==1) return puts("0"),0;
	printf("%d",solve(n,m));
	return 0;
}
