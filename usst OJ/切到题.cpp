#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

double big(double a,double b)
{
	if(a>b)
		return a;
	else
		return b;
}
double small(double a,double b)
{
	if(a>b)
		return b;
	else
		return a;
}

int main()
{
	double h,w;
	scanf("%lf %lf",&h,&w);
	if(h==w)
	{
		printf("%.10lf",h/2.0);
		return 0;
	}
	if(big(h,w)/3.0<small(h,w))
		printf("%.10lf",big(big(h,w)/3.0,small(h,w)/2));
	else
		printf("%.10lf",small(h,w));
	return 0;
}
