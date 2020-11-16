#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-5;

int t;
double a,b;
bool isp(int x)
{
	if(x==1) return 0;
	for(int i=2;i*i<=x;++i)
		if(x%i==0) return 0;
	return 1;
}

void gao()
{
	a*=1e5,b*=1e5;
	a+=eps,b+=eps;
	int aa=(int)a,bb=(int)b;
	if(aa==bb)
	{
		puts("2 2");
		return;
	}
	int g=__gcd(aa,bb);
	aa/=g,bb/=g;
	if(isp(aa)&&isp(bb))
	{
		printf("%d %d\n",aa,bb);
	}
	else
	{
		puts("impossible");
	}
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf",&a,&b);
		gao();
	}
	return 0;
}
/*
3
4.5 6
7.14 11.22
0.00002 0.00007
*/
