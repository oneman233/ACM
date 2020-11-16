#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 3;
char s[maxn];
int a[maxn];
set<int> st;
vector<int> p;
int main()
{
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	st.insert(0);
	st.insert(n+1);
	//n=strlen(s+1);
	for(int i=1;i<=n;i++) {
	//	a[i]=int(s[i]-'0');
		if(s[i]=='0') st.insert(i);
	}
	/*for(int i=1;i<=n;i++) 
		if(a[i]==2) p.push_back(i);
		else if(a[i]==0) st.insert(i);
	*/
	set<int>::iterator l,r,it;
	//int l,r;
	/*for(int i=0;i<p.size();i++) {
		if(a[p[i]]==1||a[p[i]]==2) a[p[i]]=1; 
		it=st.upper_bound(p[i]);
		//if((it)!=n+1) a[r]=1,
		r=*it;
		if(r>0&&r<=n) {
			a[r]=1; st.erase(r); 
		}
		it--;
		l=*it;
		//if(i==9) cout<<"Asd";
		if(l>0&&l<=n) {
			a[l]=1; st.erase(l);
		}
		//a[l+r-p[i]]=0;
		//st.insert(l+r-p[i]);
		/*if(a[l+r-p[i]]==1||a[l+r-p[i]]==2) {
			a[l+r-p[i]]=1; 
			st.insert(l+r-p[i]);
		}
		
		
		//st.erase(l); st.erase(r);
		
		a[l+r-p[i]]=0;
		st.insert(l+r-p[i]);
		//cout<<i<<endl;
	}
	*/
	for(int i=1;i<=n;i++) {
		if(s[i]!='2') continue;
		
		r=st.lower_bound(i);
		l=r; l--;
		int x=*l+*r-i;
		if((*r)<=n) st.erase(r); 
		//int x=*l+*r-i;
		//if(i==9) cout<<"Asd";
		if(*l>0) st.erase(l);
		st.insert(x);
	}
	for(int i=1;i<=n;i++) s[i]='1';
	for(it=st.begin();it!=st.end();it++) s[(*it)]='0';
	for(int i=1;i<=n;i++) printf("%c",s[i]);
	
	
	return 0;
}
