#include <bits/stdc++.h>
using namespace std;

bool gao(int x)
{
	string s="";
	cout<<x<<' ';
	while(x)
	{
		s.append(1,(x%2)+'0');
		x/=2;
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
	int i=0,j;
	while(s[i]=='1'&&i<s.length()) i++;
	j=i;
	while(s[j]=='0'&&j<s.length()) j++;
	string one=s.substr(0,i+1),zero=s.substr(i,j-i);
	string tmp=one;
	bool flag=1;
	while(tmp.length()<=s.length())
	{
		if(tmp==s) return 1;
		if(flag) tmp+=zero;
		else tmp+=one;
		flag=1-flag;
	}
	return 0;
}

int main()
{
	for(int i=1;i<=100;++i)
	{
		if(gao(i)) printf("%d\n",i);
	}
	return 0;
}
