#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> v;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s=="mumble"){
			v.push_back(-1);
			continue;
		}
		stringstream ss;
		int tmp;
		ss<<s;
		ss>>tmp;
		v.push_back(tmp);
	}
	bool all=1;
	for(auto i:v){
		if(i!=-1){
			all=0;
			break;
		}
	}
	if(all){
		cout<<"makes sense";
		return 0;
	}
//	if(v[0]==-1) v[0]=1;
	bool can=1;
	int pos;
	for(int i=0;i<n;++i){
		if(v[i]!=-1){
			pos=i;
			break;
		}
	}
	for(int i=0;i<pos;++i){
		if(v[i]==-1) continue;
		if(v[pos]-v[i]!=pos-i){
			can=0;
			break;
		}
	}
	for(int i=pos+1;i<n;++i){
		if(v[i]==-1) continue;
		if(v[i]-v[pos]!=i-pos){
			can=0;
			break;
		}
	}
	if(can) cout<<"makes sense";
	else cout<<"something is fishy";
	return 0;
}
