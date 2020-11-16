#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ll long long
#define pii pair<int,int>

tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> t;
struct node
{
	int op,t,val; 
};
vector<node> v;

inline bool cmp(node a,node b)
{
	if(a.t==b.t) return a.op<b.op;
	return a.t<b.t;
}

void gao(int Case)
{
	int op,a,b,c,q;
	t.clear();
	v.clear();
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d",&a,&b,&c);
			v.push_back({1,a,b});
			v.push_back({3,c,b});
		}
		else 
			scanf("%d%d",&a,&b),v.push_back({2,a,b});
	}
	sort(v.begin(),v.end(),cmp);
	printf("Case %d:\n",Case);
	for(auto p:v)
	{
		if(p.op==1) t.insert({p.val,p.t+1});
		else if(p.op==3) t.erase(t.lower_bound({p.val,0}));
		else if(p.op==2) 
		{
			a=t.find_by_order(p.val-1)->first;
			if(a==0) a--;
			printf("%d\n",a);
		}
	}
}

int main()
{
	int _;
	scanf("%d",&_);
	for(int __=1;__<=_;__++) gao(__);
	return 0;
}
