#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;

int n;
string s;
int dp[20][40000];
vector<string> v[20];
int ans=0;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s;
		for(int j=1;j<(1<<s.length());++j){
			string t="";
			for(int k=0;k<s.length();++k)
				if(j&(1<<k)) t+=s[k];
			v[i].push_back(t);
		}
	}
	for(int i=1;i<=n;++i) sort(v[i].begin(),v[i].end());
	memset(dp,0xc0,sizeof(dp));
	for(int i=0;i<v[1].size();i++) dp[1][i]=v[1][i].size();
	for(int i=2;i<=n;++i){
		int l=0,pre=dp[i-1][0];
		for(int j=0;j<v[i].size();j++){
			while(l+1<v[i-1].size()&&v[i-1][l+1]<v[i][j]) l++,pre=max(pre,dp[i-1][l]);
			if(v[i][j]>v[i-1][l]) dp[i][j]=pre+v[i][j].size();
		}
	}
	for(int i=0;i<v[n].size();i++) ans=max(ans,dp[n][i]);
	if(ans>0) cout<<ans;
	else cout<<-1;
	return 0;
}
