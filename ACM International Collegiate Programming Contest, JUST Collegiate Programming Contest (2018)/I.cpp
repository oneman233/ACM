#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,d;
double area;

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&d);
		area=(double)d*d/2;
		printf("%lf\n",area);
	}
	return 0;
}
