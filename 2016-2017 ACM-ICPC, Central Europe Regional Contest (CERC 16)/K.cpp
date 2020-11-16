#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 3;
char s[maxn];
vector<int> p;
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1)+1;
	s[0]='0';
	for(int i=1;i<=n-2;i+=3) 
		if(s[i-1]=='0') {
			if(s[i]=='0'&&s[i+1]=='0'&&s[i+2]=='0') p.push_back(i); 
			else if(s[i]=='0'&&s[i+1]=='0'&&s[i+2]=='1') {
				p.push_back(i+1); s[i+2]='0';
			}
			else if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='1') p.push_back(i); 
			else if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='1') {
				p.push_back(i+1); s[i+2]='0';
			}
		}
		else {
			if(s[i]=='0'&&s[i+1]=='0'&&s[i+2]=='0') {p.push_back(i+1); s[i+2]='1';} 
			else if(s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='0') p.push_back(i);
			else if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0') {
				p.push_back(i+1); s[i+2]='1';
			}
			else if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='1') {
				p.push_back(i); //s[i+2]='0';
			}
		}
	printf("%d\n",p.size());
	for(int i=0;i<p.size();i++) printf("%d ",p[i]);
	
	return 0;
}
