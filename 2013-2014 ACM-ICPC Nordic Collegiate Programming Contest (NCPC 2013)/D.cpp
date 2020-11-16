#include <bits/stdc++.h>
using namespace std;

const double eps=1e-8;
const double pi=acos(-1.0);

inline int cmp(double x)
{
	if(fabs(x)<eps) return 0;
	if(x>0) return 1;
	return -1;
}

struct point
{
	double x,y;
	point(){}
	point(double a,double b):x(a),y(b){}
	friend point operator - (const point &a,const point &b){return point(a.x-b.x,a.y-b.y);}	
	friend bool operator == (const point &a,const point &b){return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;}	
};
int n;
vector<point> v;

struct polygon_convex
{
	vector<point> P;
	polygon_convex(int Size=0)
	{
		P.resize(Size);
	}
};

double det(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}

double dot(point a,point b)
{
	return a.x*b.x+a.y*b.y;
}

bool cmp_less(point a,point b)
{
	return cmp(a.x-b.x)<0||cmp(a.x-b.x)==0&&cmp(a.y-b.y)<0;
}

polygon_convex convex_hull(vector<point> a)
{
	polygon_convex res(2*a.size()+5);
	sort(a.begin(),a.end(),cmp_less);
	a.erase(unique(a.begin(),a.end()),a.end());
	int m=0;
	for(int i=0;i<a.size();i++)
	{
		while(m>1&&cmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0) m--;
		res.P[m++]=a[i];
	}
	int k=m;
	for(int i=int(a.size())-2;i>=0;i--)
	{
		while(m>k&&cmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0) m--;
		res.P[m++]=a[i];
	}
	res.P.resize(m);
	if(a.size()>1) res.P.resize(m-1);
	return res;
}

double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double convex_diameter(polygon_convex &a)
{
	vector<point> &p=a.P;
	int n=p.size();
	double maxd=0;
	if(n==1) return maxd;
	#define next(i) ((i+1)%n)
	for(int i=0,j=1;i<n;i++)
	{
		while(cmp(det(p[next(i)]-p[i],p[j]-p[i])-det(p[next(i)]-p[i],p[next(j)]-p[i]))<0) j=next(j);
		double d=dist(p[i],p[j]);
		if(d>maxd) maxd=d;
		d=dist(p[next(i)],p[next(j)]);
		if(d>maxd) maxd=d;
	}
	return maxd;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		v.emplace_back(x,y);
	}
	polygon_convex hull=convex_hull(v);
	printf("%.10f",convex_diameter(hull));
	return 0;
}
