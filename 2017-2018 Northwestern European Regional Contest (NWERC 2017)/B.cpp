#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	if(n==1||n==2||n==3) puts("1");
	else printf("%d",n-2);
	return 0;
}
