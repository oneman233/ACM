#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("e.in","w",stdout);
	printf("100\n");
	for(int i=0;i<100;i++)
	{
		printf("16\n");
		for(int j=0;j<16;j++)
			for(int k=0;k<16;k++)
				printf("1%c"," \n"[k==15]);
	}
	return 0;	
}
