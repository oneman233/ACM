#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,s;
	int yuan,fen;
	int num[105];
	int i;
	int change,max_change=-1;
	cin>>n>>s;
	s*=100;
	for(i=0;i<n;i++)
	{
		cin>>yuan>>fen;
		num[i]=yuan*100+fen;
	}
	for(i=0;i<n;i++)
	{
		if(s>=num[i])
			break;
	}
	if(i==n)
	{
		cout<<"-1";
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(s%num[i]==0)
			change=(s-num[i])%100;
		else
			change=(s-num[i])%100;
		if(change>max_change)
			max_change=change;
	}
	cout<<max_change;
	return 0;
}
