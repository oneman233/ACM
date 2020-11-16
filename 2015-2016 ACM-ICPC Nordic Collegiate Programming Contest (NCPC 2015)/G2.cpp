#include <bits/stdc++.h>
using namespace std;

#define db double
#define int long long
const long db EPS=1e-10;
inline int sign(db a){return a<-EPS?-1:a>EPS;}
inline int cmp(db a,db b){return sign(a-b);}

int n,m;
vector<int> del;
multiset<int> vy[20005];

signed main()
{
	scanf("%lld",&n);
	for(int i=0,x,y;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		vy[y].insert(x);
	}
	scanf("%lld",&m);
	for(int i=0,cx,cy,r;i<m;i++)
	{
		scanf("%lld%lld%lld",&cx,&cy,&r);
		int low=max(0ll,cy-r),high=min(10000ll,cy+r);
		for(int j=low;j<=high;j++)
		{
			if(vy[j].size()==0) continue;
			del.clear();
			int x;
			auto fst=vy[j].lower_bound(cx);
			while(1)
			{
				if(fst==vy[j].end()) fst--;
				x=(*fst);
				if((j-cy)*(j-cy)+(x-cx)*(x-cx)<=r*r) del.push_back(x);
				else break;
				if(fst==vy[j].begin()) break;
				fst--;
			}
			fst=vy[j].lower_bound(cx);
			while(1)
			{
				if(fst==vy[j].end()) break;
				x=(*fst);
				if((j-cy)*(j-cy)+(x-cx)*(x-cx)<=r*r) del.push_back(x);
				else break;
				fst++;
			}
			for(auto p:del) if(vy[j].find(p)!=vy[j].end()) vy[j].erase(p);
		}
	} 
	int ans=0;
	for(int i=0;i<=10000;i++) ans+=(int)vy[i].size();
	printf("%lld",ans);
	return 0;
}

/*
4
0 1
1 0
2 1
1 2
2
1 1 1
1 1 1

4
0 1
1 0
2 2
1 2
1
1 1 1
*/
