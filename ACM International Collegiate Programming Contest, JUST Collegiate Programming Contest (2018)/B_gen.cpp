#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("b.in","w",stdout);
	printf("30\n");
	for(int T=0;T<30;T++)
	{
		printf("10000\n");
		for(int i=0;i<10000;i++)
			printf("%d ",rand()%1000000);
		printf("\n");
		for(int i=0;i<10000;i++)
			printf("%c ","MF"[rand()&1]);
		printf("\n");
	}
	return 0;
}
