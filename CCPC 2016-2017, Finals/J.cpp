#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
using namespace std;
const int maxn = 23;
string str;
string s[8][maxn];
set<string> st;
int main()
{
	FAST
	int t,kase=0;
	cin>>t;
	while(t--)
	{
		
		st.clear();
		int n;
		cin>>n>>str;
		//scanf("%d%s",&n,tar);
		for(int i=1;i<=6;i++) for(int j=1;j<=20;j++) {
			cin>>s[i][j];
		}
		
		int a=0,b=0,flag=0;
		
		for(int j=1;j<=20;j++) {
			for(int i=1;i<=5;i++) 
			{	
				if(s[i][j]==str) {
					flag=1; break;
				}
				if(!st.count(s[i][j])){
					st.insert(s[i][j]);
					a++;
					if(a>=n) {
						flag=1; break;
					}
				}
			}	
			if(flag) break;
			//cout<<i<<endl;				
		}
		cout<<"Case #"<<++kase<<": ";
		if(a>=n) {
			cout<<"0\n"; continue;
		}
		
		flag=0;
		for(int i=1;i<=20;i++) {
				if(s[6][i]==str) break;
				if(!st.count(s[6][i])){
					st.insert(s[6][i]);
					b++;
					if(b>=n-a) break;
				}
				
		}
			
		if(b>=n-a)  cout<<n-a<<"\n";
		else cout<<"ADVANCED!\n";
	}
	return 0;
}
