#include <bits/stdc++.h>
using namespace std;
const double eps=1e-10;

int n,k;
double l[10005];

bool chk()
{

}

bool eql(double a,double b)
{
    if(fabs(a-b)>eps)
        return false;
    return true;
}

int main()
{
    cin>>n>>k;
    double bg=0.0;
    for(int i=1;i<=n;++i)
        cin>>l[i],bg=max(bg,l[i]);
    double l=1.0,r=bg;
    while(l<r||eql(l,r)){
        double m=(l+r)/2.0;
        if(chk(m)) l=m;
        else r=m;
    }
    return 0;
}
