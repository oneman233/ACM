#include <bits/stdc++.h>
using namespace std;

bool isp(int x)
{
	if(x==1) return false;
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	if(n%2==0||!isp(n-2)) return printf("-1"),0;
	printf("%d %d",2,n-2); 
	return 0;
}
