#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

#define l first
#define r second 
int n,m,ans;
set<pii> s;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		s.emplace(x,x+y);
	}
	set<pii>::iterator nowp,newp;
	while(s.size())
	{
		nowp=s.begin();
		while(1)
		{
			newp=s.lower_bound({(*nowp).r,-1});
			if(newp==s.end()) break;
			if((*newp).l>(*nowp).r+m) break;
			s.erase(nowp);nowp=newp;ans++;
		}
		s.erase(nowp);
	}
	printf("%d",ans);
	return 0;
}
