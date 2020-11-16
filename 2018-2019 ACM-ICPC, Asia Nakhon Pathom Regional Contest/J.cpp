#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int l,r,fuck;
const long double g=1e-15;
const long double f=1e10;
const long double f2=1e5;
const long double _13=1.0/3.0;
const long double _23=2.0/3.0;
long double sum,a,b,ta,tb;

void gao2()
{
	fuck=0;sum=0;
	for(int i=l;i<=r;i++)
		sum+=pow(i+g,1.0/3.0)-pow((long double)i,1.0/3.0);
	while(sum>=10) sum/=10,fuck--;
	while(sum<1) sum*=10,fuck++;
	printf("%.5LfE-%03d\n",sum,fuck);
}

inline long double cal(int x)
{
	a=x+g,b=x;
	return (long double)1.0/(pow(a,_23)+pow(b,_23)+pow(a,_13)*pow(b,_13));
}

void gao()
{
	fuck=15;
	sum=0;
	for(int i=l;i<=r;i++)
	{
		b=i;
		tb=pow(b,_13);
		sum+=(long double)1.0/(tb*tb*3);
	}
	//for(int i=l;i<=r;i++)
	//sum+=cal(i);//*(r-l+1)/2;
	//sum=(cal(l)+cal(r))*(r-l+1)/2;
	while(sum>=10&&sum!=0) sum/=10,fuck--;
	while(sum<1&&sum!=0) sum*=10,fuck++;
	printf("%.5LfE-%03d\n",sum,fuck);
}

int main()
{
	//freopen("j.in","r",stdin);
	//freopen("j.out","w",stdout);
	while(~scanf("%d%d",&l,&r)&&l&&r) gao();//,gao2();
	return 0;
}

