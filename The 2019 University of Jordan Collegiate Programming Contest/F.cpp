#include <bits/stdc++.h>
using namespace std;

const double eps=1e-9;
const double PI=acos(-1);
struct point
{
	double x;
	double y;
	point(double x,double y):x(x),y(y){}
	point(){}
};
struct person
{
	point pos;
	double a1,a2;
}p[3005];
int n,deg[3005];
vector<int> e[3005],ans;

inline int cmp(double x)
{
	if(fabs(x)<eps) return 0;
	if(x>0) return 1;
	return -1;
}

inline double det(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}

inline double dot(point a,point b)
{
	return a.x*b.x+a.y*b.y;	
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		double r1,r2;
		scanf("%lf%lf%lf%lf",&p[i].pos.x,&p[i].pos.y,&r1,&r2);
		r1=r1/180*PI,r2=r2/180*PI;
		p[i].a1=r1-r2;
		p[i].a2=r1+r2;
	}
	for(int i=0;i<n;i++)
	{
		point v1=point(cos(p[i].a1),sin(p[i].a1));
		point v2=point(cos(p[i].a2),sin(p[i].a2));
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			point vv=point(p[j].pos.x-p[i].pos.x,p[j].pos.y-p[i].pos.y);
			if(cmp(det(v1,vv))==1||cmp(det(v1,vv))==0&&cmp(dot(v1,vv))==1)
			if(cmp(det(vv,v2))==1||cmp(det(vv,v2))==0&&cmp(dot(v2,vv))==1)
				e[i].push_back(j),deg[j]++;
		}
	}
	queue<int> q;
	for(int i=0;i<n;i++) if(!deg[i]) q.push(i);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		ans.push_back(now);
		for(auto to:e[now])
		{
			deg[to]--;
			if(!deg[to]) q.push(to);
		}
	}
	if(ans.size()==n) 
		for(auto a:ans) printf("%d ",a+1);
	else printf("-1");
	return 0;
}
/*
2
0 0 45 45
1 0 180 0

2 
0 0 0 0
1 0 180 0

2
0 0 0 0
-1 0 0 0

2
0 0 0 0
-1 0 180 0

3
0 0 0 0
1 0 90 0
1 1 224 0
*/
