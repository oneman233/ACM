#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int l,r,fuck;
const long double g=1e-15;
const long double f=1e10;
const long double f2=1e5;
const long double _13=1.0/3.0;
const long double _23=2.0/3.0;
long double sum;

void gao2()
{
	fuck=0;sum=0;
	for(int i=l;i<=r;i++)
		sum+=pow(i+g,1.0/3.0)-pow((long double)i,1.0/3.0);
	while(sum>=10) sum/=10,fuck--;
	while(sum<1) sum*=10,fuck++;
	printf("%.5LfE-%03d\n",sum,fuck);
}

void gao()
{
	fuck=5;
	sum=0;
	for(int i=l;i<=r;i++)
	{
		long double a=i+g;
		long double b=i;
		sum+=(long double)1.0/(pow(a,_23)+pow(b,_23)+pow(a,_13)*pow(b,_13));
	}
	while(sum>=10) sum/=10,fuck--;
	while(sum<1) sum*=10,fuck++;
	printf("%.5LfE-%03d\n",sum,fuck);
}

int main()
{
	while(~scanf("%d%d",&l,&r)&&l&&r) gao();//,gao2();
	return 0;
}
