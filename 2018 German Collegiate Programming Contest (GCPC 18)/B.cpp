#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const db eps=1e-10;
const db pi=3.14159265358979;

bool eql(db a,db b){return fabs(a-b)<eps;}
db len(db a,db b,db c,db d){return sqrt((a-c)*(a-c)+(b-d)*(b-d));}
db dot(db a,db b,db c,db d){return a*c+b*d;}

db xc,yc,xd,yd,xb,yb,rb,xr,yr,rr;

int main()
{
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&xc,&yc,&xd,&yd,&xb,&yb,&rb,&xr,&yr,&rr);
	db ans=sqrt(len(xc,yc,xr,yr)*len(xc,yc,xr,yr)-rr*rr)+sqrt(len(xd,yd,xr,yr)*len(xd,yd,xr,yr)-rr*rr);
	db alpha=acos(rr/len(xc,yc,xr,yr));
	db belta=acos(rr/len(xd,yd,xr,yr));
	db all=acos(dot(xc-xr,yc-yr,xd-xr,yd-yr)/(len(xc,yc,xr,yr)*len(xd,yd,xr,yr)));
	db in=all-alpha-belta;
	ans+=rr*min(in,2*pi-in);
	printf("%.10lf",ans);
	return 0;
}
/*
0 0
10 0
0 0 1000
5 0 2
*/
