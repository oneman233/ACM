#include <bits/stdc++.h>
#define debug(a) cout<<a<<endl
using namespace std;
const double pi=3.1415926535;
const double eps=1e-10;

double r,R;
struct point
{
    double x,y;
}rr,RR;

double s(double a,double b,double c)
{
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

double len(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool bigeql(double a,double b)
{
    if(a>b||fabs(a-b)<=eps)
        return true;
    return false;
}

bool smleql(double a,double b)
{
    if(a<b||fabs(a-b)<=eps)
        return true;
    return false;
}

double sr()
{
    return r*r*pi;
}

double sR()
{
    return R*R*pi;
}

void solve()
{
    double l=len(rr,RR);
    if(bigeql(l,r+R))
        printf("0.0000\n");
    else if(bigeql(R,l+r)){
        printf("1.0000\n");
    }
    else if(bigeql(r,l+R)){
        printf("%.4lf\n",sR()/sr());
    }
    else{
        double ra,Ra;
        ra=acos((r*r+l*l-R*R)/(2.0*r*l));
        Ra=acos((R*R+l*l-r*r)/(2.0*R*l));
        double ar,aR,atri;
        ar=ra*r*r;
        aR=Ra*R*R;
        atri=2.0*s(r,R,l);
        printf("%.4lf\n",(ar+aR-atri)/sr());
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>rr.x>>rr.y>>r>>RR.x>>RR.y>>R;
        solve();
    }
    return 0;
}
