#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N=200005;

int n;
struct point{
	int x,y;
	point(int xx=0,int yy=0):x(xx),y(yy){}
	point operator - (point p){return point(x-p.x,y-p.y);}
}p[N];

int cross(point a,point b){return a.x*b.y-a.y*b.x;}
int area(point a,point b,point c){return cross(b-a,c-a);}
int cal(point a,point b){
	return __gcd(abs(a.x-b.x),abs(a.y-b.y));
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld",&p[i].x,&p[i].y);
	int s=0;
	for(int i=3;i<=n;++i)
		s+=area(p[1],p[i-1],p[i]);//it's a fomula
	s=abs(s);
	int b=cal(p[1],p[n]);
	for(int i=2;i<=n;++i)
		b+=cal(p[i],p[i-1]);
	printf("%lld",(s-b)/2+1);
	return 0;
}
/*
4
0 0
0 10
10 10
10 0
*/
