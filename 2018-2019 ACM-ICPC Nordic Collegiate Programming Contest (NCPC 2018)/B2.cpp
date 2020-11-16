#include <bits/stdc++.h>
using namespace std;
 
char s[1000];
int n,v[1005],flag=1;
 
int main()
{
	scanf("%d",&n);
	for(int i=0,x;i<n;i++)
	{
		scanf("%s",s);
		if(s[0]=='m') continue;
		else 
		{
			sscanf(s,"%d",&x);
			if(x!=i+1) flag=0;
		}
	}
	if(flag) printf("makes sense\n"); else printf("something is fishy\n");
	return 0;	
}

