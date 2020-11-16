#include <bits/stdc++.h>
using namespace std;

double r,ans,v,s;

int main()
{
	scanf("%lf%lf",&v,&s);
	r=s/2.0/sin(acos(-1)/v);
	ans=r*r*acos(-1);
	printf("%.10f",ans);
	return 0;
}
