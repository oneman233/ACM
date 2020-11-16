#include <bits/stdc++.h>
using namespace std;

int main()
{
    double h,k,r;
    cin>>h>>k>>r;
    if(k>=h)
        printf("%.3lf",r);
    else
        printf("%.3lf",sqrt((h-k)*(h-k)+r*r));
    return 0;
}
