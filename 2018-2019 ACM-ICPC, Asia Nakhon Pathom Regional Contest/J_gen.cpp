#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(0));
	freopen("j.in","w",stdout);
	for(int T=0;T<2000;T++)
	{
		int k=rand();
		printf("%d %d\n",k,k+10000);
	}
	printf("0 0\n");
	return 0;	
}

