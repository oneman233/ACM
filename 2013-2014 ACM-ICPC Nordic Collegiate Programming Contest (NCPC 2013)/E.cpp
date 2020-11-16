#include <bits/stdc++.h>
using namespace std;

char a[100005],b[100005];

int main()
{
	scanf("%s%s",a,b);
	int l1=strlen(a),l2=strlen(b),f1=0,f2=0;
	for(int i=0;i<min(l1,l2);i++)
		if(a[i]==b[i]) f1++;
		else break;
	for(int i=0;i<min(l1,l2);i++)
		if(l1-i-1>=f1&&l2-i-1>=f1)
		{
			if(a[l1-i-1]==b[l2-i-1]) f2++;
			else break;
		}
		else break;
		
	printf("%d",max(0,l2-f1-f2));
	return 0;
}
