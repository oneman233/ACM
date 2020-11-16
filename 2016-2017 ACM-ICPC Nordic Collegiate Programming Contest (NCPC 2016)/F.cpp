#include <bits/stdc++.h>
using namespace std;
#define double long double
int n,p;

double cal(int k)
{
   	double ret=(double)k*p;
   	int i,j;
   	i=j=n-p+1;j++;
   	while(i<=n||j<=n)
   	{
   		while(j<=n&&(i>n||ret<=1)) ret*=j,j++;
   		while(i<=n&&(j>n||ret>1)) ret/=(i+k),i++;
   	}
    return ret;
}

int main()
{
	scanf("%d%d",&n,&p);
	int l=1,r=n,m1,m2;
	while(l<r)
	{
        m1=(2*l+r)/3,m2=(2*r+l+2)/3;
        if(cal(m1)>cal(m2)-1e-8) r=m2-1; else l=m1+1;
	}
	
	double ans=cal(l);
    printf("%.10Lf",ans);
	return 0;
}
