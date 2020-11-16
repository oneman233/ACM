#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		bool f=0;
		cin>>s;
		for(int i=0;i<s.size()/2;++i){
			if(s[i]!=s[s.size()-i-1]){
				cout<<"NO"<<endl;
				f=1;
				break;
			}
		}
		if(!f) cout<<"YES"<<endl;
	}
	return 0;
}
