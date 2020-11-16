#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
using namespace std;
typedef long long ll;
const int N=205;

int n,m,ans;
string a,sb1,sb2,sb3,b;
map<string,int> mp;
int fa[N],all=1;
vector<int> e[N];

void gao(int x,int y,int who){
	if(x==y){
		ans=who;
		return;
	}
	for(auto to:e[x])
		gao(to,y,who);
}

int main()
{
	FAST
	cin>>n>>m;
	for(int i=1;i<=200;++i) fa[i]=i;
	for(int i=1;i<=n;++i){
		cin>>a>>sb1>>sb2>>sb3>>b;
//		cout<<a<<' '<<b<<endl;
		if(!mp[a]) mp[a]=all,all++;
		if(!mp[b]) mp[b]=all,all++;
		e[mp[a]].push_back(mp[b]);
	}
	for(int i=1;i<=m;++i){
		cin>>a>>sb1>>sb2>>sb3>>b;
		if(mp[a]==mp[b]){
			cout<<"Pants on Fire"<<endl;
			continue;
		}
		ans=-1;
		gao(mp[a],mp[b],1);
		gao(mp[b],mp[a],2);
		if(ans==-1) cout<<"Pants on Fire"<<endl;
		else if(ans==1) cout<<"Fact"<<endl;
		else cout<<"Alternative Fact"<<endl;
	}
	return 0;
}
/*
4 5
Mexicans are worse than Americans
Russians are worse than Mexicans
NorthKoreans are worse than Germans
Canadians are worse than Americans
Russians are worse than Americans
Germans are worse than NorthKoreans
NorthKoreans are worse than Mexicans
NorthKoreans are worse than French
Mexicans are worse than Canadians
*/
