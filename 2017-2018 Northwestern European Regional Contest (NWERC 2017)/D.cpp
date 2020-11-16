#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
using namespace std;
typedef long long ll;

int n,m;
string s[25];
map<string,int> mp;
vector<string> yes[25],no[25];

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i) cin>>s[i],mp[s[i]]=i;
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		string a,b,c;
		cin>>a>>b>>c;
		if(c[0]=='c')
		{
			yes[mp[a]].push_back(b);
		}
		else if(c[0]=='i')
		{
			no[mp[a]].push_back(b);
		}
	}
	ll cor=1,all=1;
	for(int i=1;i<=n;++i)
	{
		all*=((ll)yes[mp[s[i]]].size()+no[mp[s[i]]].size());
		cor*=(ll)yes[mp[s[i]]].size();
	}
	if(all==1){
		bool ans=1;
		for(int i=1;i<=n;++i)
			if(yes[mp[s[i]]].size()==1) cout<<yes[mp[s[i]]][0]<<' ';
			else cout<<no[mp[s[i]]][0]<<' ',ans=0;
		cout<<endl;
		if(ans) cout<<"correct";
		else cout<<"incorrect";
		return 0;
	}
	cout<<cor<<" correct"<<endl;
	cout<<all-cor<<" incorrect";
	return 0;
}
/*
7
als mollen mollen mollen mollen mollen mollen
4
als when correct
mollen moles correct
mollen destroy correct
mollen mills incorrect

5
de zuigers zijn buiten werking
6
zijn are correct
banaan banana correct
de the correct
zuigers suckers incorrect
buiten out correct
werking working incorrect

3
a b c
3
a d incorrect
b e incorrect
c f incorrect

3
a b c
3
a d correct
b e correct
c f correct
*/
