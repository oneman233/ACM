#include <bits/stdc++.h>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define fo(i,a,b) for(int i=a;i<b;++i)
#define scd(a) scanf("%lf",&a)
#define scc(a) scanf("%c",&a)
#define scs(a) scanf("%s",a)
#define scii(a,b) scanf("%d%d",&a,&b)
#define sci(a) scanf("%d",&a)
#define scll(a,b) scanf("%lld%lld",&a,&b)
#define scl(a) scanf("%lld",&a)
#define prd(a) printf("%lf",a)
#define prc(a) printf("%c",a)
#define prs(a) printf("%s",a)
#define pri(a) printf("%d",a)
#define prl(a) printf("%lld",a)
#define prn() printf("\n")
#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()
#define rre(i,a,b) for(int i=a;i>=b;--i)
#define rfo(i,a,b) for(int i=a;i>b;--i)
#define endl "\n"
#define debug(a) cout<<a<<endl
using namespace std;
typedef unsigned long long ll;
const ll maxn=500005;
const ll inf=0x3f3f3f3f;
const double pi=3.1415926535;
const double esp=1e-10;
const int mod=10007;
template <typename t>
t mmax(t a,t b,t c){return max(a,max(b,c));}
template <typename t>
t mmin(t a,t b,t c){return min(a,min(b,c));}

int n;
ll x=0;
const ll big=(1LL<<32)-1;
bool can=true;

stack<string> p;
stack<int> q;
stack<int> m;

int main(){
	ios::sync_with_stdio(false);
	ll time=0;
	ll a;
	cin>>n;
	string str;
	int tem;
	int flag=0;
	ll ans=0;
	string pre;
	for(int i=1;i<=n;++i){
		cin>>str;
		if(str=="add") {
			if(flag == 1)continue;
			if(p.empty())ans++;
			else p.push(str);
		}
		else if(str=="for"){
			cin >> tem;
			if(flag == 1)continue;
			 p.push(str);
			 m.push(tem);
		}
		else {
			if(flag == 1)continue;
			pre = p.top();
			p.pop();
			while(pre!="for"){
				time ++;
				pre = p.top();
				p.pop();
			}
			if(pre == "for"){
				tem = m.top();
				m.pop();
				time *=tem ;
				if(time+ans>pow(2,32)-1)flag = 1;
			}
		}
		if(p.empty()){
			if(ans + time >pow(2,32)-1){
				flag = 1;
			}
			else ans+=time,time =0;
		}
	}
	if(flag == 1)cout <<"OVERFLOW!!!" << endl;
	else cout << ans;
	return 0;
}

