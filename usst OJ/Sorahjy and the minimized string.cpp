#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,pos;
	string s;
	char c=0;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]>c)
		{
			c=s[i];
			pos=i;
		}
		else if(s[i]<c)
			break;
		else;
	}
	for(int i=0;i<n;i++)
	{
		if(i==pos);
		else
			cout<<s[i];
	}
	return 0;
}
