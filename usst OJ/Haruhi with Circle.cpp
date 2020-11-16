#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<b;++i)
using namespace std;
typedef long long ll;
const double pi=3.1415926535;
const double esp=1e-8;

int main()
{
    double n,R,r;
    cin>>n>>R>>r;
    if(r>R)
    {
        cout<<"NO";
        return 0;
    }
    if(r>R/2.0)
    {
        if(n==1)
            cout<<"YES";
        else
            cout<<"NO";
    }
    /*
    else if(fabs(r-R/2.0)<esp)
    {
        if(n<=2)
            cout<<"YES";
        else
            cout<<"NO";
    }
    */
    else
    {
        double alpha=asin(r/(R-r));
        ///cout<<fabs(n-(pi/alpha))<<endl;
        if(n<(pi/alpha)||fabs(n-(pi/alpha))<esp)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
