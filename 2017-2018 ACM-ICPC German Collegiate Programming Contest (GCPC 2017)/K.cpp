#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define re(i,a,b) for(int i=a;i<=b;++i)
#define pub push_back
using namespace std;
typedef long long ll;
const int N=10005;

int n,d,k;
struct node{
	string s;
	int c;
}p[N];
vector<string> v;

bool cmp(node a,node b){return a.c>b.c;}

int main()
{
	FAST
	cin>>n>>d>>k;
	re(i,1,n) cin>>p[i].s>>p[i].c;
	sort(p+1,p+1+n,cmp);
	int sum=0;
	re(i,1,k) sum+=p[i].c,v.pub(p[i].s);
	if(sum>=d){
		cout<<v.size()<<endl;
		for(auto i:v)
			cout<<i<<", YOU ARE FIRED!"<<endl;
	}
	else cout<<"impossible";
	return 0;
}
