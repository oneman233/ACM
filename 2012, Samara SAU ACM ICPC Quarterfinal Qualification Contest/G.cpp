#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

string s;
map<char,int> mp,mp2;

int main()
{
	cin>>s;
	if(s.length()>26)
	{
		return cout<<"IMPOSSIBLE",0;
	}
	char c='a';
	for(int i=0;i<s.length();++i)
	{
		mp2[s[i]]=1;
	}
	for(int i=0;i<s.length();++i)
	{
		while(mp[c]||mp2[c]) ++c;
		if(mp[s[i]])
		{
			s[i]=c;
			mp[c]=1;
		}
		else mp[s[i]]=1;
	}
	cout<<s;
	return 0;
}
/*
aaaababa
*/
