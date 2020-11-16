#include <bits/stdc++.h>
using namespace std;
#define double long double
const double eps=1e-15;
const double pi=acos(-1);
double delta,r1,r2,r3,r4,r5,r6;

inline double f(double r)
{
	double ret;
	ret=r/delta/2/delta/pi;
	ret*=exp(-r*r/2/delta/delta);
	return ret;
}

/*double simpson(double L, double R)
{
    double mid = (L + R) / 2.0;
    return (f(L) + 4.0 * f(mid) + f(R)) * (R - L) / 6.0;
}

double g(double L, double R, double Eps=1e-10)
{
    double mid = (L + R) / 2;
    double ST = simpson(L, R);
	double SL = simpson(L, mid);
	double SR = simpson(mid, R);
    if(fabs(SL+SR-ST) <= 15 * Eps)  return SL+SR+(SL + SR - ST)/15;
    return g(L, mid, Eps/2) + g(mid, R, Eps/2);
}*/

/*
inline double simpson(double l,double r)
{
    double mid=(l+r)/2;
    return (f(l)+4*f(mid)+f(r))*(r-l)/6;
}

inline double g(double l,double r,double ans)
{
    double mid=(l+r)/2;
    double l1=simpson(l,mid),r1=simpson(mid,r);
    if(fabs(l1+r1-ans)<eps)return l1+r1;
    return g(l,mid,l1)+g(mid,r,r1);
}
*/

double g(double a,double b,int n=10000000)
{
	const double h=(b-a)/n;
	double ans=f(a)+f(b);
	for(int i=1;i<n;i+=2) ans+=4*f(a+i*h);
	for(int i=1;i<n;i+=2) ans+=2*f(a+i*h);
	return ans*h/3;
}

double ggg(double a,double b,double eps=1e-10)
{
	vector<double> t;
	double h=b-a,last,curr;
	int k=1,i=1;
	t.push_back(h*(f(a)+f(b))/2);
	do
	{
		last=t.back();
		curr=0;
		double x=a+h/2;
		for(int j=0;j<k;j++)
		{
			curr+=f(x);
			x+=h;
		}
		curr=(t[0]+h*curr)/2;
		double k1=4.0/3.0,k2=1.0/3.0;
		for(int j=0;j<i;j++)
		{
			double temp=k1*curr-k2*t[j];
			t[j]=curr;
			curr=temp;
			k2/=4*k1-k2;
			k1=k2+1;
		}
		t.push_back(curr);
		k*=2,h/=2,i++; 
	}while(fabs(last-curr)>eps);
	return t.back();
}


int main()
{
	scanf("%Lf%Lf%Lf%Lf%Lf%Lf",&r1,&r2,&r3,&r4,&r5,&r6);
	scanf("%Lf",&delta);
	double ans=0;
	/*ans+=g(0,r1,simpson(0,r1))*50;
	ans+=g(r1,r2,simpson(r1,r2))*25;
	ans+=g(r2,r3,simpson(r2,r3))*10.5;
	ans+=g(r3,r4,simpson(r3,r4))*31.5;
	ans+=g(r4,r5,simpson(r4,r5))*10.5;
	ans+=g(r5,r6,simpson(r5,r6))*21;*/ 
	ans+=g(0,r1)*50;
	ans+=g(r1,r2)*25;
	ans+=g(r2,r3)*10.5;
	ans+=g(r3,r4)*31.5;
	ans+=g(r4,r5)*10.5;
	ans+=g(r5,r6)*21;
	printf("%.16Lf",ans*2*pi);
	return 0;
}
