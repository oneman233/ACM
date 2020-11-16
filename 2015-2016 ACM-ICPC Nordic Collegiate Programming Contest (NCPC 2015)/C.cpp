#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	cin>>s;
	int ans=0;
	for(int i=0;i<s.length();++i){
		if(s[i]!='P'&&s[i]!='p') ans++;
		i++;
		if(s[i]!='e'&&s[i]!='E') ans++;
		i++;
		if(s[i]!='r'&&s[i]!='R') ans++;
	}
	cout<<ans;
	return 0;
}
