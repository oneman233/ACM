#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

double PI=acos(-1);
double dega,degb,la,lb;
char s[10];

int get(double deg,double l)
{
	double x,y;
	y=l*sin(deg/180*PI)/sin(PI/3);
	x=l*cos(deg/180*PI)-l*sin(deg/180*PI)/sqrt(3);
	//printf("!!! %.10f %.10f\n",x,y);
	while(x<0) x+=2;
	while(x>=2) x-=2;
	while(y<0) y+=2;
	while(y>=2) y-=2;
	int tx=int(x),ty=int(y);
	int flag=x+y-tx-ty;
	//printf("%.10f %.10f %d %d\n",x,y,tx,ty);
	if(flag==0)
	{
		if(tx==0&&ty==0) return 1;
		if(tx==1&&ty==1) return 0;
		if(tx==0&&ty==1) return 2;
		if(tx==1&&ty==0) return 3;
	}
	else
	{
		if(tx==0&&ty==0) return 0;
		if(tx==1&&ty==1) return 1;
		if(tx==0&&ty==1) return 3;
		if(tx==1&&ty==0) return 2;
	}
	return -1;
}

int main()
{
	scanf("%s%lf%lf",s,&dega,&la);
	if(s[0]=='C') dega+=60;
	else if(s[0]=='D') dega-=60;
	scanf("%s%lf%lf",s,&degb,&lb);
	if(s[0]=='C') degb+=60;
	else if(s[0]=='D') degb-=60;
	//printf("%d %d\n",get(dega,la),get(degb,lb));
	if(get(dega,la)==get(degb,lb)) printf("YES"); else printf("NO");
	return 0;
}
