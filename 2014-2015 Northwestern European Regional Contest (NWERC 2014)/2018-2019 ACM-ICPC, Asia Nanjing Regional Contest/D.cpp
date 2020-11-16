#include <bits/stdc++.h>
using namespace std;

int n;
double xx[105],yy[105],zz[105];

double cal(double x,double y,double z)
{
	double ret=0;
	for(int i=0;i<n;i++)
		ret=max(ret,(xx[i]-x)*(xx[i]-x)+(yy[i]-y)*(yy[i]-y)+(zz[i]-z)*(zz[i]-z));
	return sqrt(ret);
}

double check2(double x,double y)
{
	double l=-2e5,r=2e5;
	for(int i=0;i<50;i++)
	{
		double lm=(l+r)/2,rm=(lm+r)/2;
	    if(cal(x,y,lm)>cal(x,y,rm)) l=lm;
	    else r=rm;
	}
	return cal(x,y,(l+r)/2);
}

double check1(double x)
{
	double l=-2e5,r=2e5;
	for(int i=0;i<50;i++)
	{
		double lm=(l+r)/2,rm=(lm+r)/2;
	    if(check2(x,lm)>check2(x,rm)) l=lm;
	    else r=rm;
	}
	return check2(x,(l+r)/2);
}

int main()
{
	//n=100;
	//for(int i=0;i<n;i++)
	//	xx[i]=i+3,yy[i]=i*i*i-7,zz[i]=123+i*i;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf%lf%lf",xx+i,yy+i,zz+i);
	double l=-2e5,r=2e5;
	for(int i=0;i<50;i++)
	{
	    double lm=(l+r)/2,rm=(lm+r)/2;
	    if(check1(lm)>check1(rm)) l=lm;
	    else r=rm;
	} 
	printf("%.10f",check1((l+r)/2)); 
	return 0;
}
