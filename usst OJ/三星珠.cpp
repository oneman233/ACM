#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int maxn=10000;

int n,m;
double a[maxn+5];
double l,r;

int main()
{
	scanf("%d%d",&n,&m);
	for_(i,0,n){
		scanf("%lf",a+i);
	}
	l=0.0, r=10000.0;
	double mid;
	while((r-l)/2.0 >= 0.00000001){
		mid=(l+r)/2.0;
		int t=0;
		for_(i,0,n)
			t += a[i]/mid;
		if(t<m)
			r=mid;
		else
			l=mid;
	}

	printf("%.1lf",((int)(mid*10))/10.0);
	return 0;
}
