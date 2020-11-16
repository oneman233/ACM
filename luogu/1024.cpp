#include <bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;

const double pre=0.000001;
double a,b,c,d;
vector<double> ans;

double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}

void halve(double l,double r)
{
    if(fabs(l-r)<pre||l>r)
        return;
    double mid=(l+r)/2.0;
    cout<<l<<" "<<mid<<" "<<r<<endl;
    if(f(mid)==0.0)
    {
        ans.pb(mid);
        return;
    }
    /*
    if(f(l)==0.0)
    {
        ans.pb(l);
        return;
    }
    if(f(r)==0.0)
    {
        ans.pb(r);
        return;
    }
    */
    halve(l,mid);
    halve(mid,r);
}

int main()
{
    cin>>a>>b>>c>>d;
    ///halve(-100.0,100.0);
    for(double i=-100.0;i<=100.0;i+=0.0001)
    {
        if(fabs(f(i)-0.0)<pre)
            ans.pb(i);
        if(ans.size()==3)
            break;
    }
    printf("%.2lf %.2lf %.2lf",ans[0],ans[1],ans[2]);
    return 0;
}
