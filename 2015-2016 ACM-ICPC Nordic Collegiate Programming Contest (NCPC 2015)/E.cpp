#include <bits/stdc++.h>
using namespace std;
const int N=100005;

typedef pair<int,int>pii;
bool ed[N];
int n,k;
multiset<int>q;
vector<pii>v;
bool cmp(pii l,pii r){
	return l.second==r.second? l.first<r.first: l.second<r.second;
}
inline multiset<int>::iterator lb(int x){
	return q.upper_bound(x);
}


int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		v.push_back({x,y});
	}
	sort(v.begin(),v.begin()+n,cmp);
	for(int i=0;i<k;++i) q.insert(0);
	int ans=0;
	for(int i=0;i<n;++i){
		int rnow=*q.begin();
//printf("q:"); for(auto t:q) printf(" %d",t);
		while(i<n && v[i].first<rnow) ++i;//	ed[i]=1;
		if(i>=n) break;
		int x=v[i].first, y=v[i].second;
		auto it=lb(x);
		if(it!=q.begin()) --it;
		else continue;
		++ans;
//printf("  %d: %d %d\n",*it,x,y);
		q.erase(it);
		q.insert(y);
	}
	printf("%d",ans);
	return 0;
}
/*
4 2

1 5
6 10

2 7
8 9

*/
/*
#include <bits/stdc++.h>
using namespace std;
const int N=100005;

typedef pair<int,int>pii;
bool ed[N];
int n,k;
//priority_queue<int,vector<int>,greater<int>>q;
multiset<int>q;
vector<pii>v;
bool cmp(pii l,pii r){
	return l.second==r.second? l.first<r.first: l.second<r.second;
}
inline multiset<int>::iterator lb(int x){
	return lower_bound(q.begin(),q.end(),x);
}
//int x[N],y[N];
//vector<int> v,pos[N];

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		v.push_back({x,y});
	}
	sort(v.begin(),v.begin()+n,cmp);
	for(int i=0;i<k;++i) q.insert(0);
	int ans=0;
	for(int i=0;i<n;++i){
		int rnow=*q.begin();
//printf("q:"); for(auto t:q) printf(" %d",t);
		while(i<n && v[i].first<rnow) ++i;//	ed[i]=1;
		if(i>=n) break;
		++ans;
		int x=v[i].first, y=v[i].second;
		auto it=lb(x);
		while(it==q.end()||*it>x)
			if(it!=q.begin()) --it;
			else break;
//printf("  %d: %d %d\n",*it,x,y);
		q.erase(it);
		q.insert(y);
	}
	printf("%d",ans);
//	for(int i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]),v.push_back(x[i]),v.push_back(y[i]);
//	sort(v.begin(),v.end());
//	for(int i=1;i<=n;++i)
//		x[i]=lower_bound(v.begin(),v.end(),x[i]),
//		y[i]=lower_bound(v.begin(),v.end(),y[i]);
	
	return 0;
}
*/
