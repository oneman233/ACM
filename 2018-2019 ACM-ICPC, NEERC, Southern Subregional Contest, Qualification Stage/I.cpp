#include <bits/stdc++.h>
using namespace std;
int n,a[1002];
int main()
{
	scanf("%d",&n);for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	printf("%d\n",a[n-1]-a[0]-n+1);
	return 0;
}
