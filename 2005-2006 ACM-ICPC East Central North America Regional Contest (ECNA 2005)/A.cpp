#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;
set<string> st;

int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		st.clear();
		for(int i=1;i<=n;++i)
			cin>>s,st.insert(s);
		
	}
	return 0;
}
