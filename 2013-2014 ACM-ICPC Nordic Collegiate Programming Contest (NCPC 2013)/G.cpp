#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string a,b;
string no="Deletion failed";
string yes="Deletion succeeded";

int main()
{
	cin>>n>>a>>b;
	if(n&1){
		for(int i=0;i<a.length();++i)
			if(a[i]==b[i]){
				cout<<no;
				return 0;
			}
		cout<<yes;
		return 0;
	}
	else{
		for(int i=0;i<a.length();++i)
			if(a[i]!=b[i]){
				cout<<no;
				return 0;
			}
		cout<<yes;
		return 0;
	}
	return 0;
}
