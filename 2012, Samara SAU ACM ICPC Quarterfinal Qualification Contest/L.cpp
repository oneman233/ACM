#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll now,last,n; 

int main()
{
	scanf("%lld",&n);
	scanf("%lld",&now);
	last=now;
	printf("%lld ",last);
	for(int i=1;i<n;i++)
	{
		scanf("%lld",&now);
		printf("%lld ",now-last);
		last=now;
	}
	return 0;
}
