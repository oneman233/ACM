#include <bits/stdc++.h>
using namespace std;

char a[1000005];


int main()
{
	
	int bias=-'a'+'A';
	scanf("%s",a);
	int len = strlen(a);
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='w'||a[i]=='y')
		{
			cnt=0;
		}
		if(cnt%2==0)
		{
			printf("%c",a[i]+bias);
		}
		else
		{
			printf("%c",a[i]);
		}
		cnt++;
	}
	return 0;
}
