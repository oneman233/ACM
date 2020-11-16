#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;

int main()
{
	scanf("%lld%lld",&a,&b);
	int cnt=0;
	while(a)
	{
		cnt++;
		a/=b;
	}
	printf("%d",cnt);
	return 0;
}
