#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int main()
{
	int n;
	int easy=0,hard=0;
	cin>>n;
	string s[105];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i][0]=='E'||s[i][0]=='e')
			easy++;
		else
			hard++;
	}
	if(easy==n)
		cout<<"easy";
	else
		cout<<"hard";
	return 0;
}
