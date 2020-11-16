#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a,b;
	string a1,a2;
	int k=0;
	int i=0;
	cin>>a;
	cin>>b;
	if(a.length()>b.length()+1)
	{
		cout<<"NO";
		return 0;
	}
	for(i=0;i<a.length();i++)
	{
		if(a[i]=='*')
		{
			a[i]=' ';
			break;
		}
	}
	if(i==(a.length()-1))
	{
		for(i=0;i<a.length()-1;i++)
		{
			if(a[i]!=b[i])
			{
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
		return 0;
	}
	stringstream aa;
	aa<<a;
	aa>>a1;
	aa>>a2;
	for(i=0;i<a1.length();i++)
	{
		if(a1[i]!=b[i])
		{
			cout<<"NO";
			return 0;
		}
	}
	k=(b.length()-1);
	for(i=(a2.length()-1);i>=0;i--)
	{
		if(a2[i]!=b[k])
		{
			cout<<"NO";
			return 0;
		}
		k--;
	}
	cout<<"YES";
	return 0;
}
